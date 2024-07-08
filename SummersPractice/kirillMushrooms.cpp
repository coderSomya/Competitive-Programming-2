/*
problem link->
https://codeforces.com/problemset/problem/1945/F
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
    int p[n];
    loop(i,0,n) cin>>p[i];

    map<int,int> mp;
    loop(i,0,n){
        mp[i]=-arr[i];
    }

    multiset<int> mst;

    for(int i=0; i<n; i++){
        mst.insert(-1*arr[i]);
    }

    int ans = -1;
    int num = n;


    ans = -1*(*(mst.begin()));
    num = 1;
    for(int i=1; i<n; i++){
        int len = i+1;
        int r = mp[p[i-1]-1];
        mst.erase(mst.find(r));

        if(len>mst.size()) continue;
        auto it = mst.begin();
        advance(it,len-1);
        int elem = *it;

        int temp = -1*elem*len;
        if(temp>ans){
            ans = temp;
            num = len;
        }
    }
    cout<<ans<<" "<<num<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}