/*
problem link ->
https://codeforces.com/problemset/problem/1970/E1
*/

#include <bits/stdc++.h>
using namespace std;
#define loop(i,l,r)     for(int i=l; i<r; i++)
#define int             long long
#define pb              push_back
#define vi              vector<int>
#define mkp             make_pair<int,int>
#define umpii           unordered_map<int,int>
#define maxheap         priority_queue<int>
#define minheap         priority_queue<int, vi,greater<int>>
#define setbits(x)      __builtin_popcountll(x)
#define zerobits(x)     __builtin_ctzll(x)
#define in_arr(A,n)     loop(i,0,n) cin>>A[i];
#define p_arr(A,n)      loop(i,0,n) cout<<A[i]
;
#define pln_arr(A,n)    loop(i,0,n) cout<<A[i]<<endl
#define take_n          int n; cin>>n;
#define take_arr        int arr[n]; loop(i,0,n) cin>>arr[i];
  
  
const int mod= 1e9+7;
const int inf= 1e15;

/*
(day, mid, used, where) 
n*2*2*m
4*10^5
if(!mid) ->{
  //go back
  (day,mid,used,where) += shorts[where]*(day+1,0,0,-1)
  if(used) (day,mid,used, where) += longs[where]*(day+1,0,0,-1) 
}
else{
//go anywhere
for(train in trails):
if(shorts[trail]) (day,mid,used,where)+= shorts[i]*(day,1,1,trail)
if(shorts[trail]) (day,mid,used,where)+= longs[i]*(day,1,0,trail)
}
*/
int n,m;
int shorts[10000];
int longs[100000];

int dp[1001][2][2][101];

int rec(int day, int mid, int used, int where){

    if(day==n && mid==0) return 1;
    int temp = 0;

    if(dp[day][mid][used][where]!=-1) return dp[day][mid][used][where];

    if(mid){
        //we are starting from the lake, i.e we have done half the day
        for(int i=1; i<=m; i++){
            temp+=(shorts[i]*rec(day,0,used,i))%mod;
            temp%=mod;
            if(used) temp+=(longs[i]*rec(day,0,used,i))%mod;
            temp%=mod;
        }
    }
    else{
        // we are starting a new day
        temp+=(shorts[where]*rec(day+1,1,1,0))%mod;
        temp%=mod;
        temp+=(longs[where]*rec(day+1,1,0,0))%mod;
        temp%=mod;
    }

    return dp[day][mid][used][where]=temp;
}
 
 
void solve(){
    cin>>m>>n;

    for(int i=0; i<m; i++){
        cin>>shorts[i+1];
    }
    for(int i=0; i<m; i++){
        cin>>longs[i+1];
    }

    memset(dp,-1,sizeof(dp));

    int ans = rec(0,0,0,1);

    cout<<ans<<endl;
}
  
  
int32_t main(){
// int t;
// cin>>t;
// while(t--)
solve();
return 0;
}