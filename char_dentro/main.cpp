#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct char_dentro{
    vector<char> lexh;
    vector<struct char_dentro> kladakia;
};

struct char_dentro xmasdentro;

void make_dentro(vector<string> s){
    int i;
    struct char_dentro *tmp_dentro;

    for (auto lexeis : s)
    {
        tmp_dentro = &xmasdentro;
        for (auto gramma : lexeis)
        {
            i=0;
            while(i<tmp_dentro->lexh.size())
            {
                if (tmp_dentro->lexh[i]== gramma)
                {
                    tmp_dentro=&(tmp_dentro->kladakia[i]);
                    break;
                }
                i++;
            }
            if (i==tmp_dentro->lexh.size())
            {
                tmp_dentro->lexh.push_back(gramma);
                tmp_dentro->kladakia.push_back(*(new char_dentro));
                tmp_dentro = &(tmp_dentro->kladakia[i]);
            }
        }
    }
    cout<<xmasdentro.lexh[1]<<xmasdentro.kladakia[1].lexh[0]<<xmasdentro.kladakia[1].kladakia[0].lexh[1]<<xmasdentro.kladakia[1].kladakia[0].kladakia[1].lexh[0]<<endl;
}

void ektypwse(char_dentro* now,string s)
{
    char_dentro *next;
    if (now->lexh.size()>0)
    {
        for (int i=0;i<now->kladakia.size();i++){
            s.push_back(now->lexh[i]);
            next  =  &(now->kladakia[i]);
            ektypwse(next,s);
            s.erase(s.end()-1);
        }
    }
    else
        cout<<s<<endl;

}

int main() {
    string str;
    vector<string> x;
    ifstream infile;
    infile.open("input");
    while(!infile.eof())
    {
        getline(infile, str);
        x.push_back(str);
    }
    make_dentro(x);

    ektypwse(&xmasdentro,"");
    return 0;
}