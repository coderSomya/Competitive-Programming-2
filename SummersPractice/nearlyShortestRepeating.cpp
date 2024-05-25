/*
problem link ->
https://codeforces.com/problemset/problem/1950/E
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


bool can (const string &s, int n, int k){

    int tc1 = 0;

    //1st substr is not the defaulter
    for(int i=0; i<n/k; i++){
        for(int j=i; j<n; j+=n/k){
            tc1+= s[j]!=s[i];
        }
    }

//k==3

    if(k==1){
        return tc1<=1;
    }

    int tc2 = 0;
    //1st substr may be the defaulter

    for(int i=0; i<n/k; i++){
        for(int j=i; j<n; j+=n/k){
            tc2+= s[j]!=s[i+n/k];
        }
    }

    return min(tc1, tc2) <=1;
}

void solve(){

    int n; cin>>n;
    string s; cin>>s;

    //calculate all factors of n (this can be precomputed for all n also but nvm)


    vector<int> facts;

    for(int i=1; i*i<=n; i++){
        if(n%i==0) {
            facts.push_back(i);
            if(i*i!=n) facts.push_back(n/i);
        }
    }

    sort(facts.begin(), facts.end());

    int l = 0; int r = facts.size()-1;

    int ans = n;

    while(l<=r){
        int mid = (l+r)/2;

        int check = can(s, n, facts[mid]);

        if(check){
            ans = n/facts[mid];
            l=mid+1;
        }
        else r = mid - 1;
    }

    cout<<ans<<endl;

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}