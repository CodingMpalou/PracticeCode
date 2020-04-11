#include <iostream>
#include <vector>

using namespace std;

struct dentro{

    vector<int> laxnos;
    vector<int> counter_laxnos;
    vector<struct dentro> kladakia;
};

struct dentro xmasdentro;

int large_mod(int a, long b, long c){
    if(b==0)
        return 1;
    else if(b%2==0)
    {
        long d = large_mod(a,b/2,c);
        return (d*d)%c;
    }
    else
        return a%c*large_mod(a,b-1,c)%c;
}

void dentro_init(vector<vector<short>> laxnoi,int k){
    int i,K;
    struct dentro *temp_dentro;

    for (auto laxno : laxnoi)
    {
        K=0;
        temp_dentro = &xmasdentro;
        for (auto noumero : laxno)
        {
            K++;
            i=0;
            for(i=0;i<temp_dentro->laxnos.size();i++)
            {
                if (temp_dentro->laxnos[i]== noumero)
                {
                    temp_dentro->counter_laxnos[i]++;
                    temp_dentro=&(temp_dentro->kladakia[i]);
                    break;
                }
            }
            if (i==temp_dentro->laxnos.size())
            {
                temp_dentro->counter_laxnos.push_back(1);
                temp_dentro->laxnos.push_back(noumero);
                if (K!=k)
                    temp_dentro->kladakia.push_back(*new dentro);
                temp_dentro = &(temp_dentro->kladakia[i]);
            }
        }
    }
}

void print_dentro(int K,int index_val,struct dentro **t) {
    struct dentro *d=*t;

    if(K<3)
    {
       if (index_val < d->laxnos.size()) {
           cout<<endl;
           d= &(d->kladakia[index_val]);
           print_dentro(K, index_val + 1, &d);
       }
       else
       {
           print_dentro(K+1, 0, &d);
       }
       cout<<d->laxnos[index_val]<<" "<<K<<" "<<index_val<<endl;
    }
}

void my_print(){
    struct dentro *t = &xmasdentro;
    print_dentro(0,0,&t);
}

vector<vector<int>> koina(int K, vector<vector<short>> tuxeroi){
    vector<vector<int>> res;
    int i,j,flag;
    struct dentro *temp_dentro;
    int c=0,max,temp,size_epipedou;
    for(auto tuxero:tuxeroi)
    {
        res.push_back(*new vector<int>());
        res[c].push_back(0);
        res[c].push_back(0);
        max=0;
        temp=0;
        temp_dentro = &xmasdentro;
        for(auto noumero : tuxero)
        {
            flag = 0;
            for(i=0;i<K;i++)
            {
                if (flag == 1)
                    break;
                size_epipedou = temp_dentro->laxnos.size();
                cout<<size_epipedou<<endl;
                for (j = 0; j < size_epipedou; j++)
                {
                    if (temp_dentro->laxnos[i] == noumero) {
                        if (i==0)
                            res[c][0]=xmasdentro.counter_laxnos[j];
                        temp++;
                        temp_dentro = &(temp_dentro->kladakia[i]);
                        size_epipedou = temp_dentro->laxnos.size();
                    }
                    else {
                        flag = 1;
                        break;
                    }
                }
            }
            if (max<temp)
                max = temp;
        }
        res[c][1] = max;
        c++;
    }
    return res;
}

vector<short> convert(int p, int K){
    vector<short> v;
    unsigned long long int m=1;

    for(unsigned int i=0;i<K;i++)
    {
        m*=10;
        v.push_back(p%m/(m/10));
    }
    return v;
}

int main(){
    //Variables
    int K,N,Q,p,i,j;
    vector<vector<short>> x,y;
    vector<vector<int>> res;

    //In File
    FILE *fi=fopen("lottery.in","r");
    fscanf(fi,"%d %d %d", &K,&N,&Q);
    for(i=0;i<N;i++)
    {
        fscanf(fi,"%d",&p);
        x.push_back(convert(p,K));
    }
    for(i=0;i<Q;i++)
    {
        fscanf(fi,"%d",&p);
        y.push_back(convert(p,K));
    }
    fclose(fi);

    //Main
    dentro_init(x,K);
    my_print();
    res=koina(K,y);

    //cout<<xmasdentro.counter_laxnos[0];

    /*for(i=0;i<x.size();i++){
        for(j=0;j<x[i].size();j++)
            cout<<x[i][j];
        cout<<endl;
    }

    cout<<endl;

    for(i=0;i<y.size();i++){
        for(j=0;j<y[i].size();j++)
            cout<<y[i][j];
        cout<<endl;
    }*/
    //Out File
    FILE *fo=fopen("lottery.out","w");
    for(i=0;i<res.size();i++)
    {
        for(j=0;j<res[i].size();j++)
        {
            fprintf(fo, "%d ", res[i][j]);
        }
        fprintf(fo,"\n");
    }
    fclose(fo);

    return 0;
}