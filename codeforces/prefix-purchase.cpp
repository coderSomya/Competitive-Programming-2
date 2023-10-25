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
    int n; cin>>n;
    vi v(n);
    loop(i,0,n) cin>>v[i];

    int k; cin>>k;
    vi rep(n,-1);

    int mini=inf;

    for(int i=n-1; i>=0; i--){
        if(v[i]<mini){
         rep[i]=1;
         mini=v[i];
        }
    }
    int p=-1;
    int q=-1;
    int r=-1;
    int s=-1;

    for(int i=0; i<n; i++){
        if(rep[i]==1){
            p=k/v[i]-1;
            q=k%v[i];
            r=i;
            s=i;

            for(int j=i+1; j<n; j++){
                if(rep[j]!=1) continue;
                if((v[i]+q)/v[j] ==1){
                    s=j;
                }
            }

            break;
        }
    }
    vi ans(n,0);
    for(int i=0; i<=r; i++) ans[i]+=p;
    for(int i=0; i<=s; i++) ans[i]+=1;

    loop(i,0,n) cout<<ans[i]<<" ";
    cout<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}