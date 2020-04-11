#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//int main()
//{
//    char name[50];
//    int marks, i, num;
//
//    printf("Enter number of students: ");
//    scanf("%d", &num);
//
//    FILE *fptr;
//    fptr = fopen("student.txt", "w"); //otan vazw w , diagrafei oti ehei to arhheio kai ta grafei apo arxi , ΕΝΩ όταν είανι a , ta kanei append( tta prothetei apo kato)
//    if(fptr == NULL)
//    {
//        printf("Error!");
//        exit(1);
//    }
//
//    for(i = 0; i < num; ++i)
//    {
//        printf("For student%d\nEnter name: ", i+1);
//        scanf("%s", name);
//
//        printf("Enter marks: ");
//        scanf("%d", &marks);
//
//        fflush(stdin);
//        fprintf(fptr,"name: %s Marks=%d \n", name,marks);
//    }
//
//    fclose(fptr);
//    return 0;
//}

#define bufSize 1024

int main(int argc, char *argv[])
{
    //a απολήψιμη ποσότητα
    //b βάθος
    //c αριθμός φρεατίων
    //αποδοτικότητα επένδυσης (a-a(b/3000)-c*a/40)

    FILE* fp;
    char buf[bufSize];
    if (argc != 2)
    {
        fprintf(stderr,
                "Usage: %s <soure-file>\n", argv[0]);
        return 1;
    }
    if ((fp = fopen(argv[1], "r")) == NULL)
    { /* Open source file. */
        perror("fopen source-file");
        return 1;
    }

    while (fgets(buf, sizeof(buf), fp) != NULL)
    {
        buf[strlen(buf) - 1] = '\0'; // eat the newline fgets() stores
        printf("%s\n", buf);
    }
    fclose(fp);
    return 0;
}