#include "TekUtilities.h"



/// <summary>
/// Constructor: initiate  process variables 
/// </summary>
Zoo::Process::Process()
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
DWORD Zoo::Process::getModuleBaseAddress()
{
	return base;
}

/// <summary>
/// Convert 32 bit float to 32 unsigned 32 bit value
/// </summary>
/// <param name="s">: input 32 bit float</param>
uint32_t Zoo::Process::floatToUint(float f) 
{
	uint32_t result;
	memcpy(&result, &f, sizeof(f));
	return result;
}

/// <summary>
/// Convert unsigned 32 bit integer to 32 bit float
/// </summary>
/// <param name="s">: input unsigned 32 bit integer</param>
float Zoo::Process::uintToFloat(uint32_t n) 
{
	float result;
	memcpy(&result, &n, sizeof(n));
	return result;
}

/// <summary>
/// Obtain process handle for zoo.exe
/// </summary>
/// <param name="s">: input zoo.exe process ID</param>
HANDLE Zoo::Process::__getZooHandle(DWORD zooID)
{
	HANDLE zooHandle;
	return zooHandle = OpenProcess(PROCESS_ALL_ACCESS, true, zooID);
}

/// <summary>
/// Obtain thread ID for zoo.exe
/// </summary>
/// <param name="s">: input zoo.exe process ID</param>
DWORD Zoo::Process::__getZooThread(DWORD zooID)
{
	THREADENTRY32 entry;
	entry.dwSize = sizeof(THREADENTRY32);
	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
	if (Thread32First(snapshot, &entry) == TRUE) {
		while (Thread32Next(snapshot, &entry) == TRUE) {
			if (entry.th32OwnerProcessID == id) {
				CloseHandle(snapshot);
				return entry.th32ThreadID;
			}
		}
	}
	CloseHandle(snapshot);
	return NULL;
}