#include <stdio.h>

//1os tropos
void addition1(int a,int b){
    int e ;
    e=a+b;
    printf("addition",e);
}

void substraction(int a,int b){
    int f;
    f=a=b;
    printf("substraction",f);
}

void multiplication(int a,int b){
    int g;
    g=a*b;
    printf("multiplication",g);
}

void division(int a,int b){
    int h;
    h=a/b;
    printf("division",h);
}


int main()
{
    int a,b;

    printf("dwse tesseris times\n");
    scanf("%d%d%d%d",&a,&b,&c,&d);

    addition1(a,b);
    substraction(a,b);
    multiplication(a,b);
    division(a,b);

    return 0;
}


//////2os tropos
//int addition1(int a,int b){
//    int e ;
//    e=a+b;
//
//    return e;
//}
//
//int substraction(int a,int b){
//    int f;
//    f=a=b;
//
//    return f;
//}
//
//int multiplication(int a,int b){
//    int g;
//    g=a*b;
//
//    return g;
//}
//
//int division(int a,int b){
//    int h;
//    h=a/b;
//
//    return h;
//}
//
//
//int main()
//{
//    int a,b;
//    int sum;
//    printf("dwse tesseris times\n");
//    scanf("%d%d%d%d",&a,&b,&c,&d);
//
////    sum=addition(a,b);
////    printf("%f\n",sum);
//
//    printf("%f\n",addition1(a,b));
//    printf("%f\n",substraction(a,b));
//    printf("%f\n",multiplication(a,b));
//    printf("%f\n",division(a,b));
//
//    return 0;
//}
//
////3os tropos by reference
//int addition1(int *a,int *b){
//    int e ;
//    e=*a+*b;
//
//    return e;
//}
//
//int substraction(int *a,int *b){
//    int f;
//    f=*a=*b;
//
//    return f;
//}
//
//int multiplication(int *a,int *b){
//    int g;
//    g=(*a)*(*b);
//
//    return g;
//}
//
//int division(int *a,int *b){
//    int h;
//    h=(*a)/(*b);
//
//    return h;
//}
//
//
//int main()
//{
//    int e,f;
//    int *c,*d;
//    c=&e;
//    d=&f;
//
//    int sum;
//    printf("dwse tesseris times\n");
//    scanf("%d%d",&e,&f);
//
////    sum=addition(a,b);
////    printf("%f\n",sum);
//
//    printf("%f\n",addition1(c,d));
//    printf("%f\n",substraction(c,d));
//    printf("%f\n",multiplication(c,d));
//    printf("%f\n",division(c,d));
//
//    return 0;
//}
//
////4os tropoos global-katholikes metavlites
//int sum,sub,pro,div; //global
//
//void addition(int a,int b) {
//    sum = a + b;
//}
//
//void substraction(int a,int b){
//    sub=a=b;
//}
//
//void multiplication(int a,int b){
//    pro=a*b;
//
//}
//
//void division(int a,int b){
//    div=a/b;
//
//}
//
//
//int main()
//{
//    int a,b;
//
//    printf("dwse tesseris times\n");
//    scanf("%d%d%d%d",&a,&b);
//
////    sum=addition(a,b);
////    printf("%f\n",sum);
//
//    addition(a,b);
//    substraction(a,b);
//    multiplication(a,b);
//    division(a,b);
//
//    printf("%d\n%d\n%d\n%d\n",sum,sub,pro,div);
//
//
//    return 0;
//}