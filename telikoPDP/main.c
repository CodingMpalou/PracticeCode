/* USER: u015
LANG: C
TASK: hydrocarbons */
#include <stdio.h>
#include <stdlib.h> //qsort
#include <string.h> //strtok , atoi
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
    int *a, *b, *c, *e;
    double *d;
    char *token;

    fin = fopen("hydrocarbons.in", "r");

    if (!fin) {
        perror("fopen hydrocarbons.in");
    }

    fscanf(fin, "%d", &N); //Διαβάζω το N που βρίσκεται στη πρώτη γραμμή

    a = (int *) malloc(sizeof(int) * N); //Δυναμική δέσμευση πίνακα για απολήψιμη
    b = (int *) malloc(sizeof(int) * N); //ομοίως για βάθος
    c = (int *) malloc(sizeof(int) * N); //ομοίως για φρεάτια
    d = (double *) malloc(sizeof(double) * N); //αποδοτικότητα
    e = (int *) malloc(sizeof(int) * N); //αρχική θέση κάθε στοιχείου

    /*Διάβασμα γραμμή ανα γραμμή μετατροπή και αποθήκευση στους πίνακες */
    while (fgets(line, sizeof(line), fin)) {

        if (i == -1) {
            i++;
            continue;
        }

        token = strtok(line, " ");
        a[i] = atoi(token);

        token = strtok(NULL, " ");
        b[i] = atoi(token);

        token = strtok(NULL, " ");
        c[i] = atoi(token);

        d[i] = a[i] - a[i] * ((double) b[i] / 3000) - (double) c[i] * a[i] / 40; // υπολογισμός αποδοτικότητας κάθε θαλάσσιου οικοπέδου
        if (d[i] > 0)counter++;

        e[i] = i + 1;
        i++;

    }

    quickSort(e, d, 0, N - 1); //ταξινόμηση του πίνακα αποδοτικότητας παράλληλα με του πίνακα με τις θέσεις
    fout = fopen("hydrocarbons.out", "w");

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

    free(a);
    free(b);
    free(c);
    free(d);
    free(e);

    fclose(fin);
    fclose(fout);

    return 0;
}
