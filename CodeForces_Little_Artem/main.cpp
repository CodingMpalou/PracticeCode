#include <iostream>

using namespace std;

int main() {
    //Variables
    int T=0,M=0,N=0;

    //In File
    FILE *fi=fopen("input","r");
    FILE *fo=fopen("output","w");
    fscanf(fi,"%d",&T);
    for(int t=0;t<T;t++)
    {
        fscanf(fi,"%d %d",&N, &M);
        char matrix[N][M];
        for (int n=0;n<N;n++)
        {
            for (int m=0;m<M;m++)
            {
                if ((n+m)%2==0)
                    fprintf(fo,"%c",'B');
                else
                    fprintf(fo,"%c",'W');
            }
            fprintf(fo,"%c",'\n');
        }
    }
    fclose(fi);
    fclose(fo);
    return 0;
}