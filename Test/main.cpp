#include <iostream>

using namespace std;

int bla(int x)
{
    for (int i=0;i<5;i++)
        x+=i;

}

int main() {

    int x;
    int i;

    x=0;
    for (i=0;i<5;i++)
        x+=i;
    cout<<"Case 1: "<<i<<","<<x<<endl;



    x=0;
    i=0;
    while(i<5)
    {
        x+=i;
        i++;
    }
    cout<<"Case 2: "<<i<<","<<x<<endl;

    bla(x);
    cout<<"Case 3: "<<i<<","<<x<<endl;
    return 0;
}