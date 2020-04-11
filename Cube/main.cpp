#include <iostream>
#include <vector>

using namespace std;

class Cube {
protected:
    float side;

    float set_side(int side) {
        this->side = side;
    }

public:
    Cube(){
        this->side=10;
    }

    Cube(int side) {
        cout << "kalosirthes ston kubo re" << endl;
        this->set_side(side);
    }

    float get_side() {
        return this->side;
    }

    float area() {
        return this->side * this->side;
    }

    float volume() {
        return this->area() * this->side;
    }
};

class SuperCube:Cube {

    private:

    public:
    typedef Cube super;
    SuperCube():Cube(100)
    {
        cout<<"H pleura tou SuperCube einai: "<<this->side<<endl;
    }

    float Super_get_side(){
        super->get_side();
    }

};


int main() {

    Cube kubos;
    cout << kubos.area() << endl;
    cout << kubos.volume() << endl;

    vector<Cube *> sullogh_kubwn;
    sullogh_kubwn.push_back(new Cube(22));
    cout << sullogh_kubwn[0]->volume() << endl;
    cout << sullogh_kubwn[0]->area() << endl;

    SuperCube SuperKubos;
    cout<< SuperKubos.Super_get_side()<<endl;

    return 0;
}