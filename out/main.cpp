#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <fstream>  //in/out files
#include <functional> //greater<int>()

using namespace std;

struct Erasmus{
    int M,U;
    vector<int> u;
};

struct selected{
    int index;
    int uni;

    selected() {}
    selected (int _index,int _uni)
    {
        index=_index;
        uni=_uni;
    }
};
//quickSort
int partition(vector<int> &values,vector<int> &idx, int left, int right) {
    int pivotIndex = left + (right - left) / 2;
    int pivotValue = values[pivotIndex];
    int i = left, j = right;
    int temp,temp_idx;
    while(i <= j) {
        while(values[i] > pivotValue) {
            i++;
        }
        while(values[j] < pivotValue) {
            j--;
        }
        if(i <= j) {
            temp = values[i];
            values[i] = values[j];
            values[j] = temp;

            temp_idx = idx[i];
            idx[i]=idx[j];
            idx[j]=temp_idx;

            i++;
            j--;
        }
    }
    return i;
}
void quicksort(vector<int> &values,vector<int> &idx, int left, int right) {
    if(left < right) {
        int pivotIndex = partition(values, idx, left, right);
        quicksort(values, idx, left, pivotIndex - 1);
        quicksort(values, idx, pivotIndex, right);
    }
}

Erasmus split(string line, char delimiter){
    Erasmus foithths;
    string s;
    int i;

    i=0;
    s = "";
    while (line[i] != delimiter)
    {
        s.push_back(line[i]);
        i++;
    }
    i++;
    foithths.M = stoi(s);

    s = "";
    while (line[i] != delimiter)
    {
        s.push_back(line[i]);
        i++;
    }
    i++;
    foithths.U = stoi(s);
    int j=i;
    for(i=0;i<foithths.U;i++)
    {
        s="";
        while (line[j] != delimiter)
        {
            s.push_back(line[j]);
            j++;
        }
        j++;
        foithths.u.push_back(stoi(s));
    }

    return foithths;
}

int in(vector<int> queue, int x){

    for(int i=0;i<queue.size();i++)
    {
        if(queue[i]==x)
            return 1;
    }
    return 0;
}

int main() {

    //Variables
    int N,E,i,j;
    string N_str,line;
    vector<int> moria,indexM,u;
    vector<int> queue;
    vector<Erasmus> foithtes;
    vector<selected> final;

    //In
    ifstream infile;
    infile.open("sch.in");
    getline(infile, N_str);

    N = stoi(N_str);
    for(int i=0;i<N;i++)
    {
        getline( infile, line );
        foithtes.push_back(split(line,' '));
    }
    infile.close();

    //Main
    for(i=0;i<N;i++)
    {
        indexM.push_back(i);
        moria.push_back(foithtes[i].M);
    }

    quicksort(moria, indexM, 0, moria.size()-1);

    for(i=0;i<N;i++)
    {
        cout<<moria[i]<<","<<indexM[i]<<endl;
    }

    for(i=0;i<N;i++)
    {
        for(j=0;j<foithtes[indexM[i]].U;j++)
        {
            if(in(queue,foithtes[indexM[i]].u[j])==0)
            {
                final.push_back(selected(indexM[i]+1,foithtes[indexM[i]].u[j]));
                queue.push_back(foithtes[indexM[i]].u[j]);
                j=foithtes[indexM[i]].U;
            }
        }
    }

    for(i=0;i<N;i++)
    {
        cout<<foithtes[i].M<<" "<<foithtes[i].U;
        for(j=0;j<foithtes[i].U;j++)
        {
            cout<<" "<<foithtes[j].u[i];
        }
        cout<<endl;
    }

    //Out
    ofstream outfile;
    outfile.open("sch.out");
    outfile<<final.size()<<endl;
    for(i=0;i<final.size();i++)
    {
        outfile << final[i].index<<" "<<final[i].uni<<endl;
    }
    outfile.close();

    return 0;
}