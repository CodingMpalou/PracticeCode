#include <bits/stdc++.h>

using namespace std;

int main() {
    int N,sum=0;
    freopen("goldbach.in","w",stdin);
    freopen("goldbach.out","r",stdout);
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        if(N%i!=0 && N%(N-i)!=0){
            cout<<i<<" "<<N-1;
            if(sum==N)
                printf("%d %d", i, N-i);
            sum=i+N-i;
        }
    }
    return 0;
}