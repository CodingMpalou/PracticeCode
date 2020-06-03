#include <cstdio>
int N, K;

int elegxos(int mid){
    int i=0;
    while(i<N){

    }

}

/*
 * int elegxos(int mid){
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
 */
int main() {
    freopen("cubes.in", "r", stdin);
    freopen("cubes.out", "w", stdout);
    scanf("%d %d", &N, &K);

    int beg=0, end=1e5, mid;
    while (beg<end){
        mid=(beg+end)/2;
        if(elegxos(mid)) end=mid;
        else beg=mid+1;
    }
    printf("%d",beg);
    return 0;
}