#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int str2int(char s) {
    return (int) s - 48;
}

string int2str(vector<int> int_array) {
    string str = "";
    for (int i = 0; i < int_array.size(); i++) {
        str += to_string(int_array[i]);
    }
    return str;
}

vector<int> intArray(string s) {
    vector<int> x;
    for (int i = 0; i < s.length(); i++)
        x.push_back(str2int(s[i]));
    return x;
}

//string reverseStr(string str) {
//    int n = str.length();
//    for (int i = 0; i < n / 2; i++)
//        swap(str[i], str[n - i - 1]);
//    return str;
//}

vector<int> mulOneToMany(vector<int> arr, int l) {
    reverse(arr.begin(), arr.end());
    vector<int> res;

    for (int i = 0; i < arr.size(); i++)
        res.push_back(arr[i] * l);

    int next = 0;
    int prev_mod = 0;
    for (int i = 0; i < arr.size() - 1; i++) {
        prev_mod = next;
        next = (prev_mod + res[i]) / 10;
        res[i] = (prev_mod + res[i]) % 10;
    }
    if (res.back() / 10 != 0) {
        prev_mod = next;
        next = (prev_mod + res.back()) / 10;
        res.back() = (prev_mod + res.back()) % 10;
        res.push_back(next);
    }
    reverse(res.begin(), res.end());
    return res;
}

//problhma
vector<int> add_vals(vector<vector<int>> res) {
    vector<int> qq;

    for (int i = 0; i < res.size(); i++)
        reverse(res[i].begin(), res[i].end());

    // Add every vector
    for (int i = 0; i < res.size(); i++) {
        qq.push_back(0);
        for (int j = 0; j < res.size(); j++)
            qq[i] += res[j][i];
    }
    for(int i=0;i<qq.size();i++)
    {
        cout<< qq[i] <<endl;
    }
    // Shift
    int next = 0;
    int prev_mod = 0;
    for (int i = 0; i < qq.size() - 1; i++) {
        prev_mod = next;
        next = (prev_mod + qq[i]) / 10;
        qq[i] = (prev_mod + qq[i]) % 10;
    }
    if (qq.back() / 10 != 0) {
        prev_mod = next;
        next = (prev_mod + qq.back()) / 10;
        qq.back() = (prev_mod + qq.back()) % 10;
        qq.push_back(next);
    }
    reverse(qq.begin(), qq.end());
    return qq;
}

string multiply(string a, string b) {
    vector<int> a_int = intArray(a);
    vector<int> b_int = intArray(b);
    vector<vector<int>> res;
    vector<int> final_res;

    vector<int> temp;
    for (int i = 0; i < b_int.size(); i++) {
        temp = mulOneToMany(a_int, b_int[i]);
        for (int j = 0; j < i; i++)
            temp.push_back(0);
        res.push_back(temp);
    }
    final_res = add_vals(res);
    for (int i = 0; i < final_res.size(); i++)
        cout << final_res[i] << endl;
    return int2str(final_res);
}

int main() {
    string b = "25";
    string a = "10";

    vector<vector<int>>test;
    vector<int>qq,q;
    qq.push_back(1);
    qq.push_back(1);
    qq.push_back(1);
    qq.push_back(1);
    test.push_back(qq);
    q.push_back(1);
    q.push_back(1);
    q.push_back(1);
    q.push_back(1);
    test.push_back(q);
    for(int i=0;i<test.size();i++)
    {
        cout<< endl <<"FLAS"<< add_vals(test)[i] ;
    }
    return 0;
}
