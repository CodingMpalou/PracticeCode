#include <stdio.h>

int main() {
    int a, b;
    int *c, *d;
    int **cc, **dd;
    int **temp;

    printf("tha antimetathesw tis times duo arithmwn me deiktes se deiktes\n");
    printf("dwse duo times:\n");

    c = &a;
    d = &b;

    cc = &c;
    dd = &d;

    scanf("%d", *cc);
    scanf("%d", *dd);

    temp = cc;
    cc = dd;
    dd = temp;

    printf("h metablhth a egine:%d\n", **cc);
    printf("h mateblhth b egine:%d\n", **dd);

    return 0;
}