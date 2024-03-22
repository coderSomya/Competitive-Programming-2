/*
problem link ->
https://codeforces.com/problemset/problem/1936/A
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

unordered_map<char,int> mp;

int query(int a, int b, int c, int d){
    cout<<"? "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    char ch;
    cin>>ch;
    return mp[ch];
}
 
void solve(){
    take_n

    //find the max 
    int maxi = 0;
    for(int i=1; i<n; i++){
        int r = query(maxi,maxi,i,i);
        if(r==2) maxi=i;
    }

    //find probable candidates
    vector<int> candis;
    int mx = 0;
    candis.push_back(mx);
    for(int i=1; i<n; i++){
        int r = query(maxi,mx,maxi,i);
        if(r==2){
            candis.clear();
            candis.pb(i);
            mx=i;
        }
        else if(r==0){
          candis.pb(i);
        }
    }

    
    //find the smallest candi
    int sz = candis.size();
    int mini = candis[0];
    for(int i=1; i<sz; i++){
        int r = query(mini,mini, candis[i],candis[i]);
        if(r==1){
           mini=candis[i];
        }
    }

    cout<<"! "<<maxi<<" "<<mini<<endl;

}
  
  
int32_t main(){

mp['=']=0;
mp['>']=1;
mp['<']=2;

int t;
cin>>t;
while(t--) solve();
return 0;
}

