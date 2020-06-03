#include <bits/stdc++.h>
using namespace std;
int N;

int check(int num){
    int c=1;
    for(int i=2;i<=num/2;i++){
        if(num%i==0) {
            c=0;
            break;
        }
    }
    return c;
}

int main() {
    int c;
    freopen("goldbach.in","r",stdin);
    freopen("goldbach.out","w",stdout);
    scanf("%d",&N);
    for(int i=2;i<=N/2;i++){
        c=check(i);
        if(c==1){
            c=check(N-i);
            if(c==1){
                if(i+(N-i)==N){
                    cout<<i<<" "<<N-i;
                    break;
                }
            }
        }
    }
    return 0;
}