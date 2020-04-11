#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print_matrix(vector<vector<int>> matrix){
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[i].size();j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}

vector<vector<int>> multiply_matrix(vector<vector<int>> matrix1, vector<vector<int>> matrix2){
    vector<vector<int>> m;
    int i, j, k, sum;

    for (i = 0; i < matrix1.size(); i++)
    {
        m.push_back(*new vector<int>());
        for (j = 0; j < matrix2[0].size(); j++)
        {
            sum=0;
            for (k = 0; k < matrix2.size(); k++)
                sum+=matrix1[i][k]*matrix2[k][j];
            m[i].push_back(sum);
        }
    }
    return m;
}

int main() {
    int i,j;
    vector<vector<int>> matrix1, matrix2, final_matrix;
    matrix1={{1, 4},
             {2, 3}};
    matrix2={{1, 4, 9},
             {2, 3, 0}};

    cout<<"Matrix1: "<<endl;
    print_matrix(matrix1);

    cout<<endl<<"Matrix2: "<<endl;
    print_matrix(matrix2);

    if(matrix1[0].size()==matrix2.size())
    {
        final_matrix = multiply_matrix(matrix1, matrix2);
        cout << endl << "Final Matrix: " << endl;
        print_matrix(final_matrix);
    }
    else
        cout<<"Wrong dimensions check matrices again!";
    return 0;
}