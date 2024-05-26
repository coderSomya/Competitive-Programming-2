/*
problem link ->
https://codeforces.com/problemset/problem/1904/D1
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
    int n; cin>>n;

    vi a(n);
    vi b(n);
    loop(i,0,n) cin>>a[i];
    loop(i,0,n) cin>>b[i];

    vector<pair<int,int>> v;

    for(int i=0; i<n; i++){
        if(a[i]>b[i]){
            cout<<"NO"<<endl;
            return;
        }
        if(a[i]<b[i]){
            v.pb({b[i], i});
        }
    }

    sort(v.begin(), v.end());


    for(int turn=0; turn<v.size(); turn++){
        //move to left
        int i = v[turn].second;

        int from = -1;

        for(int j=i; j>=0; j--){
            if(a[j]>b[i]) break;
            if(b[j]<b[i]) break;
            if(a[j]==b[i]){
                from = j;
                break;
            }
        }
        if(from !=-1){
            //fill everythin from from to idx as b[i]
            for(int j=from; j<=i; j++){
                a[j]=b[i];
            }
        }
        else{
            for(int j=i; j<n; j++){
                if(a[j]>b[i]) break;
                if(b[j]<b[i]) break;
                if(a[j]==b[i]){
                    from = j;
                    break;
                }
            }
            if(from !=-1){
                for(int j=i; j<=from; j++){
                    a[j]=b[i];
                }                   
            }
            else{
                cout<<"NO"<<endl;
                return;
            }
        }
    }


    cout<<"YES"<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}