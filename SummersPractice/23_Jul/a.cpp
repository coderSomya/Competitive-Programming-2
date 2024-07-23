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
    int n, k; cin>>n>>k;

    int arr[2*n] = {0};

    arr[1]= n;
    int h = 1;
    for(int i=2; i<2*n; i+=2){
        arr[i]=n-h;
        arr[i+1]=n-h;
        h++;
    }

if(k==0){
    cout<<0<<endl;
    return;
}
    int ans = 2*n - 1;
    for(int i=1; i<2*n; i++){
        arr[i]+=arr[i-1];
        if(arr[i]>=k){
            ans = i;
            break;
        }
    }

   cout<<ans<<endl;
    
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}