#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <bits/stdc++.h>

using namespace std;

set <int, greater <int> > setnum;
set <int, greater <int> > :: iterator itr;

vector<int> split_NK(string line, char seperator){
    vector<int> v;
    int i;
    string s;

    line.push_back(' ');
    s="";
    for(i=0;i<line.length();i++)
    {
        if(line[i]==seperator && line.length()>0)
        {
            v.push_back(stoi(s));
            s="";
        }
        s.push_back(line[i]);
    }

    return v;
}

vector<int> split_c(string line, char seperator){
    vector<int> v;
    int i;
    string s;

    line.push_back(' ');
    s="";
    for(i=0;i<line.length();i++)
    {
        if(line[i]==seperator && line.length()>0)
        {
            v.push_back(stoi(s));
            s="";
        }
        s.push_back(line[i]);
    }

    return v;
}

int min_kom_me_xrwm(vector<int> c, vector<int> NK){
    vector <int> results;
    int i, start=0, end=0;
    unsigned int N=c.size();

    for(i=0;i<N;i++)
    {
        if(c[i]>NK[1])
            return 0;
    }

    while(end<N)
    {
        if (start<end && c[start] == c[end]){
            while(++start<end && c[start] == c[start+1] ){}
        }

        for (int j=start;j<=end;j++)
            setnum.insert(c[j]);

        if (NK[1]==setnum.size())
            results.push_back(end-start+1);
        end++;
    }

    if (results.size()>0)
        return *min_element(results.begin(), results.end());

    else
        return 0;
}

int main(){

    //Variables
    string NK_str, c_str;
    vector<int> NK,c,min_xrwm;
    int i;
    int res=0;

    //In File
    ifstream infile;
    infile.open("colors.in");
    getline(infile, NK_str);
    NK=split_NK(NK_str, ' ');
    getline(infile, c_str);
    c=split_c(c_str, ' ');
    infile.close();

    //Main
    res = min_kom_me_xrwm(c, NK);

    //Out File
    ofstream outfile;
    outfile.open("colors.out");
    outfile<<res;
    outfile.close();

    return 0;
}