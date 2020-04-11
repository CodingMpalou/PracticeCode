#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct dentro {
    int x;
    struct dentro *next;
};

int main() {


    int *a;
    a = new int;
    *a=3;
    cout<<*a<<endl;

    int **b;
    b=(new int*);
    *b=new int;
    **b=5;
    cout<<**b;


    return 0;
}