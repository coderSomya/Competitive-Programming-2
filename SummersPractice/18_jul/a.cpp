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

    vector<vector<int>> a(n, vi(m));

    for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin>>a[i][j];

    if(n==1 && m==1) cout<<"-1"<<endl;

    else{
        for(int i=0; i<n; i++){
            for(int j=0; j<m-1; j++){
                cout<<a[i][j+1]<<" ";
            }
            if(i!=n-1) cout<<a[i+1][0]<<" ";
            else cout<<a[0][0]<<" ";
            cout<<endl;
        }
    }
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}