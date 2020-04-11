#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    vector<vector<char>> matrix,names;
    vector<char> s;
    char ch;
    int i,j;

    FILE *fi=fopen("input","r");
    FILE *fo=fopen("ouput","w");
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            fscanf(fi,"%c",&ch);
            s.push_back(ch);
        }
        matrix.push_back(s);
        s.clear();
    }
    while(i!=';')
    {
        fscanf(fi,"%c",&ch);
        s.push_back(ch);
    }
    fclose(fi);
    fclose(fo);
    return 0;
}