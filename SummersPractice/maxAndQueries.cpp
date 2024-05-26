/*
problem link->
https://codeforces.com/problemset/problem/1903/D1
*/

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

    int n,q; cin>>n>>q;
    vi v(n);
    loop(i,0,n)cin>>v[i];

    while(q--){
        int k; cin>>k;
        int ans=0;

        for(int i=30; i>=0; i--){
            int ones=0;
            int temp = (1<<i);
            int sum=0;

            for(int j=0; j<n; j++){
                if(temp&v[j]) continue;
                sum+= temp - (v[j]%temp);
            }

            if(sum<=k){
                ans+=temp;
                k-=sum;
                for(int j=0; j<n; j++){
                    if((temp&v[j]) == 0){
                        v[j]+=temp - (v[j]%temp);
                    }
                }
            }
        }

        cout<<ans<<endl;
    }

}
  
  
int32_t main(){
int t;
// cin>>t;
t=1;
while(t--) solve();
return 0;
}

/*

1 3 7 5

001
011
111
101


*/