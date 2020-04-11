/* USER: emmanouil
LANG: C
TASK: hydrocarbons */

#include <stdio.h>
#include <stdlib.h> //qsort
#include <string.h>
#include <time.h>

int compare(const void *s1,const void *s2);

typedef struct oikopedo{
    int ap,ba,fr;
    double apod;
    int pos;
}oikopedo;

int main() {
    //απολήψιμη ποσότητα a , 1 ≤ ai ≤ 1.000.000.000
    //βάθος b , 1 ≤ bi ≤ 3.000
    //αριθμός φρεατίων c , 1 ≤ ci ≤ 40
    //αποδοτικότητα επένδυσης
    //(a-a(b/3000)-c*a/40)>0 ? 1 : 0

    FILE *fp,*fout;
    fp=fopen("hydrocarbons.in","r");
    fout=fopen("hydrocarbons.out","w");

    const int N;
    char line[64];
    char* token ;
    int counter=0;
    float msec=0;

    clock_t before,difference;


    if(!fp || !fout){
        printf("de vrika arheio");
        return 1;
    }

    fscanf(fp,"%d",&N);
    printf("N=%d\n",N);

    oikopedo *arr=malloc(N*sizeof(oikopedo));

//    ap=(float*)malloc(N*sizeof(float));
//    ba=(float*)malloc(N*sizeof(float));
//    fr=(float*)malloc(N*sizeof(float));
    int i=-1;
    while (fgets(line, sizeof(line), fp)) {
        if(i==-1){
            i++;
            continue;
        }
        token=strtok(line," ");
        arr[i].ap=atoi(token);

        token=strtok(NULL," ");
        arr[i].ba=atoi(token);

        token=strtok(NULL," ");
        arr[i].fr=atoi(token);

        arr[i].pos=i+1;

        i++;
    }

    for(i=0;i<N;i++) {
        arr[i].apod=arr[i].ap - arr[i].ap*((float)arr[i].ba/3000)-(float)arr[i].fr*arr[i].ap/40;
        if(arr[i].apod>0)counter++;
        //printf("i=%d\ta=%d\tb=%d\tc=%d\t%f\n",arr[i].pos, arr[i].ap, arr[i].ba, arr[i].fr,arr[i].apod);
    }

    printf("\n");

    before = clock();

    qsort(arr,N,sizeof(struct oikopedo),compare);

    difference = clock() - before;
    msec = difference * 1000 / CLOCKS_PER_SEC;
    printf("qsort:%fs\n",msec/1000);

    fprintf(fout,"%d\n",counter);
    for(i=0;i<N;i++) {
        if(arr[i].apod>0) {
            fprintf(fout, "%d  %.15f\n", arr[i].pos,arr[i].apod);
            //printf("i=%d\ta=%d\tb=%d\tc=%d\tapod=%f\n", arr[i].pos, arr[i].ap, arr[i].ba, arr[i].fr, arr[i].apod);
        }else {
            break;
        }
    }

    free(arr);
    fclose(fp);

    return 0;

}

int compare(const void *s1,const void *s2){

    struct oikopedo *oik1=(struct oikopedo *)s1;
    struct oikopedo *oik2=(struct oikopedo *)s2;
    if(oik1->apod<oik2->apod) {
        return 1;
    }
    else if (oik1->apod == oik2->apod){
            if (oik1->pos < oik2->pos){
                return 1;
        }
    }
    else return -1;
}