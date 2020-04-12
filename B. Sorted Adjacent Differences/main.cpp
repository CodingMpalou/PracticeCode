#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main() {

    int T,N,itemp=0,jtemp=0;

    FILE *fi=fopen("input","r");
    FILE *fo=fopen("output","w");
    fscanf(fi,"%d",&T);
    for(int t=0;t<T;t++)
    {
        fscanf(fi,"%d",&N);
        int v[N];
        for(int n=0;n<N;n++)
            fscanf(fi,"%d", &v[n]);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(v[i]-v[j]>=v[i+1]-v[j])
                {
                    itemp=v[i];
                    v[i]=v[i+1];
                    v[i+1]=itemp;
                }
            }
        }
        for(int i=0;i<N;i++)
            fprintf(fo, "%d", v[i]);
        fprintf(fo,"\n");
    }
    fclose(fi);
    fclose(fo);

    return 0;
}