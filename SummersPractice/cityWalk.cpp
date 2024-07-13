/*
problem link ->
https://codeforces.com/problemset/problem/1929/D
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
  
  
const int mod= 998244353;
const int inf= 1e15;


/*

for any node,
x1, x2, x3.. xn
x1*x2*x3 + x1*x2*x4 + x2*x3*x4 .....
x1*x2*(sum - (x1+x2))
sum = n-1
we can compute this in quadratic time

is it possible in linear?

x1*(x2*x3 + x3*x4 ..... ) + x2*(x1*x3 + )

x1*(x2*(x3+x4....xn) + x3*(x2+x4....))

using newton formula,
sum of product of numbers whose sum is n, taken 3 at a time

= 1/6*(n^3 - 3*n*p2 + 2*p3)

p2 = sum of squares of numbers
p3 = sum of cubes of numbers
*/

const int N = 3e5+ 5;
int sz[N];

int n;
int ans;

int mod_inv_6 = 166374059;

void dfs(int src, int par,const vector<vector<int>> &adj){

    sz[src]= 1;
    vi v;
    for(auto x: adj[src]){
        if(x!=par){
            dfs(x, src, adj);
            v.pb(sz[x]);
            sz[src]+=sz[x];
        }
    }
    if(n-sz[src] !=0) v.pb(n - sz[src]);

    int p2 = 0;
    int p3 = 0;

    if(v.size()>=3){
    for(auto x: v){
        p2+= (x*x)%mod;
        p2%=mod;
        p3+= (((x*x)%mod)*x)%mod;
        p3%=mod;
    }

    int temp = (((n-1)*(n-1))%mod*(n-1)%mod);
    temp+= (2*p3)%mod;
    temp%=mod;
    temp = (temp%mod - (3*(n-1)*p2)%mod + mod)%mod;

    temp*= mod_inv_6;
    temp%=mod;

    ans+= temp;

    ans%=mod;
    }
}
 
void solve(){
    cin>>n;
    ans = 0;
    vector<vector<int>> adj(n);
    for(int i=0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    ans+= (1 + n + (n*(n-1)/2)%mod)%mod;
    ans%=mod;

    dfs(1,-1,adj);

    cout<<ans<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}