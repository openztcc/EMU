#include "ZUtilities.h"

ZUtilities::ZUtilities()
{

}

ZUtilities::~ZUtilities()
{

}

/// @brief Sets the IAT hook for a given function
/// @param funcName The name of the function to hook
/// @param newFunc The new function to replace the old one
/// @return The original function address
DWORD ZUtilities::SetIAT(const char* funcName, DWORD newFunc)
{

     // -- Check if PE header is valid

    // ----- Get the DOS header
    IMAGE_DOS_HEADER* dosHeader = (IMAGE_DOS_HEADER*)EmuBase::base;
    if (dosHeader->e_magic != IMAGE_DOS_SIGNATURE)
    {
        return 0;
    }

    // ----- Get the Optional header (if it exists)
    IMAGE_OPTIONAL_HEADER* optionalHeader = (IMAGE_OPTIONAL_HEADER*)(EmuBase::base + dosHeader->e_lfanew + 24);
    if (optionalHeader->Magic != IMAGE_NT_OPTIONAL_HDR32_MAGIC)
    {
        return 0;
    }
    
    // -- Check if PE header exists

    IMAGE_DATA_DIRECTORY IAT = optionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];
    if (IAT.Size == 0 || IAT.VirtualAddress == 0)
    {
        return 0;
    }

    // --- Get the import descriptor
    IMAGE_IMPORT_DESCRIPTOR* impDesc = (IMAGE_IMPORT_DESCRIPTOR*)(EmuBase::base + IAT.VirtualAddress);

    // --- Loop through the import descriptor to find the function
    while (impDesc->FirstThunk)
    {
        // ----- Get thunk data
        IMAGE_THUNK_DATA* thunkData = (IMAGE_THUNK_DATA*)(EmuBase::base + impDesc->FirstThunk);

        // ----- Set index
        int n = 0;
        while (thunkData->u1.Function)
        {
            // ----- Place IAT hook
            char* getFuncName = (char*)((DWORD)thunkData->u1.Function + EmuBase::base + 2);
            if (strcmp(getFuncName, funcName) == 0)
            {
                DWORD* vfTable = (DWORD*)(EmuBase::base + impDesc->FirstThunk);
                DWORD og = vfTable[n];
                vfTable[n] = newFunc;

                return og;
            }
            n++;
            thunkData++;
        }
    }
}