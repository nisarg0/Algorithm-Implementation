// Reference -> https://www.youtube.com/watch?v=7FmL-WpTTJ4
// We are using bitmask to store the numbers between 1 and 10 (in integers)
// left shifting (x<<y) is equivalent to multiplying x with 2^y 
// right shifting (x>>y) is equivalent to dividing x with 2^y. 

#include<bits/stdc++.h>

using namespace std;

// If element is present it will get deleted and if its not there it will get added
void erase_or_add(int n, int& subset)
{
    subset = subset ^ 1<<(n-1);
}
void display(int subset)
{
    cout<<"The subset is: ";
    // i is the ith bit from right to left 
    // 0th  bit represents 1
    for(int i=0;i<9;i++)
    {
        if(1<<i&subset)
            cout << i+1<<" ";
    }
    cout<<"\n";
}

int main()
{
    // num represents subset of numbers from 1 to 10
    int num = 15;
    display(num);
    // delete the d from subset num
    int d = 4;
    erase_or_add(d,num);
    display(num);

    d=9;
    erase_or_add(d,num);
    display(num);
}