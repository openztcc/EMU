#ifndef EMUBASE_H
#define EMUBASE_H

#include "Windows.h"
#include <TlHelp32.h>
#include <Psapi.h>
#include <tchar.h>
#include <stddef.h>

typedef __int32 uint32_t;

class EmuBase
{
public:
	template <typename T> 
	struct Memory
	{
	public:
		Memory() {};
		T readMemory(LPVOID);
		void writeMemory(LPVOID, T);
		DWORD protectMemory(LPVOID, DWORD);
		T* pointMemory(LPVOID adr);
	};

	DWORD getModuleBaseAddress();
	DWORD callHook(DWORD hookAt, DWORD newFunc);

	uint32_t floatToUint(float);
	float uintToFloat(uint32_t);
	EmuBase();
	DWORD id;
	HANDLE handle;
	DWORD base;
	DWORD thread;

	// Windows Mgmt

	bool SingleKey(const int);
	bool DoubleKey(const int, const int);
	bool TripleKey(const int, const int, const int);

protected:
	DWORD __getModuleBaseAddress(DWORD, const TCHAR*);
	HANDLE __getZooHandle(DWORD);
	DWORD __getZooThread(DWORD);
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

