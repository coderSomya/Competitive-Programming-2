/*
problem link->
https://codeforces.com/problemset/problem/1924/A
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

    int n, k, m;
    string s; 
    cin>>n>>k>>m;
    cin>>s;
    
    int ct=0;
    int ans=0;
    unordered_set<char> st;
    vector<char> v;
    for(int i=0; i<m; i++){
        if(s[i]-'a'<k){
        st.insert(s[i]);
        }
        if(st.size() == k){
            ans++;
            v.pb(s[i]);
            st.clear();
        }
    }



    if(ans<n){
        int lex=-1;
        cout<<"NO"<<endl;
        for(int i=0; i<k; i++){
            if(st.find('a'+i)==st.end()){
                lex = i;
            }
        }

        for(int i=0; i<v.size(); i++){
            cout<<v[i];
        }
        for(int i=v.size(); i<n; i++){
            cout<<char('a'+lex);
        }
        cout<<endl;
    }
    else cout<<"YES"<<endl;

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}