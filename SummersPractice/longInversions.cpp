/*
problem link ->
https://codeforces.com/problemset/problem/1955/E
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


bool fun(const string &s, int k, int n){

    int i=0;
    vector<int> v(n,0);
    while(i<n){
        if(i>0) v[i]+=v[i-1];

        int val = (s[i]-'0')^(v[i]%2);

        if(i==n-1){
            return val==1;
        }

        if(val==0){
            if(i+k>n) return false;
            v[i]+=1;
            if(i+k<n) v[i+k]-=1;
        }
        i++;
    }
}

/*
+1  -1
0100100101
1010100101

*/

 
void solve(){

    int n; cin>>n;

    string s; cin>>s;

    int ans = 1;
    for(int k=1; k<=n; k++){
        string t = s;
        //check if we can do it for this k
        bool can = fun(t,k,n);

        if(can) ans = k;
    }

    cout<<ans<<endl;

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}