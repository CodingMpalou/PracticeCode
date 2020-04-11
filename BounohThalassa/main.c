//pdp 01
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {

    int i;
    char *str;
    char trash;
    int c = 0, counter = 0;
    unsigned int N;
    FILE *fin, *fout;

    fin = fopen("mntsea.in", "r");

    fscanf(fin, "%d", &N);
    str = (char *) malloc(sizeof(char) * N);

    printf("to N einai :%d\n", N);
    trash = getc(fin);

    fgets(str, sizeof(char) * N, fin);

    for (i = 0; i <= N + 5; i++) {
        printf("%c", *(str + i));
    }


//    while (fgets(str, sizeof(char) * N, fin)){
//        printf("%s",str);
//        if(c==0){
//            c=1;
//            continue;
//        }
//        break;
//    }

    printf("%s", str);
    //printf("%s\n",str);

    for (i = 0; i < N - 1; i++) {
        if (str[i] != str[i + 1]) {
            counter++;
        }
    }

    for (i = 0; i < N - 1; i++) {
        if (str[i] != str[i + 1]) {
            if (str[i + 1] != str[i + 2]) {
                counter++;
            }
        }
    }

    fout = fopen("mntsea.out", "w");
        fprintf(fout, "%d\n",counter);

        free(str);
    return 0;
}