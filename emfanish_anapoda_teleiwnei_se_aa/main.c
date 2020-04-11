#include <stdio.h>
#include <string.h>

    int main() {

    char str[100],temp;
    char a,b;
    int i,j;

    printf("An teleiwnei se aa to string tha to emfanizw antistrofa\n");

    fgets(str,sizeof(str),stdin);
    fflush(stdin);

    int len=sizeof(str);

    a = str[strlen(str)-1];
    b = str[strlen(str)-2];

    if(a=='a' && b=='a') {
        for (i = 0; i < len; i++) {
            for (j = 0; j < len - 1 - i; j--) {
                temp=str[i];
                str[i] = str[j+1];
                str[j + 1] = temp;
            }
        }
    }

    printf("%s\n",str);

    return 0;
}