#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMinimumOps(vector<int> ar)
{
    int n = ar.size();
    int small = *min_element(ar.begin(), ar.end());
    int large = *max_element(ar.begin(), ar.end());
    int dp[n][large + 1];

    for (int j = small; j <= large; j++)
        dp[0][j] = abs(ar[0] - j);

    for (int i = 1; i < n; i++)
    {
        int minimum = INT_MAX;
        for (int j = small; j <= large; j++)
        {
            minimum = min(minimum, dp[i - 1][j]);
            dp[i][j] = minimum + abs(ar[i] - j);
        }
    }
    int ans = INT_MAX;
    for (int j = small; j <= large; j++)
        ans = min(ans, dp[n - 1][j]);

    return ans;
}

int main()
{
    int T,N,p,res;
    vector<int> a;

    FILE *fi=fopen("input","r");
    FILE *fo=fopen("output","w");
    fscanf(fi,"%d",&T);
    for(int t=0;t<T;t++)
    {
        fscanf(fi,"%d",&N);
        for(int n=0;n<N;n++)
        {
            fscanf(fi,"%d",&p);
            a.push_back(p);
        }
        res=getMinimumOps(a);
        fprintf(fo,"%d\n",res);
        a.clear();
    }
    fclose(fi);
    fclose(fo);

    return 0;
}