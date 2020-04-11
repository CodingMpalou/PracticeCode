#include <iostream>
#include <string>

using namespace std;

string add_string1(string str1, string str2){
    return str1+str2;
}

string add_string2(string str1, string str2){
    string str12;
    int i;

    for(i=0;i<str1.length();i++)
        str12.push_back(str1[i]);

    for(i=0;i<str2.length();i++)
        str12.push_back(str2[i]);

    return str12;
}

string add_string3(string str1, string str2){
    string str12="";
    int i;

    for(i=0;i<str1.length()+str2.length();i++)
    {
        if(i>=str1.length())
            str12.push_back(str2[i-str1.length()]);
        else
            str12.push_back(str1[i]);
    }
    return str12;
}

string add_string4(string str1, string str2){

    for(int i=0;i<str2.length();i++)
        str1.push_back(str2[i]);
    return str1;
}

int main() {

    string str1="Hello ", str2="World", a, b, c, d;
    a=add_string1(str1, str2);
    b=add_string2(str1, str2);
    c=add_string3(str1, str2);
    d=add_string4(str1, str2);

    cout<<a<<endl<<b<<endl<<c<<endl<<d;

    return 0;
}