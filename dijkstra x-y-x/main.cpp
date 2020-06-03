#include <bits/stdc++.h>
using namespace std;
const long MAXN = 50000;
const int INF = 0x3f3f3f3f;

int N, M, dist[MAXN+5], dist2[MAXN+5];
vector<int> A[MAXN+5], A2[MAXN+5], w[MAXN+5], w2[MAXN+5], num_q;

int main () {
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    scanf("%d %d", &M, &N);
    for(int i=1; i<=M; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        A2[b].push_back(a);
        w2[b].push_back(c);
        A[a].push_back(b);
        w[a].push_back(c);
    }
    int x, y, Q;
    scanf("%d %d", &x, &y);
    scanf("%d", &Q);
    for(int i=0;i<Q;i++){
        int z;
        scanf("%d", &z);
        num_q.push_back(z);
    }
    set< pair<int,int> > q;
    for(int i=1; i<=N; ++i)
        dist[i] = INF;
    dist[x] = 0;
    q.insert ({0,x});

    while (q.size() > 0) {
        int currMin = q.begin()->second;
        for(int i=0; i<A[currMin].size(); ++i) {
            int neib = A[currMin][i], weight = w[currMin][i];
            if ( dist[neib] > dist[currMin] + weight ) {
                if ( q.find( {dist[neib], neib} ) != q.end() ) {
                    q.erase( q.find({dist[neib],neib}) );
                }
                q.insert( {dist[currMin] + weight,neib} );
                dist[neib] = dist[currMin] + weight;
            }
        }
        q.erase ( q.begin() );
    }
/*
    for(int i=0;i<N;i++){
        for(int j=0;j<A[i].size();j++){
            //Start i - End A[i][j], w[i][j]
            A2[A[i][j]].push_back(i);
            w2[A[i][j]].push_back(w[i][j]);
        }
    }
*/
    for(int i=1; i<=N; ++i)
        dist2[i] = INF;
    dist2[y] = 0;
    q.insert ({0,y});

    while (q.size() > 0) {
        int currMin = q.begin()->second;
        for(int i=0; i<A2[currMin].size(); ++i) {
            int neib = A2[currMin][i], weight = w2[currMin][i];
            if ( dist2[neib] > dist2[currMin] + weight ) {
                if ( q.find( {dist2[neib], neib} ) != q.end() ) {
                    q.erase( q.find({dist2[neib],neib}) );
                }
                q.insert( {dist2[currMin] + weight,neib} );
                dist2[neib] = dist2[currMin] + weight;
            }
        }
        q.erase ( q.begin() );
    }

    for(int i=0;i<Q;i++){
        if(dist[num_q[i]]+dist2[num_q[i]]==dist[y])
           printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}