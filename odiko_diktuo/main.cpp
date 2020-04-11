#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <iterator>

using namespace std;

vector<int> elegxos_grammhs(vector<vector<int>> matrix, int N){
    int i, j, k, g, idx;
    vector<int> s;

    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(matrix[i][j]==1)
            {
                s.push_back(i);
                s.push_back(j);
                idx=j;
                break;
            }
        }
    }

    for(i=0;i<N;i++)
    {
        if(i==idx) {
            for (j=0;j<N;j++)
            {
                if(matrix[i][j]==1)
                {
                    s.push_back(j);
                    break;
                }
            }
        }
    }

    return s;
}

int main() {

    //Variables
    int N, M, K;
    long long S=0, final;
    vector<int> A, B, s;
    int i, j, a, b;
    vector<vector<int>> matrix;

    //InFile
    FILE *fi= fopen("villages.in", "r");
    fscanf(fi, "%d %d %d", &N, &M, &K);
    for(i=0;i<M;i++)
    {
        fscanf(fi, "%d %d", &a, &b);
        A.push_back(a);
        B.push_back(b);
    }
    fclose(fi);

    //Main
    for(i=0;i<N;i++)
    {
        matrix.push_back(*new vector<int>);
        for(j=0;j<N;j++)
            matrix[i].push_back(0);
    }

    for(i=0;i<M;i++)
        matrix[A[i]][B[i]]=1;

    s=elegxos_grammhs(matrix, N);

    for(i=0;i<s.size();i++)
        cout<<s[i]<<" ";

    S=s.size()/2;

    final=S-K;
    //OutFile
    FILE *fo = fopen("villages.out", "w");
    fprintf(fo, "%d", final);
    fclose(fo);

    return 0;
}