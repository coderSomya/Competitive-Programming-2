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

const int N = 1000;

int comp[N];
int hard[N];

int n,m; 

int dp[N][N];

int rec(int i, int j){
    if(i==n) return 0;

    //removed = i;
    // end of 2 = m-i +j-1 

    if(dp[i][j]!=-1) return dp[i][j];


    int t1 = rec(i+1,j);
    int t2 = rec(i+1,j+1);

    t1+= hard[m-i+j-1]*comp[i];
    t2+= hard[j]*comp[i];

    int mini = max(t1,t2);

    return dp[i][j] = mini;
    
}


void solve(){

    cin>>n>>m;

    for(int i=0; i<n; i++) cin>>comp[i];
    for(int i=0; i<m; i++) cin>>hard[i];

    memset(dp,-1, sizeof(dp));

    int ans = rec(0,0);

    cout<<ans<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}