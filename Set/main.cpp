# include <stdio.h>
# include <iostream>
#include "SetProject.h"

using namespace std;
int foo (int &n);
int main (void)
{
    SetProject *aa = new SetProject();
    int a[3]={4,5,6}, num = 2;
    cout<<foo(a[2])<<endl;
    return 0;
}
int foo (int &n)
{
    return n*=3;
}
