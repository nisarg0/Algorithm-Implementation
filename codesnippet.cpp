// Nisarg Gogate
// VNIT

#include<bits/stdc++.h>
#define DEBUG_ON 0
#define int long long 
#define TESTCASES false
#define FASTIO true
#define DBG(x) if(DEBUG_ON) cout << #x << " == " << x << endl
#define FF first
#define SS second

const int inf  = (int)1e18 + 1;
const int SIZE = (int)1e5+3;
const int MOD = (int)1e9+7;
using namespace std;

int exp(int x,int n)
{
    int ret= 1;
    while(n>0)
    {
        if(n%2)ret=(ret*x)%MOD;
        x=(x*x)%MOD;
        n=n/2;
    }
    return ret%MOD;
}
int inv(int x)
{
    return exp(x,MOD-2);
}
 
int ncr(int n,int r)
{
    if(r==0)return 1;
    if(n<r)return 0;
    int ret = n*ncr(n-1,r-1);
    ret%=MOD;
    ret*=inv(r);
    ret%=MOD;
    return ret;
}

int solve(int n)
{
    int i,j,ans=0;
    vector<int> arr(n,0);
    for (auto &it : arr) cin >> it;
   
}

void main_code()
{
	int i,j,n,k;
    cin>>n;
    cout<<solve(n)<<endl;
}

signed main()
{
    if(FASTIO)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    int T = 1;
 
    if(TESTCASES)
        cin >> T;

    while(T--)
        main_code();
    
}