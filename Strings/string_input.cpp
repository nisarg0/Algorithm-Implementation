// If the input format of a string is know...
// Ex.str = "233+923i" How to extract numbers

#include<bits/stdc++.h>
using namespace std;

int main(){

    string str = "233+923i";
    int a,b;
    sscanf(str.c_str(), "%d+%di", &a, &b);
    cout << a << " " << b << endl;

//********************************* OR ***********************************

    str = "I am Nisarg and I love DS-Algo";
    vector<string> vec;

    istringstream iss(str);
    for(string s;iss >> s;)
        vec.push_back(s);

    for(int i=0;i<vec.size();i++)
        cout << vec[i] << endl;


//************************* String with spaces input ********************
    
    // string input;
    // cin.ignore();
    // getline(cin, input, '\n');

}