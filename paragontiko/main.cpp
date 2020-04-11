#include <iostream>
#include <vector>

using namespace std;


int f(int n){
    if(n==1)
        return 1;
    else
        return f(n-1)*n;
}

int t(int n){
    if(n==1)
        return 1;
    else
        return t(n-1)+f(n);
}

int main() {

    int n = 5;
    int a=t(n);

    cout<<"T: "<<a<<endl;
    return 0;
}