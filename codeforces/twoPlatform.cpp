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

    take_n
    int k; cin>>k;
    vi v(n);
    loop(i,0,n) cin>>v[i];
    loop(i,0,n){
        int y ; cin>>y;
    }

    sort(v.begin(), v.end());

    int dp[n];

    for(int i=n; i>=0; i--){
      //starting at i;

      int l=i; int h=n-1;
      int res=i;
      while(l<=h){
        int mid=(l+h)/2;


        if(v[mid]-v[i]<=k){
            l=mid+1;
            res=mid;
        }
        else h=mid-1;
      }

      dp[i]=res-i+1;
    }


    int pref[n];
    pref[n-1]=dp[n-1];
    for(int i=n-2; i>=0; i--){
        pref[i]=max(pref[i+1], dp[i]);
    }

    int ans=-1;
    for(int i=0; i<n; i++){
        int best= dp[i];
        if(i+dp[i]<n){
            best+=pref[i+dp[i]];
        }

        ans=max(ans, best);
    }


    cout<<ans<<endl;

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}