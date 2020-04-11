#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    int i;
    int a,b,c;
    srand(time(NULL));
    fp=fopen("hydrocarbons.in","w");
    fprintf(fp,"%d\n",100000);
    for(i=0;i<100000;i++){
        a =rand()%1000000000+1;
        b=rand()%1000+2000;
        c=rand()%40+1;
        fprintf(fp,"%d %d %d\n",a,b,c);
    }
}