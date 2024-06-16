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

int n,a,b;

int f (int i){
if(i<0) return 0;
  int temp = b*i - (i*(i+1))/2 + i + (n-i)*a;
  return temp;
}
 
 
void solve(){

    cin>>n>>a>>b;

     int ans = a*n;

     int k1 = b - a + 1;
     int k2 = b - a;
     int k3 = b - a -1;
     int k4 = min(n,b);

     /*
     k = 1
     4 4 5
     4 
     */

     if (k1 <= min(n,b)){
        ans = max(ans,f(k1));
     }

     if( k2<= min(n,b)){
        ans = max(ans, f(k2));  
     }

     if(k3 <= min(n,b)){
        ans = max(ans, f(k3));
     }

     ans = max(ans, f(k4));

    cout<<ans<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}