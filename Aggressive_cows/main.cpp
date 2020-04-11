#include <iostream>
#include <vector>

using namespace std;

int largest_min_distance(int C, vector<int> x){

    int res,distance=0,tmp_distance,p;

    for(int i=0;i<x.size();i++)
    {
        for(int j=0;j<C;j++)
        {
            p=x[i];
            if(x[i]>x[i-1]) tmp_distance=x[i]-p;
            else tmp_distance=p-x[i];

            if(tmp_distance>distance)
                distance=tmp_distance;
        }
   }

    return res;
}

int main() {
    int T,N,C,p,res;
    vector<int> x;

    FILE *fi=fopen("Input","r");
    FILE *fo=fopen("Output","w");
    fscanf(fi,"%d",&T);
    for(int t=0;t<T;t++)
    {
        fscanf(fi,"%d %d",&N, &C);
        for(int n=0;n<N;n++)
        {
            fscanf(fi,"%d",&p);
            x.push_back(p);
        }
        res=largest_min_distance(C, x);
        x.clear();
        fprintf(fo,"%d",res);
    }
    fclose(fi);
    fclose(fo);

    return 0;
}