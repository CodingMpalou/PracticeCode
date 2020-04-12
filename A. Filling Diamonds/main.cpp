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
        fprintf(fo,"%d\n",N);
    }
    fclose(fi);
    fclose(fo);
    
    return 0;
}