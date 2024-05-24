/*
problem link ->
https://codeforces.com/problemset/problem/1973/C
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

    int idx = -1;

    loop(i,0,n) {
        if(arr[i]==n) {
            idx =i;
            break;
        }
    }

    vector<pair<int,int>> smalls;
    vector<pair<int,int>> bigs;

    cout<<idx<<endl;

    for(int i=0; i<n; i++){
        if((i-idx)%2) smalls.pb({arr[i], i});
        else bigs.pb({arr[i],i});
    }

    sort(smalls.begin(), smalls.end());
    sort(bigs.begin(), bigs.end());

   


    vector<int> ans(n);

    for(int i=0; i<n/2; i++){
        int index = smalls[i].second;

        ans[index]=n/2-i;
    }
    for(int i=0; i<n/2; i++){
        int index = bigs[i].second;

        ans[index]=n-i;
    }

    for(int i=0; i<n; i++) cout<<ans[i]<<" ";
    cout<<endl;

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}