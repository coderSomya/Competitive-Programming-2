/*
problem link->
https://codeforces.com/problemset/problem/1971/G
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
    vi ans(n);
    map<int,vi> mp;

    loop(i,0,n){
        if(mp.find(arr[i]/4)!=mp.end()){
            mp[arr[i]/4].pb(i);
        }
        else {
            vi b = {i};
            mp[arr[i]/4] = b;
        }
    }

    for(auto x: mp){
        int val = x.first;
        vi pos = x.second;
        //has all positions
        vi h;
        //has all values
        for(int i=0; i<pos.size(); i++){
            int position = pos[i];
            h.pb(arr[position]);
        }
        sort(h.begin(), h.end());
        sort(pos.begin(), pos.end());

        for(int i=0; i<h.size(); i++){
            ans[pos[i]] = h[i];
        }
    }


    loop(i,0,n) cout<<ans[i]<<" ";
    cout<<endl;

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}