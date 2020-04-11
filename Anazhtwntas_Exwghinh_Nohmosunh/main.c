#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    FILE *fin, *fout;
    int a = 0, i, j, k, c = 0;
    char line[64];
    int K = 0, *M, N = 0;
    int dist;
    int *mes, *arr;
    int len1 = sizeof(arr) / sizeof(arr[0]), len2 = sizeof(mes) / sizeof(mes[0]), len3 = sizeof(M) / sizeof(M[0]);

    fin = fopen("seti.in", "r");
    fscanf(fin, "%d\n", &N);
    for(i=0;i<len1;i++) {
        fscanf(fin,"%d",arr[i]);
    }


    arr = (int *) malloc(sizeof(int) * N);
    mes = (int *) malloc(sizeof(int) * N);
    M = (int *) malloc(sizeof(int) * N);


    for (i = 0; i <= len1; i++) {
        for (j = i; j <= len1; i++) {
            if (arr[i] == arr[j]) {
                dist = abs(arr[i] - arr[j]);
                if (dist % 2 == 0) {
                    a = arr[i + dist / 2];
                    if (a / 2 > arr[i]) {
                        *mes = a;
                        for (k = 0; k < len1; k++) {
                            if (arr[k] == a) {
                                c++;
                            }
                        }
                        *M = c;
                        c = 0;
                    }
                }
            } else if (arr[i] != arr[j]) {
                a = 0;
            }
        }
    }

    for (i = 0; i < len2; i++) {
        K++;
    }

    fout = fopen("seti.out", "w");
    fprintf(fout, "%d\n", K);

    for (i = 0; i < len3; i++) {
        if (M[i] > 0) {
            fprintf(fout, "%d\n", M[i]);
        } else {
            fprintf(fout, "\n");
            break;
        }
    }

    free(M);
    free(mes);
    free(arr);

    fclose(fin);
    fclose(fout);
    return 0;
}