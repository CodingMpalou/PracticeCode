#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <functional>
using namespace std;

vector<int> split_S(string line, char seperator){
    int i;
    vector<int> v;
    string s;

    line.push_back(' ');
    s = "";
    for (i = 0; i < line.length(); i++)
    {
        if (line[i] == seperator && s.length() > 0)
        {
            v.push_back(stoi(s));
            s="";
        }
        s.push_back(line[i]);
    }

    return v;
}
//QuickSort
int partition(vector<int> &values, vector<int> &idx, int left, int right) {
    int pivotIndex = left + (right - left) / 2;
    int pivotValue = values[pivotIndex];
    int i = left, j = right;
    int temp, temp_idx=0;
    while (i <= j)
    {
        while (values[i] > pivotValue)
        {
            i++;
        }
        while (values[j] < pivotValue)
        {
            j--;
        }
        if (i <= j)
        {
            temp = values[i];
            values[i] = values[j];
            values[j] = temp;

            temp_idx = idx[i];
            idx[i] = idx[j];
            idx[j] = temp_idx;

            j--;
            i++;
        }
    }
    return i;
}

void quicksort(vector<int> &values, vector<int> &idx, int left, int right) {
    int pivotIndex;
    if (left < right)
    {
        pivotIndex = partition(values, idx, left, right);
        quicksort(values, idx, left, pivotIndex - 1);
        quicksort(values, idx, pivotIndex, right);
    }
}

vector<int> get_most_freq_nums(vector<int> S){
    vector<int> most_freq,freq,nums;

    int i,j,c=0,num;

    for(i=0;i<S.size();i++)
    {
        num=S[i];
        for(j=0;j<S.size();j++)
        {
            if(num==S[j] && S[j]!=0)
            {
                S[j]=0;
                c++;
            }
        }
        freq.push_back(c);
        nums.push_back(num);
        c=0;
    }

    quicksort(freq, nums, 0, nums.size() - 1);

    for(i=0;i<3;i++)
        most_freq.push_back(nums[i]);

    return most_freq;
}

int main() {

    //Variables
    string N_str,S_str;
    int N,i;
    vector<int> S,res;

    //In File
    ifstream infile;
    infile.open("sch.in");
    getline(infile, N_str);
    N=stoi(N_str);
    getline(infile, S_str);
    S=split_S(S_str, ' ');
    infile.close();

    //Main
    res=get_most_freq_nums(S);

    //Out File
    ofstream outfile;
    outfile.open("sch.out");
    for(i=0;i<res.size();i++){
        outfile<<res[i]<<" ";
    }
    outfile.close();

    return 0;
}