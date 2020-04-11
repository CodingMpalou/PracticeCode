#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T=0,N=0;
    string res;
    //In File
    FILE *fi=fopen("input","r");
    FILE *fo=fopen("output","w");
    fscanf(fi,"%d",&T);
    for(int t=0;t<T;t++)
    {
        fscanf(fi,"%d",&N);
        int A[N],B[N];
        for (int n=0;n<N;n++) {
            fscanf(fi, "%d", &A[n]);
        }
        for (int n=0;n<N;n++) {
            fscanf(fi, "%d", &B[n]);
        }
        int sign,found;
        for (int i=0;i<N;i++)
        {
            res = "YES";
            found = 0;
            if (A[i]!=B[i])
            {
                if (B[i]-A[i]>0)
                    sign =1;
                else
                    sign=-1;
                for (int j=0;j<i;j++)
                {
                    if (sign == A[j]){
                        found =1;
                        break;
                    }
                }
                if (found == 0) {
                    res = "NO";
                    break;
                }

            }
        }
        fprintf(fo,"%s\n",res.c_str());

    }
    fclose(fi);
    fclose(fo);

    return 0;
}