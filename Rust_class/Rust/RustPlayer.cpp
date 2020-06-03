#include "RustPlayer.h"
#include <bits/stdc++.h>

using namespace std;

RustPlayer::RustPlayer() {}

RustPlayer::RustPlayer(int x,int y): RustWorld::RustWorld(x,y) {

    this->initIndex();
    this->initHp();
    this->initHunger();
    this->initHydration();
    this->initGender();
    this->initUsername();
    this->initClothes();
    this->initInventory();
}

void RustPlayer::initIndex(){
    this->index.push_back(rand() % this->RustWorld::getXDIM());
    this->index.push_back(rand() % this->RustWorld::getYDIM());
}

void RustPlayer::initHp(){
    int theHp = rand() % 100;
    this->hp = theHp;
}

void RustPlayer::initHunger(){
    int theHunger = rand() % 300;
    this->hunger = theHunger;
}

void RustPlayer::initHydration(){
    int theHydration = rand() % 300;
    this->hydration = theHydration;
}

void RustPlayer::initGender(){
    int theGender = rand() % this->presetGender.size();
    this->gender = presetGender[theGender];
}

void RustPlayer::initUsername(){
    char theUsername;
    theUsername=((char)(65+(rand() % 25)));
    cout<<theUsername<<endl;
    this->username = theUsername;
}

void RustPlayer::initClothes(){
    int selectNumOfClothes = rand() % this->presetClothes.size()+1;
    for(int i=0;i<selectNumOfClothes;i++)
        this->clothes.push_back(this->presetClothes[rand()%this->presetClothes.size()]);
}

void RustPlayer::initInventory(){
//    srand(time(0));
    int selectNumOfInventory = 1 + (rand() % (this->presetInventory.size() - 1) );
    for(int i=0;i<selectNumOfInventory;i++)
        this->inventory.push_back(this->presetInventory[rand()%this->presetInventory.size()]);
}

RustPlayer::RustPlayer(vector<int> index, int hp, int hunger, int hydration, string gender ,char username ,vector<string> inventory, vector<string> clothes){
    this->index=index;
    this->hp = hp;
    this->hunger = hunger;
    this->hydration = hydration;
    this->gender = gender;
    this->username = username;
    this->inventory=inventory;
    this->clothes = clothes;
}

vector<int> RustPlayer::getIndex(){
    return this->index;
}

void RustPlayer::setIndex(vector<int> index){
    this->index=index;
}

int RustPlayer::getHp(){
    return this->hp;
}

void RustPlayer::setHp(int hp){
    this->hp=hp;
}

int RustPlayer::getHunger(){
    return this->hunger;
}

void RustPlayer::setHunger(int hunger){
    this->hunger=hunger;
}

int RustPlayer::getHydration(){
    return this->hydration;
}

void RustPlayer::setHydration(int hydration){
    this->hydration=hydration;
}

string RustPlayer::getGender(){
    return this->gender;
}

void RustPlayer::setGender(string gender){
    this->gender=gender;
}

char RustPlayer::getUsername(){
    return this->username;
}

void RustPlayer::setUsername(char username){
    this->username=username;
}

vector<string> RustPlayer::getClothes(){
    return this->clothes;
}

void RustPlayer::setClothes(string clothes){
    this->clothes.push_back(clothes);
}

vector<string> RustPlayer::getInventory(){
    return this->inventory;
}

void RustPlayer::setInventory(string inventory) {
    this->inventory.push_back(inventory);
}

int RustPlayer::playerHasGun() {
    int hasGun=0;
    for(int i=0;i<this->inventory.size();i++){
        if(this->inventory[i]=="gun")
            hasGun=1;
    }
    return hasGun;
}

void RustPlayer::printUsername(){
    cout<<"The Username is: "<<this->getUsername()<<endl;
}

void RustPlayer::printHp(){
    cout<<this->getUsername()<<" has "<<this->getHp()<<" hp"<<endl;
}

void RustPlayer::printHunger(){
    cout<<this->getUsername()<<" has "<<this->getHunger()<<" hunger"<<endl;
}

void RustPlayer::printHydration(){
    cout<<this->getUsername()<<" has "<<this->getHydration()<<" hydration"<<endl;
}

void RustPlayer::printGender(){
    cout<<this->getUsername()<<"'s gender is: "<<this->getGender()<<endl;
}

void RustPlayer::printInventory(){
    cout<<this->getUsername()<<" has: ";
    for(int i=0;i<this->getInventory().size();i++)
        cout<<(this->getInventory())[i]<<", ";
    cout<<endl;
    if(this->playerHasGun()){
        cout<<"Found a gun! PEW PEW!!!"<<endl;
    }
    else
        cout<<"No Gun"<<endl;
}

void RustPlayer::printClothes(){
    cout<<this->getUsername()<<" wears: ";
    vector<string> asd = this->getClothes();
    for(int i=0;i<this->getClothes().size();i++)
        cout<<(this->getClothes())[i]<<", ";
    cout<<endl;
}

void RustPlayer::printInfo(){
    this->printUsername();
    this->printGender();
    this->printHp();
    this->printHunger();
    this->printHydration();
    this->printInventory();
    this->printClothes();
}

vector<int> RustPlayer::playerMovement(){
    vector<int> position;
    position[0] = rand() % 3-1;
    position[1] = rand() % 3-1;
    return position;
}
//x =
//rustMap[x+position[0]][y+position[1]]