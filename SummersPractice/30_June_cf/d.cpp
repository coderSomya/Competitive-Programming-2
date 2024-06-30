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
 
bool steps(int i, int j,int ct, int v){
    return (j-i-ct)>= v;
}
 
void solve(){
    int n; cin>>n;

    vi v(n);
    loop(i,0,n) cin>>v[i];

    vector<pair<int,int>> arr;
    sort(v.begin(),v.end());

    arr.pb({v[0],1});
    for(int i=1; i<n; i++){
        if(v[i]==v[i-1]) arr.back().second++;
        else{
            arr.pb({v[i],1});
        }
    }

    n=arr.size();


    int res = 0;
    for(int i=0; i<n; i++){

        if(arr[i].second==0) continue;
        if(arr[i].second!=0){
            res++;
            arr[i].second--;
        }
        int ind= -1;
        int rind = -1;
        int ct=0;
        for(int j=i+1; j<n; j++){
            if(arr[j].second==0) ct++;
            else if(arr[j].second!=0 && steps(i,j,ct,arr[j].second)){
                if(j-i-ct-arr[j].second==0){
                    rind=j;
                }
                ind = j;
            }
        }
        if(ind!=-1) {
            arr[ind].second--;
        }
    }

    cout<<"ans"<<res<<endl;
}


void solve2(){
    int n; cin>>n;

    vi v(n);
    loop(i,0,n) cin>>v[i];

    vector<pair<int,int>> arr;
    sort(v.begin(),v.end());

    
    arr.pb({v[0],1});
    for(int i=1; i<n; i++){
        if(v[i]==v[i-1]) arr.back().second++;
        else{
            arr.pb({v[i],1});
        }
    }


    int dp[n+1][n+1]={0};
    int x = arr.size();


    for(int i=0; i<arr[x-1].second; i++){
        dp[arr.size()-1][i] = 0;
    }
    for(int i=arr[x-1].second; i<=n; i++){
        dp[arr.size()-1][i]=1;
    }
int ans  = 0;
    for(int i=x-2; i>=0; i--){
        for(int j=1; j<=i; j++){
            if(j==arr[i].second){
                //i can reduce this
                dp[i][j]= 1;
            }
            else if(j>arr[i].second){
                dp[i][j] = 1 + dp[i+1][j-arr[i].second];
            }
            else{
             dp[i][j] = 0;
            }

            ans = max(ans, dp[i][j]);
        }
    }

    cout<<arr.size() - ans<<endl;
}
  
int32_t main(){
int t;
cin>>t;
while(t--) solve2();
return 0;
}