/*
problem link ->
https://codeforces.com/problemset/problem/1928/C

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
    int n,x; cin>>n>>x;

    int ans=0;
    int p = n-x;

    if(p<0){
        std::cout<<0<<endl;
        return;
    }

    if(x==n) ans++;

    for(int i=1; i*i<=p; i++){
       if(p%i==0){
        int s = p/i;

        if(s%2 && i%2) continue;

        //we are setting i as k-1
        int k = i+1;
        if(x<=k && ((p/i) %2==0)) ans++;
        if(i*i!=p){
            //we are setting p/i as k-1
            k=s+1;
            if(x<=k  && i%2==0) ans++;
        }
       }
       
       if(i%2==0){
         if((p+i)%(i+1)==0 && (p+i)/(i+1)>1){
            ans++;
         }
       }
    }
   
    for(int i=2; i*i<=2*p; i+=2){
        int q = p+1-i;
        if(q%(i+1)==0){
            int k = q/(i+1);

            if(x<k) ans++;
        }

    }

    std::cout<<ans<<endl;

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}