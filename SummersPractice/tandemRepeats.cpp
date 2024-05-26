/*
problem link->
https://codeforces.com/problemset/problem/1948/D
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
    string s; cin>>s;
    int n = s.length();

    int ans =0;
    for(int d=1; d<=n/2; d++){

        int ct=0;
        for(int l=0; l<=n-2*d; l++){
            int r = l+2*d-1;
            if(l==0){
                for(int i=0; i<d; i++){
                    if(s[l+i]==s[l+d+i] || s[l+i]=='?' || s[l+d+i]=='?'){
                        ct++;
                    }
                }
            }
            else{
                //check if leftmost is good
                if(s[l-1]==s[l+d-1] || s[l-1]=='?' || s[l+d-1]=='?'){
                    ct--;
                }
                //check if rightmost is good
                if(s[l+d-1]==s[r] || s[l+d-1]=='?' || s[r]=='?'){
                    ct++;
                }
            }

            if(ct==d) ans = 2*d;
        }
    }

    cout<<ans<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}