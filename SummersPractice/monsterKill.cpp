/*
problem link ->
https://codeforces.com/contest/1988/problem/D
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

const int N = 300006;

vector<vector<int>> dp(N, vector<int>(2));
vi val(N);

void dfs(int src, int par, const vector<vector<int>> &adj){
    for(auto x: adj[src]){
        if(x!=par){
            dfs(x, src, adj);
        }
    }

    dp[src][0]=dp[src][1]=0;
    for(auto x: adj[src]){
        if(x!=par){
            dp[src][0] += dp[x][1];
            dp[src][1] += min(dp[x][1], dp[x][0]);
        }
    }

    dp[src][0]+= val[src];
    dp[src][1]+= 2*val[src];
}
 
void solve(){
    int n; cin>>n;
    
    vector<vector<int>> adj(n+1);

    for(int i=0; i<n; i++) cin>>val[i+1];
    for(int i=0; i<n-1; i++){
        int u,v; cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1,-1, adj);

    int ans = min(dp[1][0], dp[1][1]);

    cout<<ans<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}