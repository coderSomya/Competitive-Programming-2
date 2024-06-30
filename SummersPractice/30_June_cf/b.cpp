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
    int n; cin>>n;
    vi v(n);
    loop(i,0,n) cin>>v[i];

    vi arr;
    for(int i=1; i<n; ++i){
        if(v[i]<v[i-1]){
            arr.pb(v[i-1]-v[i]);
            v[i]=v[i-1];
        }
    }

    sort(arr.begin(), arr.end());

    n = arr.size();
    int ans = 0;

    int curr=0;
    for(int i=0; i<n; i++){
        arr[i]-=curr;
        curr+=arr[i];

        ans+= arr[i]*(n-i+1);
    }

    cout<<ans<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}