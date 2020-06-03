#include "RustUniverse.h"

RustUniverse::RustUniverse(int x, int y) : RustPlayer(x, y), RustMap(x, y) {}
RustUniverse::RustUniverse(int x, int y, char c) : RustPlayer::RustPlayer(x, y), RustMap::RustMap(x, y, c), RustWorld::RustWorld(x,y) {}
