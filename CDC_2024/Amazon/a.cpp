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

int bs1(vector<int> &a, int x){
    //find the first element greater than or == x
int n = a.size();
    int l = 0;
    int r = n-1;
    int res = n-1;

    while(l<=r){
        int mid = (l+r)/2;
        if(a[mid]>=x){
            res = mid;
            r = mid-1;
        }
        else l= mid+1;
    }
    return res;
}


int bs2(vector<int> &a, int x){
        //find the last element less than or == x

    int l = 0;
    int n = a.size();
    int r = a.size()-1;
    int res = n-1;

    while(l<=r){
        int mid = (l+r)/2;
        if(a[mid]<=x){
            res = mid;
            l = mid+1;
        }
        else r= mid-1;
    }

    return res;
}

vector<vector<int>> func(vector<int> power, vector<int> minpow, vector<int> maxpow){

    sort(power.begin(), power.end());

int  n = power.size();
int m = maxpow.size();
    vector<int> pref(n);
    pref[0]=power[0];
    for(int i=1; i<n; i++) pref[i]=power[i]+pref[i-1];

    vector<vector<int>> ans(m, vector<int>(2));

    for(int i=0; i<m; i++){
        int mini= minpow[i];
        int maxi= maxpow[i];

        int a = bs1(power, mini);
        int b = bs2(power, maxi);

        ans[i][0]=b-a+1;
        ans[i][1] = pref[b]-pref[a]+power[a];

        cout<<i<<" "<<a<<" "<<b<<" "<<endl;
    }

    return ans;
}
 
 
void solve(){

    vi pow = {25,56,38,31,100};
    vi maxi = {30,40,60,120};
    vi mini = {20,30,40,60};

    vector<vector<int>> ans = func(pow, mini,maxi);

    for(int i=0; i<4; i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<endl;
    }
    cout<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}