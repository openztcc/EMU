#include "EmuBase.h"
#include <sstream>

DWORD EmuBase::id = GetCurrentProcessId();
HANDLE EmuBase::handle = EmuBase::__getZooHandle(EmuBase::id);
DWORD EmuBase::base = (DWORD)GetModuleHandle(NULL);
DWORD EmuBase::thread = EmuBase::__getZooThread(EmuBase::id);

/// <summary>
/// Constructor: initiate  process variables 
/// </summary>
EmuBase::EmuBase()
{
	id = GetCurrentProcessId();
	handle = __getZooHandle(id);
	base = (DWORD)GetModuleHandle(NULL);
	thread = __getZooThread(id);
}

/// <summary>
/// Returns 
/// </summary>
/// <param name="s">: input 32 bit float</param>
DWORD EmuBase::getModuleBaseAddress()
{
	return base;
}

void EmuBase::ExportClassToLua(sol::state_view& lua)
{
	lua.new_usertype<EmuBase>("emuBase",
		sol::no_constructor,
		"singleKey", &EmuBase::SingleKey,
		"doubleKey", &EmuBase::DoubleKey,
		"tripleKey", &EmuBase::TripleKey
	);
}

/// <summary>
/// Returns
/// </summary>
/// <param name="s">: input 32 bit float</param>
std::string EmuBase::ptrToHexStr(void* ptr)
{
	std::stringstream ss;
	ss << std::hex << reinterpret_cast<DWORD>(ptr);
	return ss.str();
}

/// <summary>
/// Returns
/// </summary>
/// <param name="s">: input 32 bit float</param>
std::string EmuBase::ptrToHexStr(DWORD ptr)
{
	std::stringstream ss;
	ss << std::hex << ptr;
	return ss.str();
}

/// <summary>
/// Convert 32 bit float to 32 unsigned 32 bit value
/// </summary>
/// <param name="s">: input 32 bit float</param>
uint32_t EmuBase::floatToUint(float f)
{
	uint32_t result;
	memcpy(&result, &f, sizeof(f));
	return result;
}

/// <summary>
/// Convert unsigned 32 bit integer to 32 bit float
/// </summary>
/// <param name="s">: input unsigned 32 bit integer</param>
float EmuBase::uintToFloat(uint32_t n)
{
	float result;
	memcpy(&result, &n, sizeof(n));
	return result;
}

/// <summary>
/// Obtain process handle for zoo.exe
/// </summary>
/// <param name="s">: input zoo.exe process ID</param>
HANDLE EmuBase::__getZooHandle(DWORD zooID)
{
	HANDLE zooHandle;
	return zooHandle = OpenProcess(PROCESS_ALL_ACCESS, true, zooID);
}

/// <summary>
/// Obtain thread ID for zoo.exe
/// </summary>
/// <param name="s">: input zoo.exe process ID</param>
DWORD EmuBase::__getZooThread(DWORD zooID)
{
	THREADENTRY32 entry;
	entry.dwSize = sizeof(THREADENTRY32);
	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
	if (Thread32First(snapshot, &entry) == TRUE) {
		while (Thread32Next(snapshot, &entry) == TRUE) {
			if (entry.th32OwnerProcessID == EmuBase::id) {
				CloseHandle(snapshot);
				return entry.th32ThreadID;
			}
		}
	}
	CloseHandle(snapshot);
	return NULL;
}

// utility function for near hooking
DWORD EmuBase::callHook(DWORD hookAt, DWORD newFunc)
{
	DWORD newOffset = newFunc - hookAt - 5;
	DWORD oldProtection = EmuBase::Memory<DWORD>::protectMemory((LPVOID)(hookAt + 1), PAGE_EXECUTE_READWRITE);
	DWORD originalOffset = EmuBase::Memory<DWORD>::readMemory((LPVOID)(hookAt + 1));
	EmuBase::Memory<DWORD>::writeMemory((LPVOID)(hookAt + 1), newOffset);
	EmuBase::Memory<DWORD>::protectMemory((LPVOID)(hookAt + 1), oldProtection);
	return originalOffset + hookAt + 5;
}

/// @brief Set key to custom action. Single key.
/// @param VK_IKEY 
/// @return 
bool EmuBase::SingleKey(const int VK_IKEY)
{
	if (GetAsyncKeyState(VK_IKEY) & 0x8000)
	{
		return true;
	}
	return false;
}

/// @brief Set keys to custom action--two key binding.
/// @param VK_IKEY 
/// @param VK_SKEY 
/// @return 
bool EmuBase::DoubleKey(const int VK_IKEY, const int VK_SKEY)
{
	if (GetAsyncKeyState(VK_IKEY) & 0x8000 && GetAsyncKeyState(VK_SKEY) & 0x8000)
	{
		return true;
	}
	return false;
}

/// @brief Set keys to custom action--three key binding.
/// @param VK_IKEY 
/// @param VK_SKEY 
/// @param VK_TKEY 
/// @return 
bool EmuBase::TripleKey(const int VK_IKEY, const int VK_SKEY, const int VK_TKEY)
{
	if (GetAsyncKeyState(VK_IKEY) & 0x8000 && GetAsyncKeyState(VK_SKEY) & 0x8000)
	{
		return true;
	}
	return false;
}

/// @brief Print out to log file
/// @param log
/// @param file
/// @return
void EmuBase::logToFile(std::string log, std::ios::openmode mode)
{
	std::ofstream f;
	f.open("getelement.log", mode);
	const char* cstr = log.c_str();
	f << "[" << __TIMESTAMP__ << "] " << cstr << std::endl;
	f.close();
}