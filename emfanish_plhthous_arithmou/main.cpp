#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count_num(vector<int> v, int n, int num) {
    int c=0;
    int i;

    for (i = 0; i < n; i++)
    {
        if (v[i] == num)
            c++;
    }
    if(c==0)
        return -1;
    else
        return c;
}

int main() {
    vector<int> v={1,2,5,2,10,5,2};
    int n=v.size(),num=2,c;

    c=count_num(v, n, num);
    if(c>0)
        cout<<"o arithmos "<<num<<" uparxei "<<c<<" fores";
    else
        cout<<"Den uparxei";

    return 0;
}