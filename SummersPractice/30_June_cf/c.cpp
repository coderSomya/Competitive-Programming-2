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
    int n; 
    cin>>n;

    vi v(n);
    loop(i,0,n) cin>>v[i];

    int ans = 0;
    int res[n];
    for(int i=n-1; i>=0; i--){
        if(i==n-1) res[i]=v[i];
        else{
            if(v[i]>v[i+1]){
                int wait = res[i+1]-v[i+1];
                int first = v[i]-v[i+1];
                if(wait>=first){
                    res[i]=res[i+1]+1;
                }
                else{
                    res[i]=v[i];
                }
            }
            else{
                res[i]=res[i+1]+1;
            }
        }
    }

    for(int i=0; i<n; i++) ans = max(ans, res[i]);

    cout<<ans<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}