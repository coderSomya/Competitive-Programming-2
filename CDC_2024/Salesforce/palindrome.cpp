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


string all[]= {
    "00100",
    "00000",
    "01010",
    "01110",
    "10001",
    "10101",
    "11011",
    "11111"
};

int num_subsequences(const std::string& s, const std::string& t) {
    int n = s.length(), m = t.length();
    std::vector<int> dp(m + 1, 0);
    dp[0] = 1;  
    
    for (int i = 0; i < n; ++i) {
        for (int j = m; j > 0; --j) {
            if (s[i] == t[j - 1]) {
                dp[j] += dp[j - 1];
                dp[j]%=mod;
            }
        }
    }
    
    return dp[m];
}
  
const int mod= 1e9+7;
const int inf= 1e15;
 

int func(string s){

    int ans = 0;
    for(string t: all){
        ans+= num_subsequences(s, t);
        ans%=mod;
    }

    return ans;
}
 
void solve(){

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}