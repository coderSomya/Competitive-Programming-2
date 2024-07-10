/*
problem link ->
https://codeforces.com/problemset/problem/1949/I
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


int ct;

void dfs(int src,const vector<vector<int>> &adj, vector<int> &vis, vector<int> &color,  int col){
    
    ct+= col;
    vis[src]=1;
    color[src]=col;
    for(auto x: adj[src]){
        if(!vis[x]){
            dfs(x, adj, vis, color, -1*col);
        }
        else{
            if(color[x]==color[src]){
                ct=inf;
                return;
            }
        }
    }
}

int square(int x) {
    return  x*x;
}

int dist(pair<int,int> p1, pair<int,int> p2){

    int x_diff = p1.first - p2.first;
    int y_diff = p1.second - p2.second;

    int val = square(x_diff) + square(y_diff);

    return val;
}


 
void solve(){
    take_n
    vi ex,wai,ar;
    for(int i=0; i<n; i++){
        int x,y,r;
        cin>>x>>y>>r;
        ex.pb(x);
        wai.pb(y);
        ar.pb(r);
    }

    vector<vector<int>> adj(n);
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n;j++){
            int center_dist = dist({ex[i], wai[i]}, {ex[j], wai[j]});
            if(center_dist == square(ar[i])+square(ar[j]) + 2*ar[i]*ar[j]){
                //tangent
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
    }

    for(int i=0; i<n; i++){
            ct=0;
            vector<int> vis(n,0);
            vector<int> col(n,0);
            dfs(i, adj, vis, col, 1);
            if(ct<0){
                cout<<"YES"<<endl;
                return;
            }
            vis.resize(n,0);
            ct=0;
            dfs(i,adj,vis,col, -1);
            if(ct<0){
                cout<<"YES"<<endl;
                return;
            }
    }

    cout<<"NO"<<endl;
}
  
  
int32_t main(){
// int t;
// cin>>t;
// while(t--)
solve();
return 0;
}