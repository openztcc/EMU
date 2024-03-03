#ifndef BFUNITTYPE_H
#define BFUNITTYPE_H

#include "BFEntityType.h"

class BFUnitType : public BFEntityType {
    public:
    char padding[176]; // 464
    BFUnitType();
    ~BFUnitType();
};

#endif // BFUNITTYPE_H