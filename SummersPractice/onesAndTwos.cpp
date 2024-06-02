/*
problem link ->
https://codeforces.com/problemset/problem/1896/D
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
    int n, q;
    cin>>n>>q;

    vi v(n);
    loop(i,0,n) cin>>v[i];

    set<int> st;
    loop(i,0,n) if(v[i]==1) st.insert(i);

    loop(i,0,q){
        int x;
        cin>>x;

        if(x==1){
            int req; cin>>req;

            int s = st.size();
            if(abs(req-s)%2==0){
                if(2*n - s >= req){
                    cout<<"YES"<<endl;
                }
                else cout<<"NO"<<endl;
            }
            else{
                if(s==0){
                    cout<<"NO"<<endl;
                    return;
                }
                int f = *st.begin();
                int l = *st.rbegin();

                int s1 = 2*(n-1- f) - (s-1);
                int s2 = 2*l - (s-1);

                if(req<= max(s1, s2)) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
        }

     else{
        int pos; int val;
        cin>>pos>>val;
        pos--;

        st.erase(pos);
        if(val==1) st.insert(i);
     }

    }
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}