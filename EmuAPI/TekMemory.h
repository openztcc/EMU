#ifndef TEKMEMORY_H
#define TEKMEMORY_H

#include "Windows.h"


	template <typename T> class Memory
	{
	public:
		Memory() {};
		T readMemory(LPVOID);
		void writeMemory(LPVOID, T);
		DWORD protectMemory(LPVOID, DWORD);
	};


	// read from memory
	template<typename T>
	T Memory<T>::readMemory(LPVOID adr) {
		return *((T*)adr);
	}

	// write to memory
	template<typename T>
	void Memory<T>::writeMemory(LPVOID adr, T val) {
		*((T*)adr) = val;
	}
	
	// Save memory protection for given process handle
	template<typename T>
	DWORD Memory<T>::protectMemory(LPVOID adr, DWORD prot) {
		DWORD oldProt;
		//HANDLE handleZ = GetModuleHandle(L"zoo.exe");
		VirtualProtect(adr, sizeof(T), prot, &oldProt);
		return oldProt;
	}

#endif
