#include <bits/stdc++.h>
using namespace std;

vector<int> split_HMS(string line, char seperator) {
    vector<int> v;
    string str;
    int i;
    line.push_back(':');
    str = "";
    for (i = 0; i < line.length(); i++){
        if (line[i] == seperator && str.length() > 0){
            if(str[0]==':')
                 str.erase(0, 1);
            v.push_back(stoi(str));
            str = "";
        }
        str.push_back(line[i]);
    }
    return v;
}

int main() {
    vector<int> HMS;
    string HMS_str,h,m,s;
    ifstream infile;
    infile.open("time.in");
    getline(infile, HMS_str);
    HMS = split_HMS(HMS_str, ':');
    infile.close();
    HMS[2]=HMS[2]*2;
    HMS[1]=HMS[1]*2;
    HMS[0]=HMS[0]*2;
    if(HMS[2]>60){
        HMS[2]=HMS[2]-60;
        HMS[1]++;
        if(HMS[2]>60)
            HMS[2]=59;
    }
    if(HMS[1]>60){
        HMS[1]=HMS[1]-60;
        HMS[0]++;
        if(HMS[1]>60)
            HMS[1]=59;
    }
    if(HMS[0]>99)
        HMS[0]=99;
    freopen("time.out","w",stdout);
    h=to_string(HMS[0]);
    m=to_string(HMS[1]);
    s=to_string(HMS[2]);
    if(h.size()==1)
        h='0'+h;
    if(m.size()==1)
        m='0'+m;
    if(s.size()==1)
        s='0'+s;
    cout<<h<<":"<<m<<":"<<s;
    return 0;
}