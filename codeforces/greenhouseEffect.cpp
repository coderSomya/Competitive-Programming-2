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
    int n,m; cin>>n>>m;

    vi v(n);
    for(int i=0; i<n; i++){
        int a; double b;
        cin>>a>>b;
        v[i]=a;
    }

    int dp[n]={0};

    int ans=n;
    for(int i=0; i<n; i++){
        int maxi=1;
        for(int j=0; j<i; j++)
        {
            if(v[j]<=v[i]){
                maxi=max(maxi, 1+dp[j]);
            }
        }

        dp[i]=maxi;
        ans=min(ans, n-dp[i]);
    }

    cout<<ans<<endl;
}
  
  
int32_t main(){
// int t;
// cin>>t;
// while(t--)
 solve();
return 0;
}