/*
problem link ->
https://codeforces.com/problemset/problem/1992/F
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


void merge(set<int> &st, set<int> &st2){
    for(auto x: st2){
        st.insert(x);
    }
}
 
 
void solve(){
    int n,x; cin>>n>>x;
    set<int> st;
    st.insert(x);

    int ct = 1;

    int arr[n];
    loop(i,0,n) cin>>arr[i];

    for(int i=0; i<n; i++){
        set<int> st2;
        for(auto it: st){
            if((it%arr[i])!=0) continue;
            
            st2.insert(it/arr[i]);
        }

        merge(st, st2);

        if(st.find(1)!=st.end()){
            ct++;
            st.clear();
            st.insert(x);
            st.insert(x/arr[i]);
        }
    }

    cout<<ct<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}