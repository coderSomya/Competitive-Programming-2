/*
problem link->
https://codeforces.com/problemset/problem/1980/F1
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
    int n,m,k;cin>>n>>m>>k;

    map<pair<int,int>, int> mp;
    vector<pair<int,int>> v;
    vector<pair<int,int>> original;
    for(int i=0; i<k; i++){
        int r,c; cin>>r>>c;
        v.pb({r,c});
        original.pb({r,c});
        mp[{r,c}]=i;
    }
    int last_row = n;
    int max_width = m;
    int ans = 0;
    std::sort(v.begin(), v.end());

    map<int,int> min_row;
    vector<pair<int,int>> rows;
    for(int i=0; i<v.size(); i++){
        int x= v[i].first;
        int y = v[i].second;

        if(min_row.find(x) == min_row.end()){
            rows.pb({x,y});
            min_row[x]=y;
        }
    }

    int g = rows.size();
    for(int i=g-1; i>=0; i--){
        int x = rows[i].first;
        int y = rows[i].second;

        int up = last_row - x;
        int land = up*max_width;
        ans+= land;
        max_width = min(max_width,y-1);
        last_row = x;
    }
    ans+= (last_row)*max_width;
    cout<<ans<<endl;

    vi res(k);

    for(int i=0; i<k; i++){
        int x = original[i].first;
        int y = original[i].second;
        if(min_row[x]<y){
            res[i]=0;
        }
    }

    int mini = m+1;
    for(int i=g-1; i>=0; i--){
        int x = rows[i].first;
        int y = rows[i].second;
        int pos = mp[{x,y}];

        if(min_row[x]==y && mini>y){
            res[pos]=1;
        }
        else res[pos] = 0;
        mini = min(mini, y);
    }

    for(int i=0; i<k; i++){
        cout<<res[i]<<" ";
    }   
    cout<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}