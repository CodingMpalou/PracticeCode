#include <stdio.h>
#include <stdlib.h> //qsort
#include <string.h> //strtok , atoi
#include <time.h>

int partition(int e[],double d[], int low, int high)
{
    double pivot = d[high]; // pivot
    int i = (low - 1); // Index of smaller element
    int temp;
    double temp1;

    for (int j = low; j <= high - 1; j++) {

        // If current element is smaller than
        // or equal to pivot. This means are
        // sorting sequence condition fails if
        // the condition becomes true. Thus the
        // two indices which shall be obtained
        // here will be i and j and therefore
        // we will be swapping values of i and j
        // in all the arrays.
        if (d[j] > pivot ) {

            // increment index of smaller element
            i++;

            // Swapping values of i and j in
            // all the arrays
            temp = e[i];
            e[i] = e[j];
            e[j] = temp;
            temp1 = d[i];
            d[i] = d[j];
            d[j] = temp1;
        }else if(d[j]==pivot){
            if(e[j]<e[i]){
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

// Function which implements quick sort
void quickSort(int e[],double d[], int low, int high)
{
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(e,d, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(e, d,low, pi - 1);
        quickSort(e, d, pi + 1, high);
    }
}

int main(int argc, char *argv[]) {
    FILE *fin,*fout;
    char line[64];
    int N,j,temp2,counter=0;
    int i=-1;
    int *a,*b,*c,*e;
    double *d,temp;
    char *token;
    clock_t before,difference;
    before = clock();
    float msec = 0;

    fin=fopen("hydrocarbons1.in","r"); //an einai to arheio ston idio fakelo me to ektelesimo

    if(!fin){//tha mpei an de vrei to arheio
        perror("fopen hydrocarbons.in");
    }

    fscanf(fin,"%d",&N); //Διαβάζω το N που βρίσκεται στη πρώτη γραμμή
    printf("tha diavaso %d freatia\n",N);

    a=(int*)malloc(sizeof(int)*N);
    b=(int*)malloc(sizeof(int)*N);
    c=(int*)malloc(sizeof(int)*N);
    d=(double*)malloc(sizeof(double)*N);
    e=(int*)malloc(sizeof(int)*N);

    while (fgets(line,sizeof(line),fin)) {

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

        d[i] = a[i] - a[i] * ((double)b[i] / 3000) - (double)c[i] * a[i] / 40; // 2000/3000 = 0.66
        if(d[i]>0)counter++;

        e[i]=i+1;
        i++;

    }

//    difference = clock() - before;
//    msec = difference * 1000 / CLOCKS_PER_SEC;
//    printf("diavasma-desmeusi :%fs\n",msec/1000);
//
//    before= clock();

//    for (i = 0; i < N; i++) {
//        for (j = 0; j < N -i- 1; j++ ) {
//
//            if (d[j] < d[j + 1]) {
//                temp = d[j];
//                d[j] = d[j + 1];
//                d [j+1] = temp;
//                temp2=e[j];
//                e[j]=e[j+1];
//                e[j+1]=temp2;
//            }else if(d[j]==d[j+1]){
//                if (e[j]>e[j+1]){
//                    temp = d[j];
//                    d[j] = d[j + 1];
//                    d [j+1] = temp;
//                    temp2=e[j];
//                    e[j]=e[j+1];
//                    e[j+1]=temp2;
//                }
//            }
//        }
//    }


//    difference = clock() - before;
//    msec = difference * 1000 / CLOCKS_PER_SEC;
//    printf("bs:%fs\n",msec/1000);


//    before = clock();

//    printf("%.30lf\n",d[63331]);
//    printf("%.30lf\n",d[10768]);
//    if(d[63331]==d[10768]){
//        printf("mikrotero\n");
//    }

    quickSort(e,d,0,N-1);
    fout=fopen("hydrocarbons.out","w");

    fprintf(fout,"%d\n",counter);
    for(i=0;i<N;i++){
        if(d[i]>0) fprintf(fout,"%d  %.30f\n",e[i],d[i]);
        else break;
    }


    free(a);
    free(b);
    free(c);
    free(d);
    free(e);

    fclose(fin);
    fclose(fout);

    difference = clock() - before;
    msec = difference * 1000 / CLOCKS_PER_SEC;
    printf("SYNOLIKA:%fs\n",msec/1000);
    return 0;
}

