/*
problem link->
https://codeforces.com/problemset/problem/1941/E
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
 

int ans(const vector<int> &v, int m, int d){

vector<int> dp(m);
dp[0]=1;
multiset<int> mst;
mst.insert(1);

for(int i=1; i<m-1; i++){
    int mini = *mst.begin();
    int res = mini+1+v[i];
    dp[i]=res;

    if(i-d-1>=0){
        mst.erase(mst.find(dp[i-d-1]));
    }
    mst.insert(dp[i]);
}

dp[m-1]=1+*mst.begin();
return dp[m-1];
}

int ans2(const vector<int> &v, int n, int k){
  int ans = 0;
  for(int i=0; i<k; i++){
    ans+=v[i];
  }
  int temp = ans;
  for(int i=k; i<n; i++){
    temp+=v[i];
    temp-=v[i-k];
    ans = min(ans, temp);
  }

  return ans;
}

 
void solve(){
    int n,m,k,d;
    cin>>n>>m>>k>>d;

    vector<vector<int>> v(n, vector<int> (m));

    loop(i,0,n) loop(j,0,m) cin>>v[i][j];

    vector<int> res(n);

    for(int i=0; i<n; i++){
        res[i] = ans(v[i],m,d);
    }

    int sol = ans2(res,n,k);

    cout<<sol<<endl;


}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}