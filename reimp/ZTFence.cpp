#include "ZTFence.h"

int ZTFence::cStrength() {
    return *(int*)((char*)this->thisptr + 0x15C);
}

int ZTFence::cLife(int value) {
    return *(int*)((char*)this->thisptr + 0x160) = value;
}

int ZTFence::cLife() {
    return *(int*)((char*)this->thisptr + 0x160);
}  

int ZTFence::cStrength(int value) {
    return *(int*)((char*)this->thisptr + 0x15C) = value;
}