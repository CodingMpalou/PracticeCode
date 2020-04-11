//
// Created by zagor on 20/12/2019.
//

#ifndef SET_SETPROJECT_H
#define SET_SETPROJECT_H

#include <string>
using namespace std;
class SetProject {

private:
    int a;
    string aa;
public:
    int getA() const;

    void setA(int a);

    const string &getAa() const;

    void setAa(const string &aa);

    SetProject(int a, const string &aa);

    SetProject();
};


#endif //SET_SETPROJECT_H
