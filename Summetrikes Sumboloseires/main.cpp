#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <set>

using namespace std;
string bres_res(string s)
{
    int i,j,c=0,check=0;
    string temp=s,res;
    set<string> str;

    for(i=0;i<s.length();i++) {
        temp = s;
        temp.erase(i, 1);
        if (temp.substr(0, s.length() / 2) == temp.substr(s.length() / 2, s.length() - 1))
        {
            res = temp.substr(0, s.length() / 2);
            str.insert(res);
        }

        if(str.size()>1)
            return "1";
        temp=s;
    }
    if(str.size()==1)
        return res;
    else return "0";
}

/*
string bres_res1(string s)
{

    int i,j,c=0,check=0;
    string temp=s,res;
    vector<string> str;

    for(i=0;i<s.length();i++) {
        temp = s;
        temp.erase(i, 1);
        if (temp.substr(0, s.length() / 2) == temp.substr(s.length() / 2, s.length() - 1))
        {
            res = temp.substr(0, s.length() / 2);
            str.push_back(res);
            c++;
        }
        for (j = 0; j < str.size(); j++) {
            if(str[j-1]==str[j])
                check=1;
            else check=0;
        }
        if(c>1 && check==0)
            return "1";
        temp=s;
    }
    if(c==1 || check==1)
        return res;

    else return "0";
}
*/

int main() {

    int i,j;
    string s;
    vector<string> res;

    //In File
    ifstream fi("symstr.in");
    getline(fi,s);
    while(!fi.eof())
    {
        getline(fi,s);
        res.push_back(bres_res(s));
    }
    fi.close();

    //Out File
    FILE *fo=fopen("symstr.out","w");
    for(i=0;i<res.size();i++)
    {
        for(j=0;j<res[i].size();j++)
            fprintf(fo, "%c", res[i][j]);
        fprintf(fo, "\n");
    }
    fclose(fo);

    return 0;
}