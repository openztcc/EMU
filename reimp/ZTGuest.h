#ifndef ZTGUEST_H
#define ZTGUEST_H

#include <string>

class ZTGuest {
    public:
    static void init();
    static std::string getSelectedGuestName();
};

#endif // ZTGUEST_H