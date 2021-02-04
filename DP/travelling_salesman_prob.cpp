// Reference -> https://www.youtube.com/watch?v=QukpHtZMAtM&list=PLb3g_Z8nEv1icFNrtZqByO1CrWVHLlO5g&index=4
// Reference -> https://www.thecrazyprogrammer.com/2017/05/travelling-salesman-problem.html
// Time Complexcity -> O(n^2 * 2^n)
// Space Complexcity -> O(2^n * n)
// NOTE : Whenever we feel a need to pass a subset of set we can use this technique of digit dp
// Que. Find minimum distance to travel if travellers wishes to visit every city atleast once and reach back to his starting location at the end
#include<bits/stdc++.h>
using namespace std;

#define MAX 9999

int n=4; // Number of the places want to visit

 //Next distan array will give Minimum distance through all the position
int distan[10][10] = {                
                    {0, 10, 15, 20},
                    {10, 0, 35, 25},
                    {15, 35, 0, 30},
                    {20, 25, 30, 0}
};

int all_visited = (1<<n) -1;
int dp[16][4];


int  TSP(int visited,int position)
{
    // Initially checking whether all the places are visited or not
    if(visited==all_visited)
        return distan[position][0];

    if(dp[visited][position]!=-1)
        return dp[visited][position];
    
    // init
    int answer = MAX;

    // chack for each city
    for(int city=0;city<n;city++)
        if((visited&(1<<city))==0)  // is the city visited check
            answer = min(answer, distan[position][city] + TSP( visited|(1<<city),city));

    return dp[visited][position] = answer;
}

int main()
{
    memset(dp,-1,sizeof dp);
    cout<<"Minimum Distance Travelled by traveller is "<<TSP(1,0);

    return 0;
}