#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    int T,N;
    vector<int> res;

    FILE *fi=fopen("input","r");
    FILE *fo=fopen("output","w");
    fscanf(fi,"%d",&T);
    for(int t=0;t<T;t++){
        fscanf(fi,"%d",&N);
        int arr[N];
        for(int n=0;n<N;n++)
            fscanf(fi, "%d", &arr[n]);
        sort(arr,arr+N);
       for(int i=0;i<N;i++){
           res.push_back(arr[i]);
           res.push_back(arr[N-i-1]);
       }
       reverse(res.begin(),res.begin()+N);
       for(int j=0;j<N;j++)
           fprintf(fo, "%d", res[j]);
       fprintf(fo,"\n");
       res.clear();
    }
    fclose(fi);
    fclose(fo);
    return 0;
}