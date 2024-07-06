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
    int ct=0;

    for(int i=0; i<m; i++){
        for(int j=v[i].first; j<v[i].second; j++){
            if(mp.find(j)!=mp.end()){
                mp[j]=ct++;
            }
        }
    }

    vector<int> arr;

    for(int i=0; i<n; i++){
        arr.pb(mp[i]);
    }

    //check good and bad

    int l=0; int r=n-1;
    int lc=0;int rc=0;

    vi bad_ones;
    vi bad_zeroes;
    while(l<=r){
        if(s[arr[l]]==0){
            while(r>l){
                if(arr[r]==1){
                    break;
                }
                r--;
            }
            if(r>l){
                bad_ones.pb(arr[r]);
                bad_zeroes.pb(arr[l]);
                l++;
                r--;
            }
            else{
                break;
            }
        }
        else l++;
    }

    //we have pairs whom we want to swap
    int lcs = -1;
    int rcs = -1;
    if(bad_zeroes.size()!=0){
        lcs = bad_zeroes[bad_zeroes.size()-1]+1;
        rcs = bad_ones[bad_ones[0]]+1;
    }

    int ans = bad_zeroes.size();

    while(q--){
        int x; cin>>x;
        x--;
        int y = mp[x];
        if(y>=lcs && y<=rcs){
            if(s[y]==0){
            }
            else{
            }
        }
        else{
            if(y<lcs){
                if(s[y]=='0'){

                }
                else{

                }
            }
            else{
                if(s[y]=='0'){

                }
                else{

                }
            }
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