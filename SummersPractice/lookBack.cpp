/*
problem link->
https://codeforces.com/problemset/problem/1883/E
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
 
void solve(){

    take_n
    take_arr

    int maxi = arr[0];
    int ans=0;
    for(int i=1; i<n; i++){
        int j;
        for(j=0; j<100; j++){
            if(arr[i]*(1ll<<j) >= maxi){
                maxi=max(maxi, arr[i]*(1ll<<j));
                break;
            }
        }
        ans+=j;
    }

    cout<<ans<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}


/*
1376
1898    
977
1465
3350
4096
676
40
463
603
3224
3511
321
64
1350
1838
123
779
301
1784
1389
2692
140
218
621






*/