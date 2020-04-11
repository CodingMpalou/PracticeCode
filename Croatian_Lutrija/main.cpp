#include <iostream>
#include <vector>

using namespace std;

int prime(int n){

    if (n <= 1)
        return 0;

    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return 0;

    return 1;
}

int main() {

    //Variables
    int A,B,i,c=2;
    vector<int> v;

    //In File
    FILE *fi=fopen("input","r");
    fscanf(fi,"%d %d",&A,&B);
    fclose(fi);

    //Main
    v.push_back(A);
    if(prime(A+B)==1)
    {
        v.push_back(A+B);
        c++;
    }
    v.push_back(B);

    //Out File
    FILE *fo=fopen("output","w");
    if(A<2 || B<2 || A>10^14 || B>10^14 || A==B || prime(A)==0 || prime(B)==0)
        fprintf(fo,"%d",-1);

    else if(prime(A)==1 && prime(B)==1)
    {
        fprintf(fo, "%d\n", c);
        for (i = 0; i < c; i++)
            fprintf(fo, "%d ", v[i]);
    }
    fclose(fo);

    return 0;
}