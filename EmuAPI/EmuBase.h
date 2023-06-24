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


#endif

