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

int diam;
const int N = 1e5+5;

int a,b,x,y;

vector<vector<int>> adj(N);
int dist[N];
int who[N];


void height(int src, int par){
   
   if(src==a) dist[src]=0;
   else dist[src]=dist[par]+1;

   if(src==b) who[src]=1;

   for(auto x: adj[src]){
    if(x!=par) {
        height(x, src);
        if(who[x]) who[src]=1;
    }
   }
    
}

int check(int src){

    int maxi=0;
    
    for(auto x: adj[src]){
        if(!who[x]) maxi=max(maxi, dist[x]);
    }

    return maxi;
}




void dfs(int src, int par){

    int maxi=0;
    int smaxi=0;

    for(auto x: adj[src]){
         if(x==par) continue;

         if(dist[x]>=maxi){
            smaxi=maxi;
            maxi=dist[x];
         }
         else if(dist[x]>smaxi) smaxi=dist[x];
    }

    int temp=maxi+smaxi+1;
    diam=max(diam, temp);

    for(auto x: adj[src]){
        if(x!=par) dfs(x, src);
    }
}
 
 
void solve(){
    int n; cin>>n;
    adj.clear();
    adj.resize(n+1);
    cin>>a>>b>>x>>y;

    loop(i,0,n+1) who[i]=0;

   
    loop(i,0,n-1){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    height(a,-1);
    diam=0;
    dfs(a,-1);


    if(diam> 2*x && dist[b]>x && y>2*x ){
        cout<<"Bob"<<endl;
    }
    else cout<<"Alice"<<endl;


}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}