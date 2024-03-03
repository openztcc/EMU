#ifndef BFUIMGR_h
#define BFUIMGR_h
#include <Windows.h>
#include "ZTUI.h"

typedef int (__cdecl  *_getElement)(void*, int); // define original getElement function

class BFUIMgr {
    public:
    BFUIMgr();
    ~BFUIMgr();
    char padding[170]; // assumption on size. constructor not yet found.
    static int getElement(int);
    static int __cdecl __getElement(void* pThis, int param_1);
    static void clickSave();

    // static BFUIMgr &shared_instance() {
	// 	static BFUIMgr instance;
	// 	return instance;
	// }
};

#endif /* BFUIMgr_h */