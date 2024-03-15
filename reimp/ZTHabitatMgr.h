#ifndef ZT_HABITATMGR_H
#define ZT_HABITATMGR_H

class ZTHabitatMgr {
public:
    ZTHabitatMgr();
    ~ZTHabitatMgr();
    char padding[112]; // assumption on size. constructor not yet found.
    static ZTHabitatMgr &shared_instance() {
        static ZTHabitatMgr instance;
        return instance;
    }
};

#endif // ZT_HABITATMGR_H