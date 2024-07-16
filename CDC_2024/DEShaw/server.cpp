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

vector<pair<int,int>> v;
int n;

int poss(int x){

    //is it possible to downlad everythin if k = x
    int speed = x;
    int curr =0;
    for(int i=0; i<n; i++){
        v[i].second -= curr;
        //m*(v[i].first +x) >= v[i].second + v[i].first;

        int m  = (v[i].first + v[i].second) /(speed+ v[i].first);

        //it takes m steps to download the first one

        speed -= v[i].first*(m-1);
        curr+= (m-1)*v[i].first;
    }
}
 
void solve(){
    cin>>n;
    int a[n],b[n];   
    loop(i,0,n) cin>>a[i];
    loop(i,0,n) cin>>b[i];

    for(int i=0; i<n; i++) v.pb({b[i], a[i]});
    sort(v.begin(),v.end());

    reverse(v.begin(),v.end());

    int ans = 1e9;
    int l=1; int h = 1e9;
    while(l<=h){
        int mid = (l+h)/2;

        if(poss(mid)){
            ans = mid;
            h=mid-1;
        }
        else l=mid+1;
    }
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}