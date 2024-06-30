/*
problem link->
https://codeforces.com/problemset/problem/1970/G1
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


int x;


void dfs_tree(int src, int par, const vector<vector<int>> &adj, int sizes[]){

    sizes[src]=1;

    for(auto x: adj[src]){
        if(x!=par){
            dfs_tree(x, src,adj, sizes);
            sizes[src]+=sizes[x];
        }
    }
}
int tree_prob(const vector<vector<int>> &adj, int n, int m){
    int sizes[n+1] = {0};

    dfs_tree(1,0,adj, sizes);

    int ans = inf;

    for(int i=2; i<=n; i++){
        int temp = sizes[i]*sizes[i] + (n - sizes[i])*(n - sizes[i]);
        ans = min(ans, temp);
    }
    return ans;
}

void dfs_connected(int src, vector<int> &vis, const vector<vector<int>> &adj){
    x++;
    vis[src]=1;
    for(auto neigh: adj[src]){
        if(!vis[neigh]){
            dfs_connected(neigh, vis, adj);
        }
    }
}

set<int> merge(set<int> a, set<int> b){

    if(a.size()>b.size()){
        for(auto elem: b){
            a.insert(elem);
        }
        return a;
    }
    else{
        for(auto elem: a){
            b.insert(elem);
        }
    return b;
    }
}
 
int math_prob(const vector<int> &v, int n, int c){
    set<int> st;

    for(int i=0; i<v.size(); i++){
        set<int> ns;
        ns.insert(v[i]);
        for(auto it: st){
            int elem = v[i]+it;
            ns.insert(elem);
        }        

        st = merge(ns, st);
    }

    int ans = inf;

    for(auto x: st){
        int temp = x*x + (n-x)*(n-x) + (v.size()-2)*c;
        ans = min(ans, temp);
    }

    return ans;
}
void solve(){
    int n,m,c;
    cin>>n>>m>>c;

    vector<vector<int>> adj(n+1);

    loop(i,0,m){
        int u,v;
        cin>>u>>v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    vector<int> sz;
    vector<int> vis(n+1,0);

    for(int i=1; i<=n; i++){
        if(vis[i]) continue;
        x=0;
        dfs_connected(i,vis, adj);
        sz.pb(x);
    }

    int res=0;


    if (sz.size()==1){
        res = tree_prob(adj,n,m);
    }
    else{
        res = math_prob(sz,n,c);
    }

    cout<<res<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}