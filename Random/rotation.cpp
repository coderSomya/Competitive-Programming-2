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

vector<int> f(vector<int> a, vector<int> rot){

    int maxi = -1;
    int idx = -1;

    int n = a.size();

    for(int i=0; i<n; i++){
        if(a[i]>maxi){
            maxi = a[i];
            idx = i;
        }
    }

    vi indices(rot.size());

    for(int i=0; i<rot.size(); i++){
        indices[i] = (idx-rot[i]+10000000*n)%n;
    }

    for(auto i: indices) cout<<i<<" ";

    return indices;
}
 
 
void solve(){
    int n, m; cin>>n>>m;
    vi a(n), rot(m);
    loop(i,0,n) cin>>a[i];
    loop(i,0,m) cin>>rot[i];

    f(a,rot);
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}