#ifndef ZTAPP_H
#define ZTAPP_H

#include <Windows.h>

typedef void (__cdecl *_handleKeyDown)(int); // define original handleKeyDown function

class ZTApp
{
public:
    static void init();
    static void handleKeyDown(int);
    static void emuKeysHandleKeyDown(int);
};

#endif /* ZTAPP_H */