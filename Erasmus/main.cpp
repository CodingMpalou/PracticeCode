/* USER: 32pdpu2
LANG: C++
TASK: erasmus */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <functional>

using namespace std;

struct University {
    int positions, index_pos;
};

struct Student {
    int M, U;
    vector<int> u;
};

vector<int> split_NM(string line, char seperator) {
    vector<int> v;
    string str;
    int i;

    line.push_back(' ');
    str = "";
    for (i = 0; i < line.length(); i++)
    {
        if (line[i] == seperator && str.length() > 0)
        {
            v.push_back(stoi(str));
            str = "";
        }
        str.push_back(line[i]);
    }
    return v;
}

vector<University> split_uni_pos(string line, char seperator, vector<int> size) {
    vector<University> uni;
    int i, j;
    string str;

    for (i = 0; i < size[0]; i++)
        uni.push_back(*(new University));

    line.push_back(' ');
    j = 0;
    str = "";
    for (i = 0; i < size[0]; i++)
    {
        while (line[j] != seperator)
        {
            str.push_back(line[j]);
            j++;
        }
        j++;
        uni[i].positions = (stoi(str));
        uni[i].index_pos = (i + 1);
        str = "";
    }
    return uni;
}

Student split_students_info(string line, char seperator) {
    Student stud;
    string str;
    int i = 0;

    line.push_back(' ');
    str = "";
    while (line[i] != seperator)
    {
        str.push_back(line[i]);
        i++;
    }
    i++;
    stud.M = stoi(str);

    str = "";
    while (line[i] != seperator)
    {
        str.push_back(line[i]);
        i++;
    }
    i++;
    stud.U = stoi(str);

    int j = i;
    str = "";
    for (i = 0; i < stud.U; i++) {
        while (line[j] != seperator) {
            str.push_back(line[j]);
            j++;
        }
        j++;
        stud.u.push_back(stoi(str));
        str = "";
    }
    return stud;
}

//Quicksort
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

vector<int> select_university(vector<University> uni, vector<Student> student, vector<int> sorted_idx) {
    vector<int> v;
    vector<Student> stud;
    int i, j;

    for (i = 0; i < student.size(); i++)
        stud.push_back(student[sorted_idx[i]]);

    for (i = 0; i < stud.size(); i++)
        v.push_back(0);

    for (i = 0; i < stud.size(); i++)
    {
        for (j = 0; j < stud[i].U; j++)
        {
            if (uni[stud[i].u[j] - 1].positions > 0)
            {
                v[sorted_idx[i]] = (stud[i].u[j]);
                uni[stud[i].u[j] - 1].positions -= 1;
                break;
            }
        }
    }
    return v;
}

vector<string> vector_2_vectorString(vector<int> v) {
    vector<string> str;
    int i;

    for (i = 0; i < v.size(); i++)
    {
        str.push_back(to_string(v[i]));
        if (str[i] == "0")
            str[i] = "NONE";
    }
    return str;
}

int main() {

    string NM_str, uni_pos, stud_info;
    vector<string> selected_uni;
    vector<int> NM, M, index_m;
    int i = 0, j = 0;
    vector<University> uni;
    vector<Student> stud;

    //In
    ifstream infile;
    infile.open("erasmus.in");
    getline(infile, NM_str);
    NM = split_NM(NM_str, ' ');
    getline(infile, uni_pos);
    uni = split_uni_pos(uni_pos, ' ', NM);
    for (i = 0; i < NM[1]; i++)
    {
        getline(infile, stud_info);
        stud.push_back(split_students_info(stud_info, ' '));
    }
    infile.close();

    //Main
    for (i = 0; i < NM[1]; i++)
    {
        index_m.push_back(i);
        M.push_back(stud[i].M);
    }

    quicksort(M, index_m, 0, M.size() - 1);
    vector<int> selected = select_university(uni, stud, index_m);
    selected_uni = vector_2_vectorString(selected);

    //Out
    ofstream outfile;
    outfile.open("erasmus.out");
    for (i = 0; i < selected_uni.size(); i++)
        outfile << selected_uni[i] << endl;
    outfile.close();

    return 0;
}