#include <bits/stdc++.h>
#include "RustWorld.h"
#ifndef RUSTPLAYER
#define RUSTPLAYER

using namespace std;

class RustPlayer: virtual public RustWorld {
    public:
        RustPlayer();
        RustPlayer(int XDIM,int YDIM);
        RustPlayer(vector<int> index, int hp, int hunger, int hydration, string gender ,char username ,vector<string> inventory, vector<string> clothes);

        vector<int> getIndex();
        void setIndex(vector<int> index);
        int getHp();
        void setHp(int hp);
        int getHunger();
        void setHunger(int hunger);
        int getHydration();
        void setHydration(int hydration);
        string getGender();
        void setGender(string gender);
        char getUsername();
        void setUsername(char username);
        vector<string> getClothes();
        void setClothes(string clothes);
        vector<string> getInventory();
        void setInventory(string inventory);
        int playerHasGun();
        void printHp();
        void printHunger();
        void printHydration();
        void printGender();
        void printUsername();
        void printClothes();
        void printInventory();
        void printInfo();
        vector<int> playerMovement();

    private:
        enum color {WHITE, BLACK, BLONDE, BROWN};
        int hp;
        int hunger;
        int hydration;

        string gender;
        char username;

        vector<string> clothes;
        vector<string> inventory;

        vector<int> index;

        vector<string> presetGender = {"male","female"};
        vector<string> presetClothes = {"gloves","pants","shoes","mask","shirt","jacket"};
        vector<string> presetInventory = {"rock","torch","gun","tool","food","materials","components","armor","building plan","wires"};

        void initIndex();
        void initHp();
        void initHunger();
        void initHydration();
        void initGender();
        void initUsername();
        void initClothes();
        void initInventory();
};

#endif
