/*
#include <cstdio>
#include "hiddenlib.h"

int main() {

    int N=getN(), x, y;
    for(;;){
        if(compare(x, y)==1) {
            if (ishidden(x)==1)
                return 1;
            x++;
            y=(x+y)/2;
        }
        else if(compare(x, y)==-1){
            if(ishidden(y)==1)
                return 1;
            x=(x+y)/2;
            y--;
        }
        else if(compare(x, y)==0)
            return ishidden((x+y)/2);
    }
    return 0;
}*/
#include "hiddenlib.h"

int main()
{
    int N=getN();
    int beg=1, end=N, mid;
    while (beg<end)
    {
        mid = (beg+end)/2;
        if (compare(mid,mid+1) == 1) end=mid;
        else beg=mid+1;
    }
    ishidden(beg);
}