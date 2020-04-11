#include <stdio.h>

int main() {

    int *a,*b,*c;
    int z,x,h;

    a=&z;
    b=&x;
    c=&h;

    printf("dwse treis arnhtikous arithmous\n");
    scanf("%d%d%d",a,b,c);


    while( (*a>=0) || (*b>=0) || (*c>=0) )
    {
        printf("OXI THETIKOI, dwse arnhtikous arithmous blaka\n");
        scanf("%d%d%d",a,b,c);
    }

    if(((a-b)==-1) && ((b-c)==-1))){
        printf("einai arnitikoi,diadoxikoi\n");
    }else{
        printf("den einai DIADOXIKOI\n");
    }

    return 0;
}