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

    vector<vi> v(n, vi(m));

    loop(i,0,n) loop(j,0,m) cin>>v[i][j];

    unordered_set<int> dp[n][m];

    dp[0][0] = {v[0][0]};


    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 && j==0) continue;
            unordered_set<int> st;
            if(j>0){
                for(auto x: dp[i][j-1]){
                    int gcd = __gcd(x, v[i][j]);
                    st.insert(gcd);
                }
            }
            if(i>0){
                for(auto x: dp[i-1][j]){
                    int gcd = __gcd(x, v[i][j]);
                    st.insert(gcd);
                }
            }

            dp[i][j] = st;
        }
    }

int maxi = 1;
    for(int i: dp[n-1][m-1]){
        maxi = max(maxi, i);
    }
cout<<maxi<<endl;

// cout<<"-------------"<<endl;

// loop(i,0,n){
//     loop(j,0,m){
//         for(auto x: dp[i][j]) cout<<x<<" ";
//         cout<<endl;
//     }
//     cout<<endl;
// }

// cout<<"-------------"<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}