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


int maxi(vi &arr, int l, int r, int n){
    int ll= 0;
    int rr=0;
    int ans =0;
    int sum =0;
    for(int rr=0; rr<n;){
        sum+=arr[rr];
        if(arr[rr]>r){
            sum=0;
            rr++;
            ll=rr;
            continue;
        }
        if(sum>=l){
            if(sum<=r){
                ans++;
                sum=0;
                rr++;
                ll=rr;
            }
            else{
                while(ll<rr){
                    sum-=arr[ll];
                    ll++;
                    if(sum<=r && sum>=l){
                        ans++;
                        ll=rr+1;
                        rr=rr+1;
                        sum=0;
                        break;
                    }
                }
                if(sum>r){
                    sum=0;
                    rr++;
                    ll++;
                }
            }
        }
        else{
            rr++;
        }
     }
     return ans;
}
 
 
void solve(){
    int n,l,r;
    cin>>n>>l>>r;
    vi arr(n);
    loop(i,0,n) cin>>arr[i];

    int m = maxi(arr, l,r, n);
    reverse(arr.begin(), arr.end());

    m = max(m, maxi(arr, l,r, n));

    cout<<m<<endl;

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}