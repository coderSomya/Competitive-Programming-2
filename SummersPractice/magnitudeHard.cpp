/*
problem link ->
https://codeforces.com/problemset/problem/1984/C2
*/

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
  
  
const int mod= 998244353;
const int inf= 1e15;

int pow2[200010];
 
 
void solve(){

    int n; cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    int mini = 0;

    int sum = 0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
        mini = min(mini, sum);
    }

    if(mini ==0){
        cout<<pow2[n]<<endl;
        return;
    }

    int curr =0;
    int ans = 0;
    int abs = 0;
    for(int i=0; i<n; i++){
        curr+= arr[i];

        if(curr==mini){
            ans = (ans + pow2[n-i-1 + abs])%mod;
        }
        if(curr>=0) abs++;
    }

    cout<<ans<<endl;
}
  
  
int32_t main(){

pow2[0] = 1;
for(int i=1; i<=2e5; i++) pow2[i]= (pow2[i-1]*2)%mod;

int t;
cin>>t;
while(t--) solve();
return 0;
}