#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<int> split_NM(string line, char seperator){
    vector<int> v;
    string s;
    int i;

    line.push_back(' ');
    s = "";
    for (i = 0; i < line.length(); i++)
    {
        if (line[i] == seperator && s.length() > 0)
        {
            v.push_back(stoi(s));
            s = "";
        }
        s.push_back(line[i]);
    }
    return v;
}

vector<int> split_matrix(string line, char seperator){
    vector<int> v;
    int i;
    string s;

    line.push_back(' ');
    s="";
     for(i=0;i<line.length();i++)
     {
        if (line[i] == seperator && s.length()>0)
        {
            v.push_back(stoi(s));
            s="";
        }
        if(line[i] != seperator)
            s.push_back(line[i]);
     }

    return v;
}

vector<int> select_row(vector<vector<int>> matrix, int select){
    vector<int> row;
    int j;

    if(select>matrix.size()-1)
        select=matrix.size()-1;

    for(j=0;j<matrix[select].size();j++)
        row.push_back(matrix[select][j]);
    return row;
}

vector<int> select_col(vector<vector<int>> matrix, int select){
    vector<int> col;
    int i;

    if(select>matrix[0].size()-1)
        select=matrix[0].size()-1;

    for(i=0;i<matrix.size();i++)
        col.push_back(matrix[i][select]);
    return col;
}

vector<int> find_min_col(vector<vector<int>> matrix){
    int i,j;
    vector<int> min;

    for(i=0;i<matrix[0].size();i++)
        min.push_back(*new int);

    for(j=0;j<matrix[0].size();j++)
    {
        min[j]=matrix[0][j];
        for(i=0;i<matrix.size();i++)
        {
            if(matrix[i][j]<min[j])
                min[j]=matrix[i][j];
        }
    }

    return min;
}

vector<int> find_max_row(vector<vector<int>> matrix){
    int i,j;
    vector<int> max;

    for(i=0;i<matrix.size();i++)
        max.push_back(*new int);

    for(i=0;i<matrix.size();i++)
    {
        max[i]=matrix[i][0];
        for(j=0;j<matrix[i].size();j++)
        {
            if(matrix[i][j]>max[i])
                max[i]=matrix[i][j];
        }
    }
    return max;
}

float find_mean_diag(vector<vector<int>> matrix){
    vector<int> diagwnios;
    float mo=0;
    int i,size;

    size = (matrix.size()<=matrix[0].size()) ? matrix.size() : matrix[0].size();

    for(i=0;i<size;i++)
        diagwnios.push_back(matrix[i][i]);

    for(i=0;i<diagwnios.size();i++)
        mo+=(float)(diagwnios[i])/diagwnios.size();

    return mo;
}

int find_mid_antidiag(vector<vector<int>> matrix){
    vector<int> antidiagwnios;
    int i,size;

    size = (matrix.size()<=matrix[0].size()) ? matrix.size() : matrix[0].size();
    for(i=0;i<size;i++)
        antidiagwnios.push_back(matrix[i][matrix[0].size()-1-i]);

    return antidiagwnios[antidiagwnios.size()/2];
}

void print_matrix(vector<vector<int>> matrix){
    cout<<endl<<"Matrix: "<<endl;
    for(int i=0;i<matrix.size();i++) {
        for (int j = 0; j < matrix[i].size(); j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

void print_vector(vector<int> matrix){
    cout<<endl<<"Vector: "<<endl;
    for (int j = 0; j < matrix.size(); j++)
        cout << matrix[j] << " ";
    cout<<endl;
}

int main() {

    string NM_str,matrix_str;
    vector<int> NM,min,max;
    vector<vector<int>> matrix;
    int i=0,j=0,mid,epelexe;
    float mo;

    //In
    ifstream infile;
    infile.open("matrix.in");
    getline(infile, NM_str);
    NM = split_NM(NM_str, ' ');
    while(getline(infile, matrix_str))
        matrix.push_back(split_matrix(matrix_str, ' '));
    infile.close();

    //Main
    cout<<"N & M: "<<endl;
    cout<<matrix.size()<<" ";
    cout<<  matrix[0].size()<<endl;

    epelexe=2;

    min=find_min_col(matrix);
    print_vector(min);

    max=find_max_row(matrix);
    print_vector(max);

    mo=find_mean_diag(matrix);
    cout<<endl<<"The mean is: "<<mo;

    mid=find_mid_antidiag(matrix);
    cout<<endl<<endl<<"4.Mid Antidiagwnios: "<<mid<<endl;

    return 0;
}