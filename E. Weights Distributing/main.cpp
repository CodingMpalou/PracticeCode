#include <bits/stdc++.h>
using namespace std;
const long MAXN = 200000;
const int INF = 0x3f3f3f3f;

int N, T, M, a, b, c, sum, q[MAXN+5], par[MAXN+5], dist[MAXN+5], p[MAXN+5];
vector<int> A[MAXN+5], w[MAXN+5];

int main () {
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    scanf("%d", &T);
    for(int t=0;t<T;t++)
    {
        scanf("%d %d %d %d %d",&N, &M, &a, &b, &c);
        for(int m=0;m<M;m++)
            scanf("%d",&p[m]);
        for(int i=1; i<=M; ++i) {
            int u1,u2;
            scanf("%d %d", &u1, &u2);
            A[u1].push_back(u2);
            A[u2].push_back(u1);
            w[u1].push_back(p[i]);
            w[u2].push_back(p[i]);
      }
        for(int i=1; i<=N; ++i) {
            dist[i] = INF;
            par[i] = -1;
        }
        dist[1] = 0;
        par[1] = 0;
        int size = 1;
        q[1] = 1;

        while (size > 0) {
            int pos=1, currMin = q[1];
            for(int i=2; i<=size; ++i) {
                int curr = q[i];
                if ( dist[curr] < dist[currMin] ) {
                    currMin = curr;
                    pos = i;
                }
            }
            for(int i=0; i<A[currMin].size(); ++i) {
                int neib = A[currMin][i], weight = w[currMin][i];
                if ( dist[neib] == INF ) {
                    q[size+1] = neib;
                    size++;
                }
                if ( dist[neib] > weight ) {
                    dist[neib] = dist[currMin] + weight;
                    par[neib] = currMin;
                }
            }

            swap( q[pos], q[size] );
            size--;
        }
        for(int i=1; i<=N; ++i) {
            sum+=dist[i];
        }
        printf("%d\n",sum);
    }
  return 0;
}