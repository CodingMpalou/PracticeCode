#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {

    char line[256];
    int freq[13],i,j,len;
    char delim[]=" \t\n";
    char *token;

    for(i=0;i<12;i++){
        freq[i]=0;
    }

    printf("Dose pinaka alfarithmitikon\n");
    fgets(line,sizeof(line),stdin);
    printf("diavasa to : %s\n",line);

    token=strtok(line,delim);

    while(1) {
        //printf("%s\n", token);
        len = strlen(token);
        //kprintf("to mhkos ths lekshs %s einai :%d\n",token, len);
        freq[len]++;
        token=strtok(NULL,delim);
        if(!token)break;
    }

    printf("word lenght\t|Number of Occurrences\n");
    for(i=1;i<13;i++){
        printf("%d\t|",i);
        for(j=0;j<freq[i];j++)printf("*");
        printf("\n");
    }
    return 0;
}