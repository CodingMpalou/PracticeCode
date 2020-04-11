#include <iostream>
#include <vector>

using namespace std;

int min_diafora(vector<int> x){
    int i,res,sum=0,poso=0;

    for(i=0;i<x.size();i++)
        sum+=x[i];

    for(i=0;i<x.size();i++)
    {
        if(poso<sum/2) {
            cout<<poso;
            poso += x[i];
        }
    }

    res=(sum/2)-poso;
    return res;
}

int main() {

   int N,p,i,res;
   vector<int> x;

   //In File
   FILE *fi=fopen("kalanta.in","r");
   fscanf(fi,"%d",&N);
    for(i=0;i<N;i++)
    {
        fscanf(fi,"%d",&p);
        x.push_back(p);
    }
    //Main
    res=min_diafora(x);

    //Out File
    FILE *fo=fopen("kalanta.out","w");
    fprintf(fo,"%d",res);
    return 0;
}