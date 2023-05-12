#ifndef TEKUTILITIES_H
#define TEKUTILITIES_H

#include "Windows.h"
#include <TlHelp32.h>
#include <Psapi.h>
#include <tchar.h>
#include <stddef.h>

typedef __int32 uint32_t;

namespace Zoo
{
	class Process
	{
	public:
		DWORD getModuleBaseAddress();

		uint32_t floatToUint(float);
		float uintToFloat(uint32_t);
		Zoo::Process();
		DWORD id;
		HANDLE handle;
		DWORD base;
		DWORD thread;

	private:
		DWORD __getModuleBaseAddress(DWORD, const TCHAR*);
		HANDLE __getZooHandle(DWORD);
		DWORD __getZooThread(DWORD);
	};

	

}



#endif

