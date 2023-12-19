#include <bits/stdc++.h>
using namespace std;
#define loop(i,l,r)     for(int i=l; i<r; i++)
#define int             long long
#define pb              push_back
#define vi              vector<int>
#define vvi             vector<vi>
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
  
  
const int mod= 998244353;
const int inf= 1e15;

int fact[51];
int invfact[51];


int binexpo(int a, int b){
    if(b==0) return 1;

    if(b==1) return a;

    int temp = binexpo(a, b/2);
    int res = 1;
    if(b%2) res*=a;
    return ((res*temp)%mod*temp)%mod;
}

int ncr(int n, int r){
    
    if(r>n) return 0;
    int res = ((fact[n]*invfact[n-r])%mod * invfact[r])%mod;
    return res;
}
 
 
void solve(){
    int n,m; cin>>n>>m;


    vvi grid(n, vi(n));
    loop(i,0,n) loop(j,0,n) cin>>grid[i][j];

    int r, c;
    r=c=0;
    loop(i,0,n){
        loop(j,i+1,n){
            bool flag=true;
            loop(k,0,n){
             flag=flag&&((grid[i][k]+grid[j][k])<=m);
            }
            if(flag) r++;
        }
    }

    loop(i,0,n){
        loop(j,i+1,n){
            bool flag=true;
            loop(k,0,n){
             flag=flag&&((grid[k][i]+grid[k][i])<=m);
            }
            if(flag) c++;
        }
    }

    int ans=0;

    loop(i,0,r+1){
        loop(j,0,c+1){
            //calculate with given i and given j
            int temp;
            if(i>j) temp = (fact[i]*ncr(i+1,j))%mod;
            else temp= (fact[j]*ncr(j+1,i))%mod;
            ans+=temp;
            ans%=mod;
        }
    }

   ans-=1;
   cout<<ans<<endl;


}

  
int32_t main(){


fact[0]=1;
loop(i,1,51) fact[i]=(fact[i-1]*i)%mod;

invfact[50]=binexpo(fact[50], mod-2);
for(int i=49; i>=0; i--){
    invfact[i]=((i+1)*invfact[i+1])%mod;
}
 solve();
return 0;
}