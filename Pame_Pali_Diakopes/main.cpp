/* USER: 32pdpu2
LANG: C++
TASK: longsumk */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int K;
vector<int> x;

//1h LUSH
/*
int bres_meres(vector<int> x, int K){
    int i,j,sum=0,res=0;

    for(i=0;i<x.size();i++)
    {
        sum=0;
        for(j=i;j<x.size();j++)
        {
            sum+=x[j];
            if (sum == K)
            {
                if(res<j-i+1)
                    res=j-i+1;
            }
            if(sum>K)
                break;
        }
    }
    return res;
}
*/

//2H LUSH
vector<int> bres_prwto(vector<int> x, int K){
    int i,j,sum=0,res=0,flag=0;

    for(i=0;i<x.size();i++)
    {
        sum=0;
        for(j=i;j<x.size();j++)
        {
            sum+=x[j];
            if (sum == K)
            {
                if(res<j-i+1)
                    res=j-i+1;
                flag=1;
            }
            if(sum>K)
                break;
        }
        if (flag==1)
            break;

    }
    vector<int> v;
    v.push_back(i);
    v.push_back(j);
    v.push_back(sum);
    v.push_back(res);
    return v;
}

vector<int> anadromi(int i,int j,int sum, int w_size)
{
    vector<int> r;
    r.push_back(i);
    r.push_back(j);
    r.push_back(sum);
    r.push_back(w_size);

    if (i+w_size<x.size())
    {
        if (sum == K )
        {
            if ( w_size<j-i+1 ){
                r = anadromi(i,j+1,sum+x[j+1],j-i+1);

            }
            else
                r = anadromi(i,j+1,sum+x[j+1],w_size);
        }
        if (sum > K)
        {
            if (j-i+1 == w_size) {
                if (j+1<x.size())
                    r = anadromi(i + 1, j + 1, sum - x[i] + x[j + 1], w_size);
                else
                    return r;
            }
            else
                r = anadromi(i + 1, j, sum - x[i], w_size);
        }
        if (sum < K)
        {
            if (j+1<x.size())
                r = anadromi(i , j + 1, sum + x[j + 1], w_size);
            else
                return r;
        }
    }

    return r;
}

int bres_meres(vector<int> x, int K)
{
    vector<int> info = bres_prwto(x, K);

    info = anadromi(info[0],info[1],info[2],info[3]);
    return info[3];
}

int main() {

    //Variables
    int N,i,Meres_diakopwn=0,p;

    freopen("longsumk.in", "r",stdin);
    freopen("longsumk.out","w",stdout);
    scanf("%d %d", &N, &K);
    for(i=0;i<N;i++)
    {
        scanf("%d",&p);
        x.push_back(p);
    }
    Meres_diakopwn=bres_meres(x,K);
    printf("%d",Meres_diakopwn);
    
    return 0;
}