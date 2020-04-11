#include <iostream>
#include <vector>

using namespace std;

int main() {

    int T,N,X;
    int sum;
    FILE *fi=fopen("input","r");
    FILE *fo=fopen("output","w");
    fscanf(fi,"%d",&T);
    for(int t=0;t<T;t++)
    {
        fscanf(fi,"%d %d",&N,&X);
        int a[N];
        for (int n=0;n<N;n++)
        {
            fscanf(fi,"%d",&a[n]);
        }
    }
    fclose(fi);
    fclose(fo);
    
    return 0;
}