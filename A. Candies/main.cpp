#include <bits/stdc++.h>
using namespace std;
const long MAXN = 1000000000;
int T,N;

int main() {
    int x,total,k;

    FILE *fi=fopen("input","r");
    FILE *fo=fopen("output","w");
    fscanf(fi,"%d",&T);
    cout<<T<<endl;
    for(int t=0;t<T;t++)
    {
        fscanf(fi,"%d",&N);

        for(int n=0;n<N;n++)
        {
            for(int i=0;i<N;i++)
            {
                k+=2;
                if(i>0)
                    x+=n*k;
                else if(i==0)
                    x+=n;
                cout  <<x;
                if(x>N)
                    break;
                total=x;
            }
            if(x==N)
                fprintf(fo,"%d\n",x);
            else if(x>N)
                fprintf(fo,"%d\n",total);
            x=total=0;
        }
    }
    fclose(fi);
    fclose(fo);

    return 0;
}