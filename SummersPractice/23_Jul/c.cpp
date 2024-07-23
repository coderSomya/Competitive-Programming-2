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
 

bool isPowerComparisonTrue(double a, double x, double b, double y) {
    double leftSide = x * std::log(a);
    double rightSide = y * std::log(b);

    double epsilon = std::numeric_limits<double>::epsilon();

    return (leftSide > rightSide) || (std::fabs(leftSide - rightSide) < epsilon);
}

 
void solve(){
    int n; cin>>n;

    int ans =0;
    int arr[n];

    vector<pair<int,int>> v;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    v.pb({arr[0], 1});

    for(int i=1; i<n; i++){
        if(arr[i]==1 && arr[i-1]!=1){
            cout<<-1<<endl;
            return;
        }
        int l= 1;
        int  h  = 64;
        int res = -1;

        while(l<=h){
            int mid = (l+h)/2;

            if(isPowerComparisonTrue(double(arr[i]), double(1<<(mid)), double(v[i-1].first), double(v[i-1].second))){
                res = mid;
                h=mid-1;
            }
            else l = mid+1;
        }
        int y;
        if(res ==-1) y=0;
        else y = 1<<res;
        v.pb({arr[i],y});
    }

    loop(i,0,n) ans+= v[i].second;

    // for(int i=0; i<n; i++) cout<<v[i].first<<" "<<v[i].second<<endl;

    cout<<ans<<endl;


}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}