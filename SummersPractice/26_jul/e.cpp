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
    string s;
    cin>>s;
    int n = s.length();

    int arr[n];
    for(int i=0;i<n; i++){
        arr[i]=(s[i]=='1')?1:-1;
    }

    int pref[n];
    pref[0]=arr[0];

    for(int i=1; i<n; i++) pref[i]=pref[i-1]+arr[i];
int ans = 0;
    unordered_map<int,unordered_set<int>>mp;
    mp[0].insert(-1);
    for(int i=0; i<n; i++){
        int x = pref[i];
        for(auto y: mp[x]){
            int temp  = ((y+2)*(n-i))%mod;
            ans+=temp;
            ans%=mod;
        }
        mp[x].insert(i);
    }

    cout<<ans<<endl;

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}