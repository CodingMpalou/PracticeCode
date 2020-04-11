//
// Created by zagor on 20/12/2019.
//

#include "SetProject.h"

int SetProject::getA() const {
    return a;
}

void SetProject::setA(int a) {
    SetProject::a = a;
}

const string &SetProject::getAa() const {
    return aa;
}

void SetProject::setAa(const string &aa) {
    SetProject::aa = aa;
}

SetProject::SetProject() {}
SetProject::SetProject(int a, const string &aa) : a(a), aa(aa) {}
