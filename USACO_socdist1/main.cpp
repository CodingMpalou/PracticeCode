#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main() {

    //Variables
    int N,i,c,MAX1=0,MAX2=0,MIN=10000000;
    char ch;
    vector<int> D;

    //In File
    FILE *fi=fopen("socdist1.in","r");
    fscanf(fi,"%d",&N);

    fscanf(fi,"%c",&ch);

    fscanf(fi,"%c",&ch);

    ch == '0' ? c=1 : c=0;
    for(i=1;i<N;i++)
    {
        fscanf(fi,"%c",&ch);
        if(ch=='0') c++;
        if(i>1 && ch=='1') {
            D.push_back(c+1);
            if(MAX1<c+1) {
                MAX2=MAX1;
                MAX1=c+1;
            }
            else if(MAX2<c+1)
                MAX2=c+1;
            if(MIN>c+1)
                MIN=c+1;
            c=0;
        }
    }
    if (ch=='0') {
        D.push_back(c + 1);
        if(MAX1<c+1) {
            MAX2=MAX1;
            MAX1=c+1;
        }
        else if(MAX2<c+1)
            MAX2=c+1;
        if(MIN>c+1)
            MIN=c+1;
    }
    //Main
    int res,d=MIN;
    MAX1/=2;
    (MAX1>MAX2) ? res = (MAX1+1)/2 : res=MAX2/2;
    if(res>d) res = d;
    if(res==0) res=1;

    //Out File
    FILE *fo=fopen("socdist1.out","w");
    fprintf(fo,"%d",res);
    fclose(fo);

    return 0;
}