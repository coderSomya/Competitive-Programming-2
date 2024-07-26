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
    int x; cin>>x;

    int ans =0;
    for(int i=1; i<=n-2; i++){
        int a = i;
        int bpc = x - i;

        //a*(b+c) + b*c = n

        int bnc = n - a*(bpc);
        

        int m = bpc/2;

        int l = 1;
        int h = m;
        int res = 0;
        while(l<=h){
            int mid = (l+h)/2;

            int x = mid;
            int y = bpc - mid;

            if(x*y <= pnc){
                res = mid;
                l = mid+1;
            }
            else h = mid-1;
        }

        if((m+1)*(bpc- (m+1))<=bnc) res++;
        ans+=res;
    }
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}