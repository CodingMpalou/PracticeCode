#ifndef RUSTMAP
#define RUSTMAP
#include <bits/stdc++.h>
#include "RustPlayer.h"
#include "RustWorld.h"

using namespace std;

class RustMap:  virtual public RustWorld {
    public:
        RustMap();
        RustMap(int x, int y);
        RustMap(int x, int y, char c);
        RustMap(char c);
        RustMap(vector<vector<char>> map, char defaultCharMap);

        vector<vector<char>> getMap();
        vector<RustPlayer*> getPlayers();
        char getDefaultCharMap();
        void setMap(vector<vector<char>> map);
        void setMap();
        void setMap( char c);
        void setPlayers(vector<RustPlayer*> players);
        void setDefaultCharMap(char defaultCharMap);
        void enterRandPlayersInMap(int playersNumber);
        void printMap();

    private:
        char defaultCharMap;
        vector<vector<char>> map;
        vector<RustPlayer*> players;
};

#endif
