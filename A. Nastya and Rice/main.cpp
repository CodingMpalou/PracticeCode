#include <bits/stdc++.h>
using namespace std;
float a,b,c,d;
int T,N;

int main() {

    FILE *fi=fopen("input","r");
    FILE *fo=fopen("output","w");
    fscanf(fi,"%d",&T);
    for(int t=0;t<T;t++)
    {
        fscanf(fi,"%d %f %f %f %f",&N, &a, &b, &c, &d);
        if(((c+d)/(a+b)==N) || ((a+b)/(c+b)==N))
            fprintf(fo,"Yes\n");
        else if(((c-d)/(a-b)==N) || ((a-b)/(c-d)==N))
            fprintf(fo,"Yes\n");
        else if(((c+d)/(a-b)==N) || ((a-b)/(c+d)==N))
            fprintf(fo,"Yes\n");
        else if(((c-d)/(a+b)==N) || ((a+b)/(c-d)==N))
            fprintf(fo,"Yes\n");
        else   fprintf(fo,"No\n");
    }
    fclose(fi);
    fclose(fo);

    return 0;
}