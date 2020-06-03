#include <bits/stdc++.h>
using namespace std;
int N,A,B,C,D;
int main() {
    int a=0,b=0,c=0,d=0;
    freopen("tickets.in","r",stdin);
    freopen("tickets.out","w",stdout);
    scanf("%d", &N);
    scanf("%d %d %d %d", &A, &B, &C, &D);
    N*=10;
    if(N/10>=A)
        a = (N - (N * 0.1));
    if(N/10<A)
        a = ((A*10) - ((A*10) * 0.1));
    if(N/10>=B)
        b = (N - (N * 0.2));
    if(N/10<B)
        b = ((B*10) - ((B*10) * 0.2));
    if(N/10>=C)
        c = (N - (N * 0.3));
    if(N/10<C)
        c = ((C*10) - ((C*10) * 0.3));
    if(N/10>=D)
        d = (N - (N * 0.5));
    if(N/10<D)
        d = ((D*10) - ((D*10) * 0.5));
    vector<int> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);
    int min=v[0];
    for(int i=0;i<v.size();i++){
        if(min>v[i])
            min=v[i];
    }
    printf("%d", min);
   return 0;
}