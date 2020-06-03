#include "RustWorld.h"

RustWorld::RustWorld(){}

RustWorld::RustWorld(int XDIM, int YDIM){
    this->setXDIM(XDIM);
    this->setYDIM(YDIM);
}

int RustWorld::getXDIM() const {
    return XDIM;
}

void RustWorld::setXDIM(int XDIM) {
    RustWorld::XDIM = XDIM;
}

int RustWorld::getYDIM() const {
    return YDIM;
}

void RustWorld::setYDIM(int YDIM) {
    RustWorld::YDIM = YDIM;
}