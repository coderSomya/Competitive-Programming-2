/*
problem link ->
https://codeforces.com/problemset/problem/1932/F
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
    int n; cin>>n;
    int m; cin>>m;
    vector<pair<int,int>> v(n+2);
    vi starts(m);
    vi ends(m);
    vector<set<int>> start_here(n+2, set<int>());
    vector<set<int>> end_here(n+2, set<int>());
    loop(i,0,m){
        int x,y; cin>>x; cin>>y;
        starts[i]=x;
        ends[i]=y;

        start_here[x].insert(i);
        end_here[y].insert(i);
    }

    int dp[n+2]={0};
    set<pair<int,int>> st;
    for(int i=1; i<=n; i++){
        for(auto x: start_here[i]){
            st.insert({ends[x], x});
        }
 
       for(auto y: end_here[i-1]){
            st.erase({ends[y],y});
        }
        //st has all elements that are active at i

        // we need the max right
        if(st.size()){
            pair<int,int> p = *st.rbegin();
            int right_max = p.first;
            v[i]={st.size(), right_max};
        }
        else{
            v[i]={0,i};
        }
   
    }

    // for(auto x: v){
    //     cout<<x.first<<" "<<x.second<<endl;
    // }

    for(int i=n; i>=0; i--){
        //either take everything here and move to max_right+1

        //or don't take anythig here and take the max that can be obtainer from i+1

        dp[i]=dp[i+1];
        dp[i]=max(dp[i], v[i].first+dp[1+v[i].second]);
    }

    cout<<dp[0]<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}