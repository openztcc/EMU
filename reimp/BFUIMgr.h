#ifndef BFUIMGR_h
#define BFUIMGR_h
#include <Windows.h>
#include "ZTUI.h"

typedef void (__thiscall *_setControlForeColor)(void*, int, ZTUI::main::rgb); // define original BFUIMgrSetControlForeColor function
typedef int (__thiscall *_confirmDialog)(void*, char, int, int, std::string, char, char, int, int); // define original BFUIMgrConfirmDialog function 

class BFUIMgr {
    public:
    BFUIMgr();
    ~BFUIMgr();
    char padding[170]; // assumption on size. constructor not yet found.
    static void* getElement(int);
    static int __cdecl __getElement(void* pThis, int param_1);
    static void clickSave();
    static void* getUIMgr();
    static DWORD getOffset(DWORD);
    static void setControlForeColor(void*, int, ZTUI::main::rgb);
    static int confirmDialog(void*, char, int, int, std::string, char, char, int, int);


    // static BFUIMgr &shared_instance() {
	// 	static BFUIMgr instance;
	// 	return instance;
	// }
};

typedef void* (__thiscall  *_getElement)(void*, int); // define original getElement function


#endif /* BFUIMgr_h */