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

int dp[105][3];
int risk(int i, int last, vector<int>&v, int n){
  //minimum risk starting from i, if the last elem%2 was 'last'

  if(i==n) return 0;

  if(dp[i][last]!=-1) return dp[i][last];

  if(v[i]!=0){
    int extra= i!=0 ? (last!=v[i]%2) : 0;

    return dp[i][last] = extra+ risk(i+1, v[i]%2, v, n);
  }
  
  else{
    
    int opt1= risk(i+1, 0, v, n);
    int opt2= risk(i+1, 1, v, n);

    return dp[i][last] = min((last==1) + opt1, (last==0) + opt2);
  }

}


int Parity(int N, vector<int> Arr){

    // memset(dp, -1, sizeof(dp));
    // int ans= risk(0,2,Arr, N);
    // return ans;
   if(N==1) return 0;

    vector<int> v;
    v.push_back(Arr[0]);
    
    int risk=0;
    for(int i=1; i<N; i++){
        if(v.back()==0 && Arr[i]==0) continue;
        else v.push_back(Arr[i]);
    }

    int n=v.size();
    if(n==1) return 0;
     for(int i=0; i<n;i++){
        if(v[i]==0){
            if(i==0) v[i]=v[i+1];
            else v[i]=v[i-1];
        }
     }

     for(int i=1; i<n; i++){
         risk+=(v[i]%2 != v[i-1]%2);
     }

   return risk;

     
}




 
void solve(){

  int N; cin>>N;
  vi v(N);
  loop(i,0,N) cin>>v[i];
  int res= Parity(N, v);
  cout<<res<<endl;

}
  
  
int32_t main(){
 solve();
return 0;
}