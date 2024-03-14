#ifndef BFINTERNAT_H
#define BFINTERNAT_H

typedef void (__cdecl *_setMoneyText)(int, int, char); // define original BFUIMgrSetControlForeColor function

class bfinternat {
    public:
    static void setMoneyText(int, int, char);
};

#endif /* BFINTERNAT_H */