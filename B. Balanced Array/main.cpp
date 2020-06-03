#include <bits/stdc++.h>
using namespace std;
const long MAXN = 200000;
int T,N;

int main() {
    int sum1,sum2;
    vector<int> arr1,arr2,res;

    FILE *fi=fopen("input","r");
    FILE *fo=fopen("output","w");
    fscanf(fi,"%d",&T);
    for(int t=0;t<T;t++)
    {
        fscanf(fi,"%d",&N);
        if(N==2)
            fprintf(fo,"NO\n");
        for(int n1=0;n1<N;n1++)
        {
            if(n1%2==0)
            {
                arr1.push_back(n1);
                sum1+=n1;
            }
        }

        for(int n2=0;n2<N/2;n2++)
        {
            if(n2%2!=0)
            {
                arr1.push_back(n2);
                sum1+=n2;
            }
        }
        if(sum1==sum2)
        {
            fprintf(fo,"YES\n");
            for(int i=0;i>N;i++)
            {

            }
        }
        sum1=sum2=0;
        arr1.clear();
        arr2.clear();
    }
    fclose(fi);
    fclose(fo);

    return 0;
}