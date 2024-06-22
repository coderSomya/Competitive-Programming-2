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

    int m,x;
    cin>>m>>x;
    int max_sum = 0;
    int c[m];
    int h[m];

    for(int i=0; i<m; i++){
        cin>>c[i]>>h[i];
        max_sum+=h[i];
    }
    int dp[m][max_sum+1];

    //max_sum is the max sum that can be MADE

    for(int i=0; i<m; i++){
        for(int j=0; j<=max_sum; j++){
            dp[i][j] = -inf;
        }
    }

    //dp(i,j)-> how much money will i have in pocket if i want j happiness by the end of ith day

    //dp(i,j) -> if(dp(i-1,j) was positive) dp(i-1, j)+x

    // dp(i,j) -> dp(i-1, j-h[i]) if dp(i-1,j-h[i])>c[i]

    // dp(i,j+1) atleast




    for(int i=0; i<m; i++){
        dp[i][0] = (i+1)*x;
        // i'll have all my salary till here if i want zero happiness
    }

    if(c[0]==0){
        for(int i=0; i<=h[0]; i++){
            dp[0][i]=x;
        }
    }

    for(int i=1; i<m; i++){
        for(int j=max_sum; j>=1; j--){
            dp[i][j]=-inf;

            if(dp[i-1][j]>=0){
                 dp[i][j] = max(dp[i][j], x+ dp[i-1][j]);
            }

            if(j-h[i]>=0){
                //how much did i have in the pocket 
                    if(dp[i-1][j-h[i]]>=c[i]){
                        dp[i][j]=max(dp[i][j], dp[i-1][j-h[i]]+x-c[i]);
                    }
            }

            if(j+1<=max_sum) dp[i][j] = max(dp[i][j], dp[i][j+1]);
        }
    }

    int ans = 0;

    for(int happiness = 0; happiness <= max_sum; happiness++){
        if(dp[m-1][happiness]>=0) ans=happiness;
    }

    cout<<ans<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}