#include <iostream>

using namespace std;

int main() {
    long N,M;
    FILE *fi = fopen("inFile", "r");
    fscanf(fi, "%ld %ld", &N, &M);
    fclose(fi);

    FILE *fo = fopen("outFile", "w");
    fprintf(fo, "%d", N+M);
    fclose(fo);

   return 0;
}