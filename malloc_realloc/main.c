#include <stdlib.h>
#include <stdio.h>

int main() {
    int *b;
    int n, i;


    printf("dwse ton arithmo twn thesewn tou pinaka\n");
    scanf("%d", &n);

    /* Initial memory allocation */
    b = (int *) malloc(n * sizeof(int));

    /* Reallocating memory */
    //b = (int *) realloc(b, n * 2 * sizeof(int));


    for (i = 0; i < n; i++) {
        printf("dwse thn %dh thesh tou pinaka\n", i + 1);
        scanf("%d", (b + i));

    }
    printf("oi arithmoi einai:\n");

    for (i = n - 1; i >= 0; i--)
    {
        printf("%d\n", *(b + i));
    }

    free(b);
    return 0;
}
