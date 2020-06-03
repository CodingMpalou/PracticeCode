#include <cstdio>
#include <algorithm>
#include <cstring>

int N, nSize=0;
char car[1000000][45];
int help[1000000];

bool compare(int a, int b)
{
    return strcmp(car[a],car[b])<0;
}

int main()
{
    freopen("boat.in","r",stdin);
    freopen("boat.out","w",stdout);
    scanf("%d",&N);
    for (int out,in, i=0; i<N; i++)
    {
        scanf("%d%d",&out,&in);
        nSize -= out;
        for (int j=0; j<in; j++) scanf("%s",car[nSize++]);
    }
    for (int i=0; i<nSize; i++) help[i] = i;
    std::sort(help,help+nSize,compare);
    for (int i=0; i<nSize; i++) printf("%s\n",car[help[i]]);
}