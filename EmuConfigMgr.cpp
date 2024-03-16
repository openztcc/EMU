#include "EmuConfigMgr.h"

void EmuConfigMgr::LoadSceneryConfig(std::string filename) {
    // Load the configuration file
    CSimpleIniA ini;
    ini.SetUnicode();
    ini.LoadFile(filename.c_str());

    const char* pVal = ini.GetValue("Configuration/Integers", "EmuConfigMgr", "EmuConfigMgr");
}