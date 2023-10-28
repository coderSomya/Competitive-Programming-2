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
    int k; cin>>k;

    string s; cin>>s;
   bool flag=true;

   string t;
    
    for(int i=0; i<k; i++){
        char curr=s[i];
        for(int j=i+k; j<n; j+=k){
          if(s[j]=='?') continue;
          else{
            if(curr=='?') curr=s[j];
            else if(curr!=s[j]) flag=false;
          }
        }
        t+=curr;
    }
    
    
    //just check the first kth string 

    int ones, zeroes;
    ones= zeroes=0;

    for(int i=0; i<k; i++){
        ones+=t[i]=='1';
        zeroes+= t[i]=='0';
    }

    if(ones>k/2 || zeroes>k/2) flag=false;

    cout<<((flag)? "YES": "NO")<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}