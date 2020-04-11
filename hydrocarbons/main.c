/* USER: u015
LANG: C
TASK: hydrocarbons */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int partition(int e[], double d[], int low, int high) {
    double pivot = d[high];
    int i = (low - 1);
    int temp;
    double temp1;

    for (int j = low; j <= high - 1; j++) {

        if (d[j] > pivot) {
            i++;

            temp = e[i];
            e[i] = e[j];
            e[j] = temp;
            temp1 = d[i];
            d[i] = d[j];
            d[j] = temp1;
        } else if (d[j] == pivot) {
            if (e[j] < e[i]) {
                i++;

                temp = e[i];
                e[i] = e[j];
                e[j] = temp;
                temp1 = d[i];
                d[i] = d[j];
                d[j] = temp1;
            }
        }

    }
    temp = e[i + 1];
    e[i + 1] = e[high];
    e[high] = temp;
    temp1 = d[i + 1];
    d[i + 1] = d[high];
    d[high] = temp1;
    return (i + 1);
}


void quickSort(int e[], double d[], int low, int high) {
    if (low < high) {

        int pi = partition(e, d, low, high);

        quickSort(e, d, low, pi - 1);
        quickSort(e, d, pi + 1, high);
    }
}

int main(int argc, char *argv[]) {
    FILE *fin, *fout;
    char line[64];
    int N, counter = 0;
    int i = -1;
    int a, b, c, *e;
    double *d;
    char *token;

    double msec=0;

    clock_t before,difference;
    before = clock();

    fin = fopen("hydrocarbons.in", "r");

    if (!fin) {
        perror("fopen hydrocarbons.in");
    }

    fscanf(fin, "%d", &N); //Διαβάζω το N που βρίσκεται στη πρώτη γραμμή

    d = (double *) malloc(sizeof(double) * N); //δυναμική δέσμευση μνήμης για την αποδοτικότητα κάθε οικοπέδου
    e = (int *) malloc(sizeof(int) * N); //αρχική θέση κάθε οικοπέδου στο αρχείο εισόδου

    /*Διάβασμα γραμμή ανα γραμμή μετατροπή και αποθήκευση στους πίνακες */
    while (fgets(line, sizeof(line), fin)) {

        if (i == -1) {
            i++;
            continue;
        }

        token = strtok(line, " ");
        a = atoi(token);

        token = strtok(NULL, " ");
        b = atoi(token);

        token = strtok(NULL, " ");
        c = atoi(token);

        d[i] = a - a * ((double) b / 3000) - (double) c * a/ 40; // υπολογισμός αποδοτικότητας κάθε θαλάσσιου οικοπέδου
        if (d[i] > 0)counter++;

        e[i] = i + 1;
        i++;

    }

    quickSort(e, d, 0, N - 1); //ταξινόμηση του πίνακα αποδοτικότητας παράλληλα με του πίνακα με τις αρχικές θέσεις
    fout = fopen("hydrocarbons.out", "w");

    /*εγγραφή αποτελεσμάτων στο αρχείο εξόδου*/

    fprintf(fout, "%d\n", counter);
    if (counter) {
        for (i = 0; i < N; i++) {
            if (d[i] > 0) fprintf(fout, "%d ", e[i]);
            else {
                fprintf(fout, "\n");
                break;
            }
        }
    }

    free(d);
    free(e);

    fclose(fin);
    fclose(fout);
    difference = clock() - before;
    msec = difference * 1000 / CLOCKS_PER_SEC;
    printf("synolika :%fs\n",msec/1000);

    return 0;
}
