#ifndef ZTUNIT_H
#define ZTUNIT_H


#include "BFUnit.h"

class ZTUnit : public BFUnit
{
    public:
    ZTUnit(void* _thisptr) : BFUnit(_thisptr) {};
    ~ZTUnit() {};
};

#endif // ZTUNIT_H