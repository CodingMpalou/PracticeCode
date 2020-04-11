#include <iostream>
#include <vector>

using namespace std;

int main() {
    //Variables
    int Q,i,p;
    vector<int> x,res;
    vector<unsigned long long int> A;

    for(i=1;i<2^60;i++) {
        A.push_back(*new int);
        A[i]=i;
    }
    //In File
    FILE *fi=fopen("input","r");
    fscanf(fi,"%d",&Q);
    for(i=0;i<2;i++)
    {
        fscanf(fi,"%d",&p);
        x.push_back(p);
    }
    fclose(fi);

    //Main
    cout<<Q;
    for(i=0;i<x.size();i++)
        cout<<x[i]<<endl;


    //Out File
    FILE *fo=fopen("output","w");
    for(i=0;i<Q;i++)
        fprintf(fo,"%d\n",&res[i]);
    fclose(fo);

    return 0;
}