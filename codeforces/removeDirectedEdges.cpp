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


const int N = 200006;
vector<int> vis(N,0);
vector<int> dp(N,0);
vi id(N);
vi od(N);
vector<vector<int>> adj;

void dfs(int src){

    vis[src]=1;

    for(auto x: adj[src]){
        
        if(!vis[x]) dfs(x);
        if(id[x]==1) continue;
        dp[src]=max(dp[src], 1+ dp[x]);
    }

    if(od[src]==1) dp[src]=1;
}


 
void solve(){

    int n,m; cin>>n>>m;
    adj.clear();
    adj.resize(n+1);
    id.clear();
    id.resize(n+1,0);
    od.clear();
    od.resize(n+1,0);
    loop(i,0,m){
        int u,v; cin>>u>>v;
        adj[u].pb(v);
        id[v]++;
        od[u]++;
    }

    loop(i,1,n+1) dp[i]=1, vis[i]=0;

  int ans=-1;
    for(int i=1; i<=n; i++){
        if(!vis[i]) dfs(i);
        ans=max(ans, dp[i]);
    }

    cout<<ans<<endl;
}
  
  
int32_t main(){
// int t;
// cin>>t;
// while(t--)
 solve();
return 0;
}