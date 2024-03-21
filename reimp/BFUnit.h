#ifndef BFUNIT_H
#define BFUNIT_H

#include "BFEntity.h"

class BFUnit : public BFEntity
{
    public:
    BFUnit(void* _thisptr) : BFEntity(_thisptr) {};
    ~BFUnit() {};
};

#endif // BFUNIT_H