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

int bs(int pref[], int arr[], int n, int i, int val){
    //return the first element j such that pref[j]-pref[i]>val

    int ans = -1;

    int l = i; int h=n-1;
    while(l<=h){
        int mid = (l+h)/2;

        if(pref[mid]-pref[i]+arr[i]>val){
            ans =mid;
            h=mid-1;
        }
        else l=mid+1;
    }

    return ans;
}
 
 
void solve(){
    int n, x;
    cin>>n>>x;
    int arr[n];
    loop(i,0,n) cin>>arr[i];

    int pref[n];
    loop(i,0,n) pref[i]=(i>0 ? pref[i-1] : 0)+arr[i];


    int ans[n]={0};
    for(int i=n-1; i>=0; i--){
        int idx = bs(pref, arr, n,i,x);
        if(idx==-1){
            //take everything
            ans[i]=n-i;
        }
        else{
            ans[i]=idx-i;
            if(idx<n-1) ans[i]+=ans[idx+1];
        }
    }

    int res = 0;
    for(int i=0; i<n; i++) res+= ans[i];

    cout<<res<<endl;


}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}