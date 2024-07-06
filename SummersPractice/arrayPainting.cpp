/*
problem link ->
https://codeforces.com/problemset/problem/1849/D
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
 

void dfs(int src, int par,  vector<int> &vis,  const vector<vector<int>> &adj){

    vis[src]=true;

    for(int child: adj[src]){
        if(child!=par) dfs(child, src, vis, adj);
    }
}

int find_ans(vector<int> &v, int n){
      vector<vector<int>> adj(n);

    set<int>added;

    for(int i=0; i<n; i++){
        if(v[i]==2){
            if(i!=n-1 && v[i+1]==2){
                adj[i+1].pb(i);
                adj[i].pb(i+1);
            }
        }
        if(v[i]==1){
            if(i!=0 && v[i-1]==2){
                adj[i-1].pb(i);
                adj[i].pb(i-1);
                continue;
            }
            else if(i<n-1 && (v[i+1]==2 || v[i+1]==1)){
                added.insert(i);
                adj[i+1].pb(i);
                adj[i].pb(i+1);
            }
        }

        if(v[i]==0){
            if(i!=0){
                if(v[i-1]==2){
                    adj[i-1].pb(i);
                    adj[i].pb(i-1);
                    continue;
                }
                else if(v[i-1]==1 && added.find(i-1)==added.end()){
                    adj[i-1].pb(i);
                    adj[i].pb(i-1);
                    continue;
                }
            }
            if(i!=n-1){
                if(v[i+1]==2 || v[i+1]==1){
                    added.insert(i+1);
                    adj[i+1].pb(i);
                    adj[i].pb(i+1);
                }
            }
        }
    }



    vector<int> vis(n,0);
    int ans = 0;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            ans++;
            dfs(i, -1, vis, adj);
        }
    }

    return ans;
}
 
void solve(){
    int n; cin>>n;

    vi v(n);
    loop(i,0,n) cin>>v[i];

    int ans = find_ans(v,n);

    reverse(v.begin(), v.end());
    ans = min(ans, find_ans(v, n));

    cout<<ans<<endl;

}
  
  
int32_t main(){
// int t;
// cin>>t;
// while(t--) 
solve();
return 0;
}