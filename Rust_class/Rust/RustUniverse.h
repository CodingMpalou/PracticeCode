#ifndef RUST_CLASS_RUSTUNIVERSE_H
#define RUST_CLASS_RUSTUNIVERSE_H
#include "RustWorld.h"
#include "RustMap.h"

class RustUniverse: public RustPlayer, public RustMap {
    public:
        RustUniverse();
        RustUniverse(int x, int y);
        RustUniverse(int x, int y,char c);
};

#endif
