#include "EmuScriptMgr.h"

// EmuScriptMgr::EmuScriptMgr() : lua(NULL), f(std::ofstream("out.log", std::ios_base::app)), timestamp(*new char) {
//     // do not use default constructor
// }

EmuScriptMgr::EmuScriptMgr() {

    //------ Initializing Lua
	lua = luaL_newstate();  // Open Lua
	int iErr = 0;
	// if (!lua) {
	// 	f << "[" << timestamp << "] " << "Failed to create Lua state." << std::endl;
	// }

	//------ Register API functions to Lua
	RegZooState::register_zoo_state(lua);

	//------ Load Lua libraries
	luaL_openlibs (lua);
}

EmuScriptMgr::~EmuScriptMgr() {
    lua_close (lua);
}

/// @brief Executes all emu scripts in a directory.
ZooModels EmuScriptMgr::executeScripts() {
    ZooModels zoo_models;

    for (size_t i = 0; i < scripts.size(); i++) {
        lua = luaL_newstate();  // Open Lua
    
        int iErr = 0;
        if (!lua) {
            // f << "[" << timestamp << "] " << "Failed to create Lua state." << std::endl;
        }
        //------ Register API functions to Lua
        RegZooState::register_zoo_state(lua);
        luaL_openlibs (lua);
        if (luaL_loadstring(lua, scripts[i].c_str()) == 0) {
            if (lua_pcall(lua, 0, LUA_MULTRET, 0) == 0)
            {
                // script is loaded, now load specific function
                lua_getglobal(lua, "emu_run");
                // check if we can call function
                if (lua_isfunction(lua, -1)) {
                    if (lua_pcall(lua, 0, LUA_MULTRET, 0) == 0) {
                        // // errors if can't execute script
                        // const char* error_message = lua_tostring(lua, -1);
                        // f << "Error executing Lua function: " << error_message << std::endl;
                        // lua_close (lua);
                        // // return 1;
                        lua_getglobal(lua, "_globalAnimalRating");
                        if (lua_isnumber(lua, -1)) {
                            int animalRating = (int)lua_tointeger(lua, -1);
                            zoo_models._animalRating = animalRating;
                        }
                        lua_getglobal(lua, "_globalGuestRating");
                        if (lua_isnumber(lua, -1)) {
                            int guestRating = (int)lua_tointeger(lua, -1);
                            zoo_models._guestRating = guestRating;
                        }
                        lua_getglobal(lua, "_globalZooRating");
                        if (lua_isnumber(lua, -1)) {
                            int zooRating = (int)lua_tointeger(lua, -1);
                            zoo_models._zooRating = zooRating;
                        }
                        lua_pop(lua, 1);
                    }
                } else {
                    // f << "[" << timestamp << "] " << "Function 'emu_run' not found or not callable" << std::endl;
                    lua_close (lua);
                    // return 1;
                }
                lua_pop(lua, 1);
            } else {
                // error handling
                const char* error_message = lua_tostring(lua, -1);
                // f << "[" << timestamp << "] " << "Error executing Lua script " << i << ": " << error_message << std::endl;

                // remove err from stack
                lua_pop(lua, 1);
                lua_close (lua);
                // return 1;
            }
        } else {
            // error handling
            const char* error_message = lua_tostring(lua, -1);
            // f << "[" << timestamp << "] " << "Error loading Lua script " << i << ": " << error_message << std::endl;

            // remove err from stack
            lua_pop(lua, 1);
            lua_close (lua);
            // return 1;
        }
        lua_close (lua);
    }
    
    // return 0;
    return zoo_models;
}

/// @brief Stores all emu scripts in a directory in memory.
void EmuScriptMgr::storeScripts() {

    for (size_t i = 0; i < files.size(); i++) {
        //------ Read script file
        std::ifstream file(files[i].c_str());
        std::string script;
        char c;
        while (file.get(c)) {
            script += c;
        }
        scripts.push_back(script);
        file.close();
        //------ Compile script
        if ((luaL_loadstring(lua, script.c_str())) == 0) {
            lua_CFunction script_funct = lua_tocfunction(lua, -1);
            compiled_scripts.push_back(script_funct);
            lua_pop(lua, 1);
        } else {
            // f << "[" << timestamp << "] " << "Error loading script: " << files[i].substr(0, files[i].size() - (int)(files[i].size() * 0.30)) << " [..]" << std::endl;
        }
    }
    lua_close (lua);

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

    //------ Find first .emu file in directory
	WIN32_FIND_DATA find_emu_file;
	HANDLE hFind = FindFirstFile((wpath + L"\\*.emu").c_str(), &find_emu_file); // wide string used here

	wpath = find_emu_file.cFileName;
	std::string file_found(wpath.begin(), wpath.end());
	
    //------ If no .emu files found, log error
	if  (hFind == INVALID_HANDLE_VALUE) {
		// f << "[" << timestamp << "] " << "Error finding path: " << file_found << std::endl;
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

