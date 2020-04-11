#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> split(string line, char delimiter){
    int i,c=0;
    vector<int> v;
    string s;

    s="";
    for(i=0;i<line.length();i++)
    {
        if(line[i]!=delimiter)
        {
            c++;
           if(c==1)
           {
               s.push_back(line[i]);
               v.push_back(stoi(s));
           }
            if(c==2)
            {
                s.push_back(line[i]);
                v.push_back(stoi(s));
            }
            if(c==3)
            {
                s.push_back(line[i]);
                v.push_back(stoi(s));
            }
        }
        s="";
    }
    return v;
}

vector<int> splitMatrix(string line,char delimiter){
    vector<int> q;
    int j=0,i;
    string s;

    line.push_back(delimiter);

    s="";
    for(i=0;i<line.length();i++) {
        if (line[i] != delimiter) {
            s.push_back(line[i]);
        } else {
            q.push_back(stoi(s));
            s="";
        }
    }

   return q;
}

int main() {

    int res=0,i,j;
    string line;
    vector<int> RCK;
    vector<vector<int>> matrix;

    ifstream infile;
    infile.open("hopscotch.in");
    getline(infile, line);
    RCK=split(line, ' ');
    for(i=0;i<RCK[0];i++)
    {
        getline(infile, line);
        matrix.push_back(splitMatrix(line, ' '));
    }
    infile.close();

    //Main

    for(i=0;i<3;i++)
        cout<<RCK[i]<<" ";

//    for(i=0;i<RCK[0];i++)
//    {
//        for(j=0;j<RCK[1];j++)
//        {
//            cout<<matrix[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    cout<<endl;

    for(i=0;i<matrix.size();i++)
    {
        for(j=0;j<matrix[i].size();j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    //Out
    ofstream outfile;
    outfile.open("hopscotch.out");
    outfile << res;
    outfile.close();

    return 0;
}


//vector<vector<int>> q;
//q.push_back({1,235,86});
//cout<<q[0][1]