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



int hashval(string &s) {
    int p = 29;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % mod;
        p_pow = (p_pow * p) % mod;
    }
    return hash_value;
}


int dfs(int src, int par, vector<vector<int>> &adj, vector<int> &vis){
    vis[src]=1;

    int temp =0;
    for(auto x: adj[src]){
        if(!vis[x] && x!=par){
            temp= max(temp, dfs(x, src, adj, vis));
        }
    }

    return 1+temp;
}
int chain(vector<string> words){

    int n = words.size();

    map<int,int> mp1;
    map<int,set<int>> mp2;
    for(int i=0; i<n; i++) {
        string s = words[i];
        string s2 = s.substr(0, s.length()-1);
        mp1[i]= hashval(s);
        mp2[hashval(s2)].insert(i);
    }

    vector<vector<int>> adj(n);

    for(int i=0; i<n; i++){
        int x = mp1[i];
        for(auto x: mp2[x]){
            adj[i].pb(x);
        }
    }

    int ans = 0;

    vi vis(n,0);
    vi val(n,0);

    for(int i=0; i<n; i++){
        if(vis[i]) continue;
        int temp = dfs(i,-1,adj,vis);
        ans = max(ans,temp);
    }

    cout<<ans<<endl;

}
 
void solve(){
    take_n
    vector<string> words(n);

    loop(i,0,n) cin>>words[i];

    int ans = chain(words);
    
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}