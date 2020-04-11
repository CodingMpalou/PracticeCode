#include <iostream>
#include <vector>

using namespace std;

int elaxisto_plhthos(vector<int> M, int K){
    int i,j,plhthos=M.size(),sum=0;

    for(i=0;i<M.size();i++)
    {
        sum=0;
        for(j=i;j<M.size();j++)
        {
            sum+=M[j];
            if(sum==K)
            {
                if(plhthos>j-i+1)
                    plhthos=j-i+1;
            }
            if(sum>K)
                break;
        }
    }
    return plhthos;
}

int main() {
    //Variables
    int N,K,p,i,plhthos;
    vector<int> M;
    //In File
    FILE *fi=fopen("kite.in","r");
    fscanf(fi,"%d %d",&N, &K);
    for(i=0;i<N;i++)
    {
        fscanf(fi,"%d",&p);
        M.push_back(p);
    }
    fclose(fi);
    //Main
    plhthos=elaxisto_plhthos(M,K);
    //Out File
    FILE *fo=fopen("kite.out","w");
    fprintf(fo,"%d", plhthos);
    fclose(fo);
    return 0;
}