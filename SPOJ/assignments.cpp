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

const int N = 20;

int dp[N][(1<<N)+1];

vector<vector<int>> masks(N, vector<int>(N,0));
int n;

int func(int pos, int mask){
    
    int temp=0;
    if(pos==n) return 1;

    if(dp[pos][mask]!=-1) return dp[pos][mask];

    for(int i=0; i<n; i++){
        if(mask&(1<<i) && masks[pos][i]){
            int temp_mask= (1<<i)^mask;
            temp+=func(pos+1, temp_mask);
        }
    }

    return dp[pos][mask]=temp;
}
 
void solve(){

    memset(dp, -1, sizeof(dp));


    cin>>n;
    for(int i=0;i<n; i++){
        for(int j=0; j<n; j++){
            cin>>masks[i][j];
        }
    }

    int init_mask=(1<<n)-1;
    //all are available

    int ans = func(0, init_mask);

    cout<<ans<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}