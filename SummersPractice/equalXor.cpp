/*
problem link ->
https://codeforces.com/problemset/problem/1968/F
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


int bs(const vector<int> &v, int left){
    //find count of values greater than or equal to l
    int l = 0;
    int r = v.size();


    int ans = 2e5;

    while(l<=r){
        int mid = (l+r)/2;

        if(v[mid]>=left){
            ans=v[mid];
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }

    return ans;
}
 
void solve(){
    int n,q; cin>>n>>q;

    int arr[n];
    loop(i,0,n) cin>>arr[i];

    map<int,vi> mp;
    int exor[n];
    for(int i=0; i<n; i++){
        if(i==0) exor[i]=arr[i];
        else exor[i]=exor[i-1]^arr[i];

        if(mp.find(exor[i])==mp.end()){
            mp[exor[i]]={i};
        }
        else mp[exor[i]].pb(i);
    }

    while(q--){
        int l,r;
        cin>>l>>r;
        l--; r--;

        int left=0;
        if(l>0) left=exor[l-1];


        int andar_ka_xor = exor[r]^left;

        if(andar_ka_xor == 0){
            cout<<"YES"<<endl;
            continue;
        }
        else{
            //we need first > l such that xor till there is left^andar_ka_xor = p1

            // we need first > p1 such that xor till there is p = p2

            // if p2 < r, its true


            int req = left^andar_ka_xor;

            if(mp.find(req)==mp.end()){
                cout<<"NO"<<endl;
                continue;
            }

            vector<int> v1= mp[req];


            if(mp.find(left)==mp.end()){
                cout<<"NO"<<endl;
                continue;
            }

            vector<int> v2= mp[left];


            int p1 = bs(v1, l);
            int p2 = bs(v2, p1+1);

            if(p2<r){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}