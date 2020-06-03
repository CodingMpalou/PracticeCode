#include <algorithm>
#include <cstdio>

using namespace std;
int N, c;
vector<int> arr;

int find_max(vector<int> arr, int c){
    int sum=0, prev_sum=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==arr[arr.size()-i-1])break;
        sum=arr[i]+arr[arr.size()-i-1];
        if(sum<prev_sum)
            sum=prev_sum;
        prev_sum=sum;
    }
    if(c>sum)
        sum=c;
    return sum;
}

int main()
{
    freopen("elevator.in","r",stdin);
    freopen("elevator.out","w",stdout);
    scanf("%d",&N);
    for(int p=0,i=0;i<N;i++) {
        scanf("%d", &p);
        arr.push_back(p);
    }
    sort(arr.begin(),arr.end());
    if(N%2==0)
        printf("%.0lf %d", (double)N/2, find_max(arr, c));
    else{
        c=arr[arr.size()-1];
        arr.pop_back();
        printf("%.0lf %d", (double)N/2, find_max(arr, c));
    }

    return 0;
}