/*
problem link ->
https://codeforces.com/problemset/problem/1847/D
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
    int n,m,q; 
    cin>>n>>m>>q;

    string s; cin>>s;

    vector<pair<int,int>> v;
    loop(i,0,m){
        int a,b; cin>>a>>b;
        a--; b--;
        v.pb({a,b});
    }

    map<int,int> mp;
    map<int,int> pos;
    int ct=0;


    for(int i=0; i<m; i++){
        for(int j=v[i].first; j<=v[i].second; j++){
            if(mp.find(j)==mp.end()){
                mp[ct]=j;
                pos[j] = ct;
                ct++;
            }
        }
    }

    vector<int> arr;


    /*
    mp[0] = 5
    mp[1] = 6
    .....
    

    st = {2,3,5,6,7,8}
    */

    for(int i=0; i<=ct; i++){
        arr.pb(mp[i]);
    }

    /*
    arr = [5,6,...]
    */

    int X = 0;
    for(int i=0; i<=ct; i++){
        X+=(s[arr[i]]=='1');
    }

    /*
    X = 1s in arr from 0 -> ct
    */

    int Y=0;
    for(int i=0; i<X; i++){
        Y+=(s[arr[i]]=='0');
    }

    /*
    Y = 0s in arr from 1 -> X
    */

    while(q--){
        int x; cin>>x;
        x--;

        if(pos.find(x)==pos.end()){
            cout<<"ans"<<Y<<endl;

            //if we dont have this index in t(s),
            //then fuck off
            continue;
        }
        int y = pos[x];

        // y will tell where the index is in arr


        if(s[x]=='1'){

            //1->0

            if(X>=1 && s[pos[X-1]]=='0') Y--;
            if(y<X-1) Y++;
            X--;

            s[x]='0';
            cout<<"ans"<<Y<<endl;
        }
        else{
            //0->1
            if(s[pos[X]]=='0') Y++;
            if(y<=X) Y--;

            X++;
            s[x]='1';
            cout<<"ans"<<Y<<endl;
        }
    }
}
  
  
int32_t main(){
// int t;
// cin>>t;
// while(t--) 
solve();
return 0;
}