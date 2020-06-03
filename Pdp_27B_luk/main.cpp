#include <cstdio>

const long MAXN=1000005;
int N, V[MAXN];

int elegxos(int mid){
    int i=0, sum=0, brother=0;
    while(i<N && brother<3)
        if (sum+V[i]>mid)
        {
            brother++;
            sum = 0;
        }
        else sum+=V[i++];
    return i==N;
}

int main() {
    freopen("share.in", "r", stdin);
    freopen("share.out", "w", stdout);
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &V[i]);

    int beg=0, end=1e9, mid;
    while (beg<end){
        mid=(beg+end)/2;
        if(elegxos(mid)) end=mid;
        else beg=mid+1;
    }
    printf("%d",beg);
    return 0;
}