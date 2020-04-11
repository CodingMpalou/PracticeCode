#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#define N 7

using namespace std;

struct upallhlos{
    string name;
    float misthos;
};

struct found{
    string names;
    vector<int> idx;
};

upallhlos split_names_misthos(string line, char delimiter) {
    upallhlos upall;
    string s;
    int i=0;

    line.push_back(' ');
    s = "";
    while (line[i] != delimiter)
    {
        s.push_back(line[i]);
        i++;
    }
    i++;
    upall.name = s;

    s = "";
    while (line[i] != delimiter)
    {
        s.push_back(line[i]);
        i++;
    }
    i++;
    upall.name += s;

    s = "";
    while (line[i] != delimiter)
    {
        s.push_back(line[i]);
        i++;
    }
    i++;
    upall.misthos=stoi(s);

    return upall;
}

float misthos_mo(vector<float> misthos){
    float mo=0;
    int i;

    for(i=0;i<misthos.size();i++)
        mo+=(misthos[i])/misthos.size();

    return mo;
}

int in(vector<found> single_names,string name)
{
    for (int i=0;i<single_names.size();i++)
    {
        if (single_names[i].names == name)
            return i;
    }
    return 0;
}
int main() {
    string lines;
    int i,j;
    float mo;
    vector<float> misthos;
    vector<upallhlos> upall;

    //In
    ifstream infile;
    infile.open("onoma & misthos");
    for(i=0;i<N;i++) {
        getline(infile, lines);
        upall.push_back(split_names_misthos(lines, ' '));
    }

    //Main
    found f;
    f.names = upall[0].name;
    f.idx.push_back(0);
    vector <found> single_names;
    single_names.push_back(f);

    int idx = 0;
    for (i=1;i<upall.size();i++)
    {
        idx = in(single_names,upall[i].name);
        if ( idx == 0 )
        {
            f= *(new found);
            f.names = upall[i].name;
            f.idx.push_back(i);
            single_names.push_back(f);

        }
        else
        {
            single_names[idx].idx.push_back(i);
        }
    }

    for (int i = 0; i < single_names.size(); i++) {
        if (single_names[i].idx.size() > 1)
            for (int j=0;j<single_names[i].idx.size();j++)
                misthos.push_back(upall[single_names[i].idx[j]].misthos);
    }


    mo=misthos_mo(misthos);
    cout<<mo;


    return 0;
}