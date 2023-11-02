/*
https://codeforces.com/problemset/problem/1143/C
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

    vector<vector<int>> child(n+1);
    vector<int> cs(n+1);

    loop(i,1,n+1){
       int p, c;
       cin>>p>>c;
       if(p!=-1)
       child[p].push_back(i);
       cs[i]=c;
    }

    vi v;

    for(int i=1; i<=n;i++){
        
        bool flag=(cs[i]==1);
        for(auto x: child[i]){
            flag=flag&&(cs[x]==1);
        }

        if(flag){
            v.push_back(i);
        }
    }

    if(v.empty()){
        cout<<-1<<endl;
        return;
    }

    sort(v.begin(), v.end());
    for(auto x: v) cout<<x<<" ";

 
    cout<<endl;


}
  
  
int32_t main(){
// int t;
// cin>>t;
// while(t--)
 solve();
return 0;
}