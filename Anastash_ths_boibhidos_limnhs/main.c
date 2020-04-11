#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main() {
    int N, M;  //eisodos
    int K = 0;  //exodos
    int i, j;  //gia epanalhpseis
    FILE *fin, *fout;  //gia ta files
    fin = fopen("karla.in", "r");
    fscanf(fin, "%d %d\n", &N, &M);  //dinei sthn eisodo to N kai to M

    int x[N][N]; // 2D pinakas

    for (i = 0; i <= N; i++) {
        for (j = 0; j <= N; j++) {
            fscanf(fin, "%d", &x[i][j]);    //dinei sthn eisodo ton 2D pinaka
        }
        fprintf(fin, "\n");
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (x[i][j] == M || x[i][j] < M) {
                x[i][j] = 0;      //kanei 0 auta pou einai isa h mikrotera apo to M
            } else if (x[i][j] != 0) {
                x[i][j] = 0;
                if (x[i][j + 1] != 0 && x[i][j - 1] != 0 && x[i - 1][j] != 0 && x[i + 1][j] != 0) {
                    x[i][j + 1] = 0;
                    x[i][j - 1] = 0;
                    x[i - 1][j] = 0;
                    x[i + 1][j] = 0;
                    K++;
                } else if (x[i][j + 1] != 0 && x[i][j - 1] != 0 && x[i - 1][j] != 0) {
                    x[i][j - 1] = 0;
                    x[i - 1][j] = 0;
                    x[i][j + 1] = 0;
                    K++;
                } else if (x[i][j + 1] != 0 && x[i][j - 1] != 0 && x[i + 1][j] != 0) {
                    x[i][j - 1] = 0;
                    x[i][j + 1] = 0;
                    x[i + 1][j] = 0;
                    K++;
                } else if (x[i - 1][j] != 0 && x[i + 1][j] != 0) {
                    x[i - 1][j] = 0;
                    x[i + 1][j] = 0;
                    K++;
                } else if (x[i][j - 1] != 0 && x[i][j + 1] != 0) {
                    x[i][j - 1] = 0;
                    x[i][j + 1] = 0;
                    K++;
                } else if (x[i][j - 1] != 0) {
                    x[i][j - 1] = 0;
                    K++;
                } else if (x[i][j + 1] != 0) {
                    x[i][j + 1] = 0;
                    K++;
                } else if (x[i][j + 1] != 0 || x[i - 1][j] != 0) {
                    x[i][j + 1] = 0;
                    x[i - 1][j] = 0;
                    K++;
                } else if (x[i][j + 1] != 0 || x[i + 1][j] != 0) {
                    x[i][j + 1] = 0;
                    x[i + 1][j] = 0;
                    K++;
                } else if (x[i][j - 1] != 0 || x[i + 1][j] != 0) {
                    x[i][j - 1] = 0;
                    x[i + 1][j] = 0;
                    K++;
                } else if (x[i][j - 1] != 0 || x[i - 1][j] != 0) {
                    x[i][j - 1] = 0;
                    x[i - 1][j] = 0;
                    K++;
                }
            }
        }
    }

    fout = fopen("karla.out", "w");
    fprintf(fout, "%d", K);      //dinei to K sthn exodo

    return 0;
}