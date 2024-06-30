/*
problem link ->
https://codeforces.com/problemset/problem/1986/F
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

int nc2(int x){
    if(x<2) return 0;

    return (x*(x-1))/2;
}


//for articulation


void dfs_art(int u, vector<vector<int>>& adj, vector<int>& disc, vector<int>& low, vector<int>& parent, vector<pair<int, int>>& bridges, int& time) {
    disc[u] = low[u] = ++time;

    for (int v : adj[u]) {
        if (disc[v] == -1) {
            parent[v] = u;
            dfs_art(v, adj, disc, low, parent, bridges, time);
            low[u] = min(low[u], low[v]);

        
            if (low[v] > disc[u]) {
                bridges.push_back({u, v});
            }
        } else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

vector<pair<int, int>> findBridges(int n, vector<pair<int, int>>& edges) {
    vector<vector<int>> adj(n);
    for (auto& edge : edges) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }

    vector<int> disc(n, -1), low(n, -1), parent(n, -1);
    vector<pair<int, int>> bridges;
    int time = 0;

    for (int i = 0; i < n; ++i) {
        if (disc[i] == -1) {
            dfs_art(i, adj, disc, low, parent, bridges, time);
        }
    }

    return bridges;
}


void dfs_sz(int src, int par, int sz[], vector<vector<int>> &adj){

    sz[src]=1;

    for(auto x: adj[src]){
        if(x==par) continue;

        dfs_sz(x, src, sz, adj);
        sz[src]+= sz[x];
    }
}

void dfs_tree(int node, vector<vector<int>>& adj, vector<vector<int>>& treeAdj, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            treeAdj[node].push_back(neighbor);
            treeAdj[neighbor].push_back(node);
            dfs_tree(neighbor, adj, treeAdj, visited);
        }
    }
}

vector<vector<int>> createTree(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<vector<int>> treeAdj(n);
    vector<bool> visited(n, false);

    // Start DFS from the first node (assuming the graph is connected)
    dfs_tree(0, adj, treeAdj, visited);

    return treeAdj;
}

void solve(){

    int n,m; cin>>n>>m;

    vector<vector<int>> adj(n);

    vector<pair<int,int>> edges(m);

    loop(i,0,m){
        int u,v; cin>>u>>v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);

        edges[i] = {u,v};
    }

    //get articulation edges

    vector<pair<int,int>> art = findBridges(n,edges);

    //construct mst

    vector<vector<int>> tree = createTree(adj);

    //sizes

    int sz[n];
    dfs_sz(0, -1, sz, tree);

    //ans

    /*
    for each aritculaltions
    */

   int ans = nc2(n);
   for(auto x: art){
      int u = x.first;
      int v = x.second;

      int mini = min(sz[u],sz[v]);

      int temp = nc2(mini)+ nc2(n-mini);

      ans = min(ans, temp);
   }

   cout<<ans<<endl;


}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}