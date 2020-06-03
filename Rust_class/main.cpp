#include <bits/stdc++.h>
#include "Rust/RustPlayer.h"
#include "Rust/RustMap.h"
#include "Rust/RustUniverse.h"

using namespace std;

int main()
{
    srand(0);

    int XDIM=10;
    int YDIM=50;
    vector<vector<char>> map;
    vector<int> letters={65,66,67,68,69,126};

    RustUniverse *universe=new RustUniverse(XDIM,YDIM,'~');
    universe->enterRandPlayersInMap(50);
    universe->printMap();

    for(int i=0;i<10;i++){
        for(int j=0;j<50;j++)
            map[i].push_back((char)(letters[rand()%letters.size()]));
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<50;j++) {
            map[i][j]=map[i+universe->playerMovement[0]][j+universe->playerMovement[1]];
        }asdasd
    }
    return 0;
}