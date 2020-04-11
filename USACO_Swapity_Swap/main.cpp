#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    //Variables
    int N,K,i,p;
    vector<int>A,B,nums;

    //In File
    FILE *fi=fopen("swap.in","r");
    fscanf(fi,"%d",&N);
    fscanf(fi,"%d",&K);
    for(i=0;i<2;i++)
    {
        fscanf(fi,"%d",&p);
        A.push_back(p);
    }
    for(i=0;i<2;i++)
    {
        fscanf(fi,"%d",&p);
        B.push_back(p);
    }
    fclose(fi);

    //Main
    for(i=0;i<N;i++)
        nums.push_back(i + 1);

    for(i=0;i<K;i++)
    {
        reverse(nums.begin() + A[0] - 1, nums.begin() + A[1]);
        reverse(nums.begin() + B[0] - 1, nums.begin() + B[1]);
    }

   //Out File
    FILE *fo=fopen("swap.out","w");
    for(i=0;i<nums.size();i++)
        fprintf(fo,"%d\n",nums[i]);
    fclose(fo);

    return 0;
}