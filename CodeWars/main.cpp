#include <bits/stdc++.h>
using namespace std;

string addLargeNumbers(string a,string b){
    int sum=0,carry=0;
    string res;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());

    string tmp = b;
    if(a.length()>b.length()){
        b=a;
        a=tmp;
    }
    // b > a ALWAYS
    for(unsigned int i=0;i<a.length(); i++){
        sum=((int)a[i]-48)+((int)b[i]-48)+carry;
        res =to_string(sum%10)+res;
        carry=sum/10;
    }

    for (unsigned int j = a.length() ; j < b.length(); j++){
        sum=((int)b[j]-48)+carry;
        res = to_string(sum%10) + res;
        carry=sum/10;
    }
    if (carry) res = to_string(sum/10) + res;
    return res;
}

string mulLargeNumbers(string a, string b){
    string res,final_res;
    int carry=0,prod=0;
//    vector<string> add;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    string tmp = b;
    if(a.length()>b.length()){
        b=a;
        a=tmp;
    }
    final_res = "0";
    for(int i=0;i<a.length();i++)
    {
        res="";
        carry=0;
        for(int j=0;j<b.length();j++)
        {
            prod=((int)a[i]-48)*((int)b[j]-48)+carry;
            res=(to_string(prod%10)) +res;
            carry=prod/10;
        }
        res = (carry>0)? to_string(carry)+res : res;
        for (int j=0;j<i;j++)
            res += "0";
//        add.push_bach(res);
        final_res = addLargeNumbers(final_res,res);
    }
//    for (int i = 0;i<add.length()-1;i++)
//        final_res=addLargeNumbers(add[i+1],add[i]);

    return final_res;
}

int main()
{
    string a, b;
    b="11111111111111111111111111";
    a="11111111111111111111111111";
    cout<<addLargeNumbers(a, b)<<endl;
    cout<<endl<<mulLargeNumbers(a, b)<<endl;
    return 0;
}