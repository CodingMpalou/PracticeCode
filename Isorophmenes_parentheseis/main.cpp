#include <iostream>
#include <vector>
#include <string>

using namespace std;

int nai_h_oxi(vector<char> kommataki){
    int i,M,M_prev;
    M=kommataki.size()-1;
    while(1) {
        i=0;
        M_prev=M;
        while (i < M)
        {
            if (kommataki[i] == '(' && kommataki[i + 1] == ')')
            {
                kommataki.erase(kommataki.begin() + i);
                kommataki.erase(kommataki.begin() + i + 1);
                M-=2;
                break;
            }
            i++;
        }
        if(M+1==0)
            return 1;
        else if(M==M_prev)
            return 0;
    }
}

int bres_isorropies(vector<char> S){
    int bhma,i,c=0,k,apotelesma;
    vector<char> kommataki;

    for(i=0;i<S.size();i++)
    {
        for(bhma=i+2;bhma<=S.size();bhma=bhma+2) {
            for(k=i;k<bhma;k++)
                kommataki.push_back(S[k]);
           kommataki.clear();
          apotelesma=nai_h_oxi(kommataki);
          if(apotelesma==1)
              c++;
        }
    }
    return c;
}


int main()
{
    int N,i,plhthos;
    char p;
    vector<char> S;

    //In file
    FILE *fi= fopen("cntbal.in", "r");
    fscanf(fi, "%d\n", &N);
    for(i=0;i<N;i++)
    {
        fscanf(fi,"%c",&p);
        S.push_back(p);
    }
    fclose(fi);

    //Main

    plhthos=bres_isorropies(S);

    //Out File
    FILE *fo=fopen("cntbal.out","w");
    fprintf(fo, "%d", plhthos);
    fclose(fo);
    return 0;
}