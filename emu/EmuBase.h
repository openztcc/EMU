#ifndef EMUBASE_H
#define EMUBASE_H

#include "Windows.h"
#include <TlHelp32.h>
#include <Psapi.h>
#include <tchar.h>
#include <stddef.h>
#include <ctime>
#include <fstream>
#include "sol/sol.hpp"

class EmuBase
{
public:
	template <typename T>
	struct Memory
	{
	public:
		Memory() {};
		static T readMemory(LPVOID);
		static void writeMemory(LPVOID, T);
		static DWORD protectMemory(LPVOID, DWORD);
		static T* pointMemory(LPVOID adr);
	};

	static DWORD getModuleBaseAddress();
	static DWORD callHook(DWORD hookAt, DWORD newFunc);
	static void logToFile(std::string log, std::ios::openmode);
	static std::string ptrToHexStr(void*);
	static std::string ptrToHexStr(DWORD);

	static uint32_t floatToUint(float);
	static float uintToFloat(uint32_t);
	EmuBase();
	static DWORD id;
	static HANDLE handle;
	static DWORD base;
	static DWORD thread;
	static void ExportClassToLua(sol::state_view&);

	// Windows Mgmt

	static bool SingleKey(const int);
	static bool DoubleKey(const int, const int);
	static bool TripleKey(const int, const int, const int);

protected:
	static DWORD __getModuleBaseAddress(DWORD, const TCHAR*);
	static HANDLE __getZooHandle(DWORD);
	static DWORD __getZooThread(DWORD);
};

// read from memory
template<typename T>
T EmuBase::Memory<T>::readMemory(LPVOID adr)
{
	return *((T*)adr);
}

// write to memory
template<typename T>
void EmuBase::Memory<T>::writeMemory(LPVOID adr, T val)
{
	*((T*)adr) = val;
}

// Save memory protection for given process handle
template<typename T>
DWORD EmuBase::Memory<T>::protectMemory(LPVOID adr, DWORD prot)
{
	DWORD oldProt;
	//HANDLE handleZ = GetModuleHandle(L"zoo.exe");
	VirtualProtect(adr, sizeof(T), prot, &oldProt);
	return oldProt;
}

template<typename T>
T* EmuBase::Memory<T>::pointMemory(LPVOID adr)
{
	return ((T*)adr);
}

// shelf: near call hook

// // declare addToBudget (goes to top)
// DWORD __fastcall addToBudget(DWORD, float);

// // reroute old function to new function
// typedef DWORD(__fastcall _origFunc)(DWORD arg1, float transaction);
// _origFunc* __addToBudget = (_origFunc*)callHook(0x0050A245, (DWORD)&addToBudget);

// // deposit = admission fee paid by guest 
// DWORD __fastcall addToBudget(DWORD tclass, float transaction)
// {
// 	//transaction = 10000; // final release won't see this line. also the idea will be to call this function
// 	                     // from a VF table to use other class members
// 	return __addToBudget(tclass, transaction); // return to location in zoo.exe
// }

#endif
