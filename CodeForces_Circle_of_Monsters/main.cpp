#include <iostream>

using namespace std;

int main() {
    int T,N;

    FILE *fi=fopen("input","r");
    FILE *fo=fopen("output","w");
    fscanf(fi,"%d",&T);
    for(int t=0;t<T;t++)
    {
        fscanf(fi,"%d",&N);
        int a[N],b[N],max=0,idx,res;
        for (int n=0;n<N;n++)
        {
            fscanf(fi,"%d %d",&a[n],&b[n]);
            if(b[n]>max)
            {
                max=b[n];
                idx=n;
            }
            res=a[idx]-1;
        }
        fprintf(fo,"%d",res);
    }
    fclose(fi);
    fclose(fo);
    return 0;
}