#include "ZUtilities.h"

ZUtilities::ZUtilities()
{

}

ZUtilities::~ZUtilities()
{

}

int ZUtilities::FoundIAT()
{
    // -- Check if PE header is valid

    // ----- Get the DOS header
    IMAGE_DOS_HEADER dosHeader = *(IMAGE_DOS_HEADER*)EmuBase::base;
    if (dosHeader.e_magic != IMAGE_DOS_SIGNATURE)
    {
        return 0;
    }

    // ----- Get the Optional header (if it exists)
    IMAGE_OPTIONAL_HEADER optionalHeader = *(IMAGE_OPTIONAL_HEADER*)(EmuBase::base + dosHeader.e_lfanew + 24);
    if (optionalHeader.Magic != IMAGE_NT_OPTIONAL_HDR32_MAGIC)
    {
        return 2;
    }
    
    // -- Check if PE header exists

    IMAGE_DATA_DIRECTORY IAT = optionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];
    if (IAT.Size == 0 || IAT.VirtualAddress == 0)
    {
        return 3;
    }
    
    return 1;
}