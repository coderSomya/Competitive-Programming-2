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
 
 
void solve(){
    int n,m,k;
    cin>>n>>m>>k;

    char arr[n+2];
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    arr[0]=arr[n+1]='L';

    int dp[n+2];
    dp[n+1]=0;

    for(int i=n; i>=0; i--){
        if(arr[i]=='C') dp[i]=inf;
        if(arr[i]=='W'){
            dp[i]=dp[i+1]+1;
        }
        if(arr[i]=='L'){
            dp[i]=inf;
            for(int j=1; j<=m && i+j<=n+1; j++){
                dp[i]=min(dp[i],dp[i+j]);
            }
        }
    }


    if(dp[0]<=k){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}