/*
problem link ->
https://codeforces.com/problemset/problem/1409/D
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
const int inf= 2e18;

int SUM;
vector<int> v;

vector<int> ANS;
vector<int> pow10(19);

int dp[20][2][180];


int mini(int i, int tight, int sum){
    //returns sum of digit if we are at i, we are tight, and sum of digits so far is sum

    if(i==18){
        if(sum<=SUM)return 0;
        else return inf;
    }

    if(dp[i][tight][sum]!=-1) return dp[i][tight][sum];

   //we try to put every digit at ith place
   int lb=tight? v[i]:0;
   int ub=9;
   int res=2e18;
   int best=-1;

   for(int dig=lb; dig<=ub; dig++){
     int diff= (dig-v[i])*(pow10[17-i]);
     int ntight=tight&&(dig==lb);

     if(diff+ mini(i+1, ntight, sum+dig) < res){
      res = diff+ mini(i+1, ntight, sum+dig);
      best=dig;
     }
  
   }

   return dp[i][tight][sum] = res;
}
 
 
void solve(){
   int n; cin>>n;
   cin>>SUM;

   v.clear();
   for(int i=0; i<18; i++){
     int rem=n%10;
     v.push_back(rem);
     n/=10;
   }


   memset(dp, -1, sizeof(dp));
   reverse(v.begin(), v.end());

   for(auto x: v) cout<<x<<" ";
   cout<<"\n";

  
   int ans= mini(0,1,0);
   cout<<ans<<endl;


}
  
  
int32_t main(){
int t;
cin>>t;
pow10[0]=1;
for(int i=1; i<=18; i++) pow10[i]=pow10[i-1]*10;
while(t--) solve();
return 0;
}