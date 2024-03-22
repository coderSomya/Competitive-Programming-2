/*
problem link ->
https://codeforces.com/problemset/problem/1934/C
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

int query(int x, int  y){
    cout<<"? "<<x<<" "<<y<<endl;
    int res;
    cin>>res;
    return res;
}


  
void solve(){
    int n, m;cin>>n>>m;

    int t1,t2,t3,t4;
    int x1,y1;

    //top left
    t1 = query(1,1);
    //top right
    t2 = query(1,m);
    //bottom left
    t3= query(n,1);
    
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}