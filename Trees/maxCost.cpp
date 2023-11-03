/*
problem link->
https://codeforces.com/problemset/problem/1092/F
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

const int N = 200005;
vector<vector<int>>child(N);
vector<int> sz(N);
vector<int> val(N);
vector<int> ans(N);

 

void dfs(int src, int par){
    sz[src]=val[src];

    for(auto x: child[src]){
        if(x==par) continue;
        dfs(x, src);
        sz[src]+=sz[x];
    }
}

void ansroot(int src, int par, int dist){
    
    ans[1]+= val[src]*dist;

    for(auto x: child[src]){
        if(x!=par) ansroot(x,src, dist+1);
    }
}
int total;
void extend(int src, int par){
    
    if(par!=0){
        ans[src]=ans[par]+total-2*sz[src];
    }

    for(auto x: child[src]){
        if(x!=par){
            extend(x, src);
        }
    }
}
 
void solve(){
    int n; cin>>n;
    total=0;
   loop(i,1,n+1) {
    cin>>val[i]; total+=val[i];
    }

   loop(i,0,n-1)
   {
    int u,v; cin>>u>>v;
    child[u].pb(v) ;
    child[v].pb(u) ;
   }

   dfs(1,0);


   ansroot(1,0,0);

   extend(1, 0);

   int res=-1;

   for(int i=1; i<=n; i++){
    res=max(res, ans[i]);
   }

   
   cout<<res<<endl;




}
  
  
int32_t main(){
// int t;
// cin>>t;
// while(t--) 
solve();
return 0;
}