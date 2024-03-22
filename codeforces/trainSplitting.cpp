/*
problem link ->
https://codeforces.com/problemset/problem/1776/F
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


bool isCompleteGraph(int n, int m){
    return m==n*(n-1)/2;
}
 
int findNotFullyConnected(const vector<vector<int>> &adj, int n, int m){

    for(int i=1; i<=n; i++){
        if(adj[i].size()!=n-1) return i;
    }
}
 
void solve(){
    int n,m;
    cin>>n>>m;
    int k=0;

    vector<vector<int>> adj(n+1);
    vector<pair<int,int>> edges;

    for(int i=0; i<m; i++){
        int u,v; cin>>u>>v;
        edges.pb({u,v});
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool isComplete = isCompleteGraph(n,m);

    vector<int> ans(m,0);
    if(!isComplete){
        int center = findNotFullyConnected(adj,n,m);

        for(int i=0; i<m; i++){
            pair<int,int> edge = edges[i];

            int x = edge.first; int y = edge.second;

            if(x==center || y==center){
                ans[i]=1;
            }
            else ans[i]=2;
        }
    }


    else{
        int center = 1;

        for(int i=0; i<m; i++){
            pair<int,int> edge = edges[i];
            int x = edge.first; int y = edge.second;

            if(x==center || y==center){
                int extra = x!=center ? x: y;
                if(extra ==2){
                    ans[i]=3;
                }
                else ans[i]=2;
            }

            else ans[i]=1;
        }
    }

  set<int> st;
  for(int i=0; i<m; i++) st.insert(ans[i]);

  k = st.size();

  cout<<k<<endl;
  for(int i=0; i<m; i++){
    cout<<ans[i]<<" ";
  }
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}