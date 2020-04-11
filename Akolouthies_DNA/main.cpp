#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    //Variables
    int N,L=0,M,i;

    //In File
    FILE *fi = fopen("dnaseq.in","r");
    fscanf(fi,"%ld", &N);
    char A[N], B[N];
    fscanf(fi,"%s", A);
    fscanf(fi,"%s", B);
    fclose(fi);

    //Main
    while(A[L]==B[L] && L<=N)
        L++;
    L++;

    M=N-1;
    while(A[M]==B[M] && M>=0)
        M--;
    M++;

    i=L;
    while(A[i]==B[M+L-i] && i<=M)
        i++;

    //Out File
    FILE *fo= fopen("dnaseq.out","w");
    if(L+i==M)
        fprintf(fo, "%d", M - L);
    if(M==0 && L==M+i)
        fprintf(fo, "%d", 0);
    else
        fprintf(fo, "%s", "no");
    fclose(fo);

    return 0;
}