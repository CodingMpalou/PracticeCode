#include <stdio.h>

int main() {

    double a = 0, b = 0, *p = 0;
    int c = 0;

    printf("tha emfanisw to dekadiko meros mias double metablhths\n");
    printf("dwse enan dekadiko arithmo:\n");

    scanf("%lf", &a);

    p = &a;

    c = (int) *p;
    b = *p - c;

    printf("to akeraio meros einai:%d\n", c);
    printf("to dekadiko meros einai:%lf\n", b);

    return 0;
}