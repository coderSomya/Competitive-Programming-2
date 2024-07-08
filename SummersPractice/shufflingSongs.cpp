/*
problem link->
https://codeforces.com/problemset/problem/1950/G
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

int N; //store number of elements in current subset
int BITMASK; //bitmask for current subset
bool flag; //did we reach all elements in one round

int ans;
vector<vector<int>> adj(16);
int source= -1;

void dfs(int src, vector<int> &vis, int curr){

    vis[src]=1;
    curr++;
    if(curr==N){
        flag = true;
        return;
    }

  

    for(auto x: adj[src]){
        if(BITMASK&(1<<x) && !vis[x]){
            dfs(x, vis, curr);
        }
    }

    vis[src]=0;
    curr--;
}

void check(int mask, int n){
    BITMASK = mask;

    //we have a mask and need to check if this subset of nodes can generate one path
    flag = false;
    N = 1ll*setbits(BITMASK);
    for(int i=0; i<n; i++){
        if(BITMASK&(1<<i)){
            vector<int> vis(n,0);
            source = i;
            dfs(i,vis,0);
            if(flag) {
                break;
            }
        }
    }

    if(flag){
        ans = max(ans, N);
    }

}

void generate_mask(int i, int n, int curr_mask){
    if(i==n){
        check(curr_mask,n);
        return;
    }

    int t1 = curr_mask*2;
    int t2 = curr_mask*2 + 1;

    generate_mask(i+1,n, t1);
    generate_mask(i+1,n, t2);
}

bool match(pair<int,int> p1, pair<int,int> p2){
    return p1.first == p2.first || p1.second == p2.second;
}
 
 
void solve(){
    take_n
    map<string,int> g;
    map<string,int> a;
    int ct1 = -1;
    int ct2 = -1;
    ans = 0;

    vector<pair<int,int>> v;

    for(int i=0; i<n; i++){
        string gn, ar;
        cin>>gn>>ar;

        if(g.find(gn)==g.end()){
            ct1++;
            g[gn]=ct1;
        }
        if(a.find(ar)==a.end()){
            ct2++;
            a[ar]=ct2;
        }
        v.pb({g[gn], a[ar]});
    }


    adj.clear();
    adj.resize(n);

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(match(v[i], v[j])){
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
    }

    generate_mask(0,n,0);

    int best = n - ans;
    cout<<best<<endl;

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}