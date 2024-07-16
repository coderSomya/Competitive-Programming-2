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

int find(){

    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    sort(arr.begin(), arr.end());
    map <int,int> mp;
    mp[arr[0]]++;

    int speed; cin>>speed;

    int ans = 0;

    for(int i=1; i<n; i++){
        for(int j=1; j*j<=arr[i]; j++){
            if(arr[i]%j==0){
                if(mp[j]!=0){
                    if((arr[i]/j)%speed ==0){
                        ans+= mp[j];
                    }
                }
            }
        }
        mp[arr[i]]++;
    }

    cout<<ans<<endl;

}
 
 
void solve(){
    find();
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}