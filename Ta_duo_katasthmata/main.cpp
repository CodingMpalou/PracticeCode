#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> bres_max(vector<int> A, int K){
    int i,j,sum;
    vector<int> max;


    for(i=0;i<2;i++)
        max.push_back(0);

    for(i=0;i<A.size()-K+1;i++)
    {
        sum=0;
        for(j=i;j<K+i;j++)
            sum+=A[j];

        cout<<" I: "<<i<<" Sum: "<<sum<<" Max[0]: "<<max[0]<<" Max[1]: "<<max[1]<<endl;
        if(max[0]<sum)
        {
            max[1]=max[0];
            max[0]=sum;
            continue;
        }
        if(max[1]<sum && max[0]>=sum)
            max[1]=sum;
    }

    return max;
}

int main() {
    int N,K,i,p,sum=0;
    vector<int> A,max;

    //In file
    FILE *fi= fopen("shops.in", "r");
    fscanf(fi, "%d %d", &N, &K);
    for(i=0;i<N;i++)
    {
        fscanf(fi,"%d",&p);
        A.push_back(p);
    }
    fclose(fi);

    //Main
    max=bres_max(A,K);
    sum=max[0]+max[1];
    //Out File
    FILE *fo=fopen("shops.out","w");
    fprintf(fo, "%d",sum);
    fclose(fo);

    return 0;
}