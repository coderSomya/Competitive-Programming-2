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

int n,k; 
string s,t;

const int N =202;

int dp[N][N][N];

int maxi(int i, int t0, int k){
   
    if(i>=n) return 0;
    if(dp[i][t0][k]!=-1) {
        return dp[i][t0][k];}
    
    int p=0;
    if(s[i]==t[0]) p++;
    
    int res= maxi(i+1, t0+p, k);
 
    if(s[i]==t[0]){
       //we can change it to t[1]

       if(k>0 && t0>0){
         res=max(res, t0+maxi(i+1, t0, k-1));
       }
    }
    else if(s[i]==t[1]){
        //we acn match one prev t0
          if(t0>0) res= max(res, t0+ maxi(i+1,t0,k ));
        
        //we can change it to t0
          if(k>0){
            res=max(res, maxi(i+1, t0+1, k-1));
          }
    }

    else{
        if(k>0){
         //we can change it to t0
         res=max(res, maxi(i+1, t0+1, k-1));
        //we can change it to t1
        //we would do it only if there is a previous t0
        if(t0>0){
            res= max(res, t0+ maxi(i+1, t0, k-1));
        }
        
        }
    }

    return dp[i][t0][k]=res;
}

int nc2(int i){
    return i*(i-1)/2;
}

int solve2(){
    int ct=0;
    for(int i=0; i<n; i++){
        ct+= (s[i]==t[0]);
    }

    ct+=min(n-ct, k);

    int res=nc2(ct);
    return res;
}
 
 
void solve(){
    scanf("%d%d", &n,&k);
   cin>>s>>t;
   

   memset(dp, -1, sizeof(dp));

   if(t[0]==t[1]){
    int res= solve2();
    cout<<res<<endl;
    return;
   }

   int ans= maxi(0, 0, k);
   cout<<ans<<"\n";
   
}
  
  
int32_t main(){
// int t;
// cin>>t;
// while(t--)
 solve();
return 0;
}