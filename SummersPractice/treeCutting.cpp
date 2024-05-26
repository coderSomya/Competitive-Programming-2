/*
problem link ->
https://codeforces.com/problemset/problem/1946/C
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

const int N = 1e5+6;
int n, k;

vector<vector<int>> adj(N);
vector<int> sz(N);

int curr;
int ct;

void dfs(int src, int par){

    sz[src]=1;

    for(auto x: adj[src]){
        if(x!=par){
            dfs(x, src);
        }
    }

    for(auto x: adj[src]){
        if(x!=par){
            sz[src]+=sz[x];
        }
    }

    if(sz[src]>=curr){
        ct++;
        sz[src]=0;
    }
}
 
void solve(){

    cin>>n>>k;

    adj.clear();
    adj.resize(n+1);
    sz.clear();
    sz.resize(n+1);


    for(int i=0; i<n-1; i++){
        int u,v;
        cin>>u>>v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    int l=1;
    int h=n;
    int ans = 1;
    while(l<=h){
        int mid = (l+h)/2;
        ct=0;
        curr= mid;

        sz.clear();
        sz.resize(n+1,0);
        dfs(1,-1);

        if(ct>k){
            ans= curr;
            l=mid+1;
        }
        else h=mid-1;
    }

    cout<<ans<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}