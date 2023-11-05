#include "EmuScriptMgr.h"

// EmuScriptMgr::EmuScriptMgr() {

// }

EmuScriptMgr::EmuScriptMgr(lua_State* lua, std::ofstream& fs) : lua(lua), f(fs) {

    //------ Timestamp for logging
    *t = std::time(0);
	timestamp = new char[80]; // timestamp buffer
    std::strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", std::localtime(t));
}

EmuScriptMgr::~EmuScriptMgr() {
}

/// @brief Executes all emu scripts in a directory.
int EmuScriptMgr::executeScripts() {
    std::string function_name;
    try {
        for (size_t i = 0; i < files.size() - 1; i++) {
            // lua_CFunction script_fun = script_functions[i];
            //script_fun(lua);
            std::stringstream ss;
            ss << "emu_run";// << i + 1;
            function_name = ss.str();
            lua_getglobal(lua, function_name.c_str()); // call emu_run from script
            if (lua_isfunction(lua, -1)) {
                int pcall = lua_pcall(lua, 0, 0, 0);
                if (pcall != 0) {
                    const char* error_message = lua_tostring(lua, -1);
                    if(error_message != NULL) {
                        f << "[" << timestamp << "] " << "Lua pcall error: <" << function_name << "> " << error_message << std::endl;
                    } else {
                        f << "[" << timestamp << "] " << "Lua pcall error: <" << function_name << "> err unavailable" << std::endl;
                    }
                    
                    lua_pop(lua, 1);
                }
                lua_pop(lua, 1);
            }
            else {
                lua_pop(lua, 1);
                f << "[" << timestamp << "] " << "Error while finding function: <" << function_name << "> null function" << std::endl;
                return 2;
            }
        }
    }
    catch (const std::bad_alloc& e) {
        f << "[" << timestamp << "] " << "Error while executing function: <" << function_name << "> " << e.what() << std::endl;
    }
    return 0;
}

/// @brief Serializes all emu scripts in a directory as a binary format.
void EmuScriptMgr::serializeScripts() {
    int err = 0;

    //------ Load scripts
    for (int i = 0; i < files.size(); i++) {
        std::string file = files[i];
        std::string file_name = file_names[i];

        //------ Load script into Lua state (if no errors
        if ((err = luaL_loadfile(lua, file.c_str())) == 0) {
            lua_pcall(lua, 0, LUA_MULTRET, 0);
            f << "[" << timestamp << "] " << "Loading script: " << file_name << std::endl;
        }
        else
        {
            const char* error_message = lua_tostring(lua, -1);
            if (error_message != NULL)
            {
                f << "[" << timestamp << "] " << "Error loading script: <" << file_name << "> " << error_message << std::endl;
            }
            else
            {
                f << "[" << timestamp << "] " << "Error loading script: <" << file_name << std::endl;
            }
            
        }
    }
}

/// @brief Finds all scripts within the /scripts directory and stores their location in memory.
void EmuScriptMgr::findScripts() {

    //------ Open log file in append mode
    std::ofstream f;
	f.open("out.log", std::ios_base::app);

    //------ Get working directory
    wchar_t buffer[MAX_PATH]; // wide char buffer for GetCurrentDirectory
	DWORD len = GetCurrentDirectory(MAX_PATH, buffer); // TODO: add error handling for this
	std::wstring wpath(buffer, len);//std::wstring(buffer.begin(), buffer.end()); // conv path to wide string (project uses multi-byte char set)
	wpath += L"\\scripts";

    //------ Convert wide string to narrow string, 
	std::string path(wpath.begin(), wpath.end());

    //------ Store all file directories into vector
    std::vector<std::string> files;

    //------ Find first .emu file in directory
	WIN32_FIND_DATA find_emu_file;
	HANDLE hFind = FindFirstFile((wpath + L"\\*.emu").c_str(), &find_emu_file); // wide string used here

	wpath = find_emu_file.cFileName;
	std::string file_found(wpath.begin(), wpath.end());
	
    //------ If no .emu files found, log error
	if  (hFind == INVALID_HANDLE_VALUE) {
		f << "[" << timestamp << "] " << "Error finding path: " << file_found << std::endl;
	} else {
		//------ Find the rest of the .emu files in the directory
		do {
			if (find_emu_file.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
				// skip directories (for now)
			} else { // we only care about files (for now) 
				std::wstring nFound = find_emu_file.cFileName; // conv file found back to narrow string
				std::string file_name(nFound.begin(), nFound.end());
				std::string file = path + "\\" + file_name;
				
				files.push_back(file);
                file_names.push_back(file_name);
			}
		} while (FindNextFile(hFind, &find_emu_file) != 0); // find the next file
		FindClose(hFind); 
    }

}

