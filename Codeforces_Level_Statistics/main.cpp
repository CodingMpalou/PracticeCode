#include <iostream>
#include <vector>

using namespace std;

int main() {

    int T,N,a=0,b=0;
    string res="YES";

    FILE *fi=fopen("input","r");
    FILE *fo=fopen("output","w");
    fscanf(fi,"%d",&T);
    for(int t=0;t<T;t++)
    {
        fscanf(fi,"%d",&N);
        if(N==1)
            fprintf(fo, "YES\n");
        int p[N],c[N];
        for (int n=0;n<N;n++)
        {
            fscanf(fi, "%d %d", &p[n], &c[n]);
            if((p[n]>a && c[n]>b) || (p[n]==a && c[n]==b)) res="YES";
            else res="NO";
            a=p[n];
            b=c[n];
        }
        if(N!=1)
            fprintf(fo,"%s\n",res.c_str());
    }
    fclose(fi);
    fclose(fo);
    return 0;
}
//input.fd0138e687.txt
//output.fd0138e687.txt