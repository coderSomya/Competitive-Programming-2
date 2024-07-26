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
    int n; int k;
    cin>>n>>k;

    int arr[n][n];
    
    for(int i=0; i<n;i++) {
        string s; cin>>s;
        for(int j=0; j<n; j++){
            arr[i][j]=s[j]-'0';
        }
    }

    int res[n/k][n/k];
    int ii=0;
    for(int i=0; i<n; i+=k){
        int jj=0;
        for(int j=0; j<n; j+=k){
            res[ii][jj++]=arr[i][j];
        }
        ii++;
    }

    for(int i=0; i<n/k; i++) {
        for(int j=0; j<n/k; j++) cout<<res[i][j];
        cout<<endl;
    }

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}