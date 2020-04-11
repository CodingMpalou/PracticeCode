#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {

    int N,M,i,S,max=0,min=0,zeros=0;
    vector<int> index;

    //In File
    FILE *fi=fopen("aris.in","r");
    fscanf(fi,"%d %d",&N,&M);
    for(i=0;i<M;i++)
        index.push_back(0);
    max=0;
    for(i=0;i<N;i++)
    {
        fscanf(fi, "%d", &S);
        index[S-1]++;
        if(max<index[S-1])
            max=index[S-1];
    }
    fclose(fi);

    min=max;
    for(i=0;i<index.size();i++)
    {
        if(index[i]==0)
            zeros++;
        if(min>index[i] && index[i]!=0)
            min=index[i];
    }

    //Out File
    FILE *fo=fopen("aris.out","w");
    fprintf(fo,"%d %d %d",M-zeros, min, max);
    fclose(fo);

    return 0;
}