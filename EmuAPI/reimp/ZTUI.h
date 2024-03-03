#ifndef ZTUI_H
#define ZTUI_H

typedef unsigned int (*_saveGame)(void); // define original saveGame function

namespace ZTUI {
    class gameopts {
        public:
        static unsigned int saveGame();
    };
};

#endif /* ZTUI_H */