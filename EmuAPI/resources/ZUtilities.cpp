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

    std::ofstream f;
	f.open("out.log", std::ios_base::app);
	std::time_t t = std::time(0);
	char timestamp[80]; // timestamp buffer
	std::strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", std::localtime(&t));



     // -- Check if PE header is valid

    // ----- Get the DOS header
    IMAGE_DOS_HEADER* dosHeader = (IMAGE_DOS_HEADER*)EmuBase::base;
    if (dosHeader->e_magic != IMAGE_DOS_SIGNATURE)
    {
        f << "[" << timestamp << "] " << "IAT hook failed!" << std::endl;
        return 0;
    }

    f << "[" << timestamp << "] " << "DOS Header is valid!" << std::endl;

    // ----- Get the Optional header (if it exists)
    IMAGE_OPTIONAL_HEADER* optionalHeader = (IMAGE_OPTIONAL_HEADER*)(EmuBase::base + dosHeader->e_lfanew + 24);
    if (optionalHeader->Magic != IMAGE_NT_OPTIONAL_HDR32_MAGIC)
    {
        f << "[" << timestamp << "] " << "IAT hook failed!" << std::endl;
        return 0;
    }
    
    f << "[" << timestamp << "] " << "Optional header is valid!" << std::endl;

    // -- Check if PE header exists

    IMAGE_DATA_DIRECTORY IAT = optionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];
    if (IAT.Size == 0 || IAT.VirtualAddress == 0)
    {
        f << "[" << timestamp << "] " << "IAT hook failed!" << std::endl;
        return 0;
    }

    f << "[" << timestamp << "] " << "Import Address Table exists!" << std::endl;

    // --- Get the import descriptor
    IMAGE_IMPORT_DESCRIPTOR* impDesc = (IMAGE_IMPORT_DESCRIPTOR*)(EmuBase::base + IAT.VirtualAddress);

    // --- Loop through the import descriptor to find the function
    while (impDesc->FirstThunk)
    {
        // ----- Get thunk data
        IMAGE_THUNK_DATA* thunkData = (IMAGE_THUNK_DATA*)(EmuBase::base + impDesc->OriginalFirstThunk);

        // ----- Set index
        int n = 0;
        while (thunkData->u1.Function)
        {
            // ----- Place IAT hook
            char* getFuncName = (char*)(EmuBase::base + (DWORD)thunkData->u1.AddressOfData + 2);
            f << "[" << timestamp << "] " << "Checking function: " << getFuncName << std::endl;
            if (strcmp(getFuncName, funcName) == 0)
            {
                f << "[" << timestamp << "] " << "Found function: " << funcName << std::endl;
                DWORD* vfTable = (DWORD*)(EmuBase::base + impDesc->FirstThunk);
                DWORD og = vfTable[n];
                
                DWORD ogProt = EmuBase::Memory<DWORD>::protectMemory(&vfTable[n], PAGE_READWRITE);
                vfTable[n] = newFunc;
                EmuBase::Memory<DWORD>::protectMemory(&vfTable[n], ogProt);


                f << "[" << timestamp << "] " << "IAT hook success!" << std::endl;


                return og;
            }
            n++;
            thunkData++;
        }
    }

    f.close();

}