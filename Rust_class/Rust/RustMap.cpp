#include "RustMap.h"
#include <bits/stdc++.h>

using namespace std;
RustMap::RustMap():RustWorld(){
    this->setMap();
}

RustMap::RustMap(char c){
    this->setMap(c);
}
RustMap::RustMap(int x, int y):RustWorld::RustWorld(x, y){
    this->setMap();
}

RustMap::RustMap(int x, int  y, char c):RustWorld::RustWorld(x, y){
    this->setMap(c);
}

RustMap::RustMap(vector<vector<char>> map, char defaultCharMap){
    this->setMap(map);
    this->setDefaultCharMap(defaultCharMap);
}

char RustMap::getDefaultCharMap(){
    return this->defaultCharMap;
}

void RustMap::setDefaultCharMap(char defaultCharMap){
    this->defaultCharMap=defaultCharMap;
}

vector<RustPlayer*> RustMap::getPlayers(){
    return this->players;
}

void RustMap::setPlayers(vector<RustPlayer*> players) {
    this->players=players;
}

vector<vector<char>> RustMap::getMap(){
    return this->map;
}

void RustMap::setMap(vector<vector<char>> map){
    this->map=map;
}

void RustMap::setMap() {
    this->defaultCharMap = ' ';
    map.empty();
    for(int i=0;i<this->RustWorld::getXDIM();i++)
    {
        this->map.push_back(*new vector<char>());
        for(int j=0;j<this->RustWorld::getYDIM();j++)
            this->map[i].push_back(' ');

    }
}

void RustMap::setMap(char c){
    this->defaultCharMap = c;
//    this->setIndex(x,y)
    map.empty();
    for(int i=0;i<RustWorld::getXDIM();i++)
    {
        this->map.push_back(*new vector<char>());
        for(int j=0;j<RustWorld::getYDIM();j++)
            this->map[i].push_back(c);
    }

}

void RustMap::printMap(){
    for(int i=0;i<map.size();i++)
    {
        for(int j=0;j<map[i].size();j++)
            cout<<map[i][j];
        cout<<endl;
    }
}

void RustMap::enterRandPlayersInMap(int playersNumber){

    if(this->RustWorld::getXDIM()*this->RustWorld::getYDIM() < playersNumber + players.size())
    {
        cout<<"Map can only contain "<<this->RustWorld::getXDIM()*this->RustWorld::getYDIM()<<" players."<<endl;
        cout<<"It already contains "<<players.size()<<endl;
        cout<<"Try again!"<<endl;
    }
    else{
        vector <int> index;

        for (int i=0;i<map.size();i++){
            for (int j=0;j<map[i].size();j++) {
                if (map[i][j] == this->getDefaultCharMap())
                    index.push_back(i * this->RustWorld::getYDIM() + j);
            }
        }

        for (int i=0;i<playersNumber;i++) {

            // Add new player to map
            int idx = index[rand() % index.size()];
            int x = idx / this->RustWorld::getYDIM();
            int y = idx - x * this->RustWorld::getYDIM();

            // New player
            this->players.push_back(new RustPlayer(x,y));
            this->map[x][y] = this->players.at(this->players.size() - 1)->getUsername();
        }
    }

}
