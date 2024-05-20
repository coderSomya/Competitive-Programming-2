/*
problem link ->
https://codeforces.com/problemset/problem/1969/C
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

const int MAX_N= 3*1e5+3;
const int MAX_K= 11;
 
 
vector<vector<int>> preprocess(const vector<int>& arr) {
    int n = arr.size();
    int k = log2(n) + 1;

    vector<vector<int>> st(n, vector<int>(k));
    
    for (int i = 0; i < n; ++i) {
        st[i][0] = arr[i];
    }
    
    for (int j = 1; (1 << j) <= n; ++j) {
        for (int i = 0; (i + (1 << j) - 1) < n; ++i) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    
    return st;
}

int query(const vector<vector<int>>& st, int l, int r) {
    int length = r - l + 1;
    int k = log2(length);
    return min(st[l][k], st[r - (1 << k) + 1][k]);
}

vector<vector<int>> dp(MAX_N, vector<int>(MAX_K));

int n, k;
int rec(int i, int k, vector<vector<int>> &st, vector<int> &v){

// return minimum sum if we are at i and we can at max k so far

if(i<0) return 0;
if(dp[i][k]!=-1) return dp[i][k];
int ans = inf;
if(k==0){
    int temp = rec(i-1,k,st,v);
    return dp[i][k]=v[i]+temp;
}

for(int j=0; j<=k; j++){
    //i..i-j

    int mini = query(st, max(1ll*0, i-j), i);
    int temp = rec(i-j-1, k-j, st, v);

    ans = min(ans, temp+ (j+1)*mini);
}

return dp[i][k] = ans;

}

void solve(){
    cin>>n>>k;
    vector<int> v(n);

    for(int i = 0; i < n; ++i){
        cin>>v[i];
    }

    vector<vector<int>> st = preprocess(v);

    for(int i=0; i<n; i++){
        for(int j=0; j<=k; j++){
            dp[i][j]=-1;
        }
    }
    int ans = rec(n-1, k, st, v);
    cout<<ans<<endl;

    // run a dp

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}