/*
problem link->
https://codeforces.com/problemset/problem/1917/C
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
  
  
const int mod= 1e9+7;
const int inf= 1e15;

int res(vi &a, vi &b, int n, int k, int d, int start){

    int ans = 0;
    for(int i=1; i<=min(2*n,d); i++){
    //either stop here
        int r = 0;
        for(int j=0; j<n; j++){
            r+= a[j]==j+1;
        }

        int temp = r + (d-i)/2;
        ans = max(ans, temp);
        for(int j=0; j<b[(i+start-1)%k]; j++){
            a[j]+=1;
        }
    }

    return ans;
}
 
 
void solve(){

    int n,k,d; cin>>n>>k>>d;

    vi a(n);
    loop(i,0,n) cin>>a[i];
    vi b(k);
    loop(i,0,k) cin>>b[i];

    vi c(a);

    // each step, see how many items can u make equal to themselves
    //at next step

    // score r, add1, score 1, add1, score 1....
    // r + (d-i)/2
    int ans = res(a,b,n,k,d,0);

    for(int i=0; i<b[0]; i++){
        c[i]+=1;
    }

    ans = max(ans, res(c,b,n,k,d-1,1));

    cout<<ans<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}