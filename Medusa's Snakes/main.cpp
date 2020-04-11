#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct IndexPos{
    int lo,hi;
};

vector<vector<int>> PopulateIndex(vector<vector<int>> index, string line, int size){
    //vector<vector<int>> index;
    int i,j;

    for(i=0;i<5;i++)
        index.push_back(*new vector<int>());

    for(i=0;i<size;i++)
    {
        if(line[i]=='S')
            index[0].push_back(i);

        else if(line[i]=='N')
            index[1].push_back(i);

        else if(line[i]=='A')
            index[2].push_back(i);

        else if(line[i]=='K')
            index[3].push_back(i);

        else index[4].push_back(i);
    }

//    for(i=0;i<5;i++)
//    {
//        for(j=0;j<index[i].size();j++)
//        {
//            cout<<index[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    return index;
}

vector<IndexPos> InitIndex(vector<vector<int>> index){
    vector<IndexPos> p;
    int i;

    for(i=0;i<5;i++)
    {
        p.push_back(*new IndexPos);
        p[i].lo=0;
        p[i].hi=index[i].size()-1;
    }

    return p;
}

vector<vector<int>> FindIndex(vector<vector<int>> index, string line){
    int i=0,j=0;
    vector<IndexPos> p = InitIndex(index);

    for(i=0;i<4;i++)
    {
        while(index[i][p[i].hi]>index[i+1][p[i+1].lo] && p[i].hi!=p[i].lo)
        {
            p[i+1].lo ++;
            if(p[i+1].lo > p[i+1].hi)
            {
                p[i+1].lo=0;
                p[i].hi--;
            }
        }
        if(p[i+1].hi==p[i+1].lo && index[i][p[i].hi]>index[i+1][p[i+1].lo]){
            p[i+1].lo=0;
            p[i+1].hi=index[i+1].size()-1;
            i--;
        }

    }

    for(i=0;i<5;i++)
    {
        for(j=p[i].lo;j<=p[i].hi;j++)
            cout << line[index[i][j]] << " ";
    }

    return index;
}

int main(){

    vector<vector<int>> index;
    string N_str,line;
    int N,lvl=0;

    //In
    ifstream infile;
    infile.open("inFile");
    getline(infile,N_str);
    N=stoi(N_str);
    getline(infile,line);
    infile.close();

    //Main
    index=PopulateIndex(index, line, N);
    index=FindIndex(index, line);

    //Out
    ofstream outfile;
    outfile.open("outFile");
    outfile<<lvl;
    outfile.close();

    return 0;
}