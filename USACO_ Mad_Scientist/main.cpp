#include <iostream>
#include <vector>
#include <string>

using namespace std;

int min_num_machine(string A, string B){
    int res;

    for(int i=0;i<A.size();i++)
    {
        if(A[i]!=B[i] && A[i+1]==B[i+1])
            res++;
    }

    return res;
}

int main() {

    //Variables
    int N,i,res;
    char ch;
    string A,B;

    //In File
    FILE *fi=fopen("breedflip.in","r");
    fscanf(fi,"%d",&N);
    fscanf(fi,"%c",&ch);
    for(i=0;i<N;i++)
    {
        fscanf(fi,"%c",&ch);
        A.push_back(ch);
    }
    fscanf(fi,"%c",&ch);
    for(i=0;i<N;i++)
    {
        fscanf(fi,"%c",&ch);
        B.push_back(ch);
    }
    fclose(fi);

    //Main
    res=min_num_machine(A,B);

    //Out File
    FILE *fo=fopen("breedflip.out","w");
    fprintf(fo,"%d",res);
    fclose(fo);
    return 0;
}