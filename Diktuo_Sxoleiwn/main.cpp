#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int w;
    vector<int> neighbours;
};

vector<Node> split_weight(string line, char delimiter,int N) {
    vector<Node> node;
    for(int i=0;i<N;i++)
        node.push_back(*(new Node));

    string s;
    int i, j;

    j=0;
    s="";
    line.push_back(' ');
    for(i=0;i<N;i++)
    {
        while(line[j]!=delimiter)
        {
            s.push_back(line[j]);
            j++;
        }
        j++;
        node[i].w=stoi(s);
        s="";
    }
    return node;
}

vector<Node> split_neighbours(string line, char delimiter, int N){
    vector<Node> node;
    for(int i=0;i<N;i++)
        node.push_back(*(new Node));

    string s;
    int i,j,num;

    s="";
    for(i=0;i<N;i++)
    {
        num=line[i];
        for (j=i;j<N;j++)
        {

            if (line[j] == delimiter)
            {
                if (line[j - 1] == num || line[j + 1] == num)
                {
                    s.push_back(line[j - 1]);
                    s.push_back(line[j + 1]);
                    node[j].neighbours.push_back(stoi(s));
                    cout << node[j].neighbours[j] << " ";
                }
            }
            s="";
        }
    return node;
}

int main() {

    //Variables
    int N, K = 0, i, j;
    string N_str, w, line;
    vector<Node> nodes;

    //In
    ifstream infile;
    infile.open("schoolnet.in");
    getline(infile, N_str);
    N = stoi(N_str);
    getline(infile, w);
    split_weight(w, ' ', N);
    for (i = 0; i < N; i++) {
        getline(infile, line);
        split_neighbours(line, ' ', N);
    }
    infile.close();

    //Main


    //Out
    ofstream outfile;
    outfile.open("schoolnet.out");
    outfile << K;
    outfile.close();

    return 0;
}

