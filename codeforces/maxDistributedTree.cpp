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

const int N = 2000000;
vector<vector<int>> adj(N);
vi val(N);
vi sz(N);
int n;

void dfs(int src, int par){
  
  sz[src]=1;
  for(auto x: adj[src]){
    if(x!=par) {
        dfs(x, src);
        sz[src]+=sz[x];
    }
  }
  val[src]=sz[src]*(n-sz[src]);
}
 
 
void solve(){

    cin>>n;
    adj.clear();
    adj.resize(n+1);
    val.clear();
    val.resize(n+1,0);
    sz.clear();
    sz.resize(n+1,0);
    
    loop(i,0,n-1){
        int a,b; cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int m; cin>>m;

    vi fact(m);
    for(int i=0;i<m;i++) cin>>fact[i];


    //fit these factors in n-1 places;
     sort(fact.rbegin(), fact.rend());

     //calculate the vals;
     dfs(1,0);

     vi values;
     for(int i=2; i<=n; i++){
        values.pb(val[i]);
     }

     sort(values.rbegin(), values.rend());

     int ans=0;
     
     if(n-1>m){
        for(int i=0; i<m; i++){
            ans+=(values[i]%mod*fact[i]%mod)%mod;
            ans%=mod;
        }
        int r=n-1-m;
        for(int i=0; i<r; i++){
            ans+=values[m+i]%mod;
            ans%=mod;
        }
     }
     else{
         
         int r =m-(n-1);

         for(int i=0; i<r; i++){
            fact[r]=(fact[r]*fact[i])%mod;
         }

         for(int i=0; i<n-1; i++){
            ans+=(values[i]%mod*fact[r+i]%mod)%mod;
            ans%=mod; 
         }
     }
     cout<<ans<<endl;

    //  cout<<"values: "<<endl;
    //  for(int i=0; i<n - 1; i++){
    //     cout<<values[i]<<" ";
    //  }
    //  cout<<endl;

    //  cout<<"factors: "<<endl;
    //  for(int i=0; i<m; i++){
    //     cout<<fact[i]<<" ";
    //  }
    //    cout<<endl;

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}