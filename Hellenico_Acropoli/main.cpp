#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
const long MAXN = 1005;
int N, arr[MAXN], arr2[MAXN], c;

int main() {
    freopen("acropolis.in","r",stdin);
    freopen("acropolis.out","w",stdout);
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d", &arr[i]);
        arr2[i]=arr[i];
    }
    sort(arr2,arr2+N);
    for(int i=0;i<N;i++){
         if (arr[i] == 1) continue;
         for (int j = 0; j < N; j++) {
             if (arr2[j] != 1) {
                 arr[i] = arr2[j];
                 arr2[j]=1;
                 break;
             }
         }
    }
    for(int i=0;i<N;i++)
        cout<<arr[i]<<endl;

    return 0;
}