#include <stdio.h>

#define MAX_DIM 101

int array[MAX_DIM + 1][MAX_DIM + 1];
short v[MAX_DIM + 1][MAX_DIM + 1];
int N, M, K;

int flood(int a, int b) {

    if (a == 0 || a > N || b == 0 || b > N || v[a][b] == 1 || array[a][b] <= M) {
        return 0;
    }

    v[a][b] = 1;
    flood(a + 1, b);
    flood(a - 1, b);
    flood(a, b + 1);
    flood(a, b - 1);

    return 1;
}

int main(void) {
    FILE *fin, *fout;
    fin = fopen("karla.in", "rt");
    fout = fopen("karla.out", "wt");

    fscanf(fin, "%d%d", &N, &M);

    int i, j;
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++)
            fscanf(fin, "%d", &array[i][j]);
    }

    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++) {
            if (flood(i, j) == 1)
                K++;
        }
    }
    fprintf(fout, "%d", K);

    return 0;
}
