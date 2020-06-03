#include<cstdio>

int pinakas[10]={1,3,5,7,7,8,8,9,10,11};
int pinakas2[10]={1,3,5,7,7,8,4,2,1,0};
int n=10;

int ternary()
{
    int beg=0, end=9, mid;
    while (beg<end)
    {
        mid = (beg+end)/2;
        if (pinakas2[mid]<=pinakas2[mid+1]) beg=mid+1;
        else end=mid;
    }
    return beg;
}

int lower_bound(int target)
{
    int beg=0, end=9, mid;
    while (beg<end)
    {
        mid = (beg+end)/2;
        if (pinakas[mid]<target) beg=mid+1;
        else end=mid;
    }
    return beg;
}

int upper_bound(int target)
{
    int beg=0, end=9, mid;
    while (beg<end)
    {
        mid = (beg+end)/2;
        if (pinakas[mid]<=target) beg=mid+1;
        else end=mid;
    }
    return beg;
}

int main()
{
    int lo = lower_bound(6);
    int up = upper_bound(6);
    printf("lower bound: %d\n",lo);
    printf("upper bound: %d\n",up);
    printf("emfaniseis:  %d\n",up-lo);
    printf("max_pos: %d",ternary());
}