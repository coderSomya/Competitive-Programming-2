/*
problem link ->
https://codeforces.com/problemset/problem/1989/D
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

const int A = 1e6+1;

int best[A];
 
void solve(){

    int n,m; cin>>n>>m;

    vi a(n), b(n), c(m);

    loop(i,0,n) cin>>a[i];
    loop(i,0,n) cin>>b[i];
    loop(i,0,m) cin>>c[i];

    int maxi = -1;
    loop(i,0,n) maxi = max(maxi, 1+a[i]);
    loop(i,0,maxi) best[i]= inf;
    int ans[maxi] = {0};

    for(int i=0; i<n; i++){
        best[a[i]] = min(best[a[i]], a[i]-b[i]);
    }

    for(int i=1; i<maxi; i++){
        best[i]= min(best[i], best[i-1]);
    }

    loop(i,1,maxi){
        if(best[i]<=i) ans[i] = 2 + ans[i - best[i]];
    }

    int res= 0;
    loop(i,0,m){
        if(c[i]<=maxi) res+= ans[c[i]];
        else{
            int k = (c[i] - maxi + best[maxi-1] + 1)/best[maxi-1];
            res += 2*k + ans[c[i]- k*best[maxi-1]];
        }
    }

    cout<<res<<endl;
}
  
  
int32_t main(){
solve();
return 0;
}