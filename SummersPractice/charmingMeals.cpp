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


/*

a = 2 3  4 5  8

b = 4 5 6 7 19
b=  0 1 9 10 11


*/


bool can(const vector<int> &a,const vector<int> &b, int n, int d){

    //a and b are sorted

    //for everything in a, find the first in b such that diff > = d

    bool is = true;

    int lefta = 0;
    int leftb=0;
    vector<int> unused;
    while(leftb<n){
        if(abs(b[leftb]-a[lefta])>=d){
            lefta++;
        }
        else{
            unused.push_back(leftb);
        }
        leftb++;
    }

    //we have lefta-1 sorted
    //we have some in unused

    int x = unused.size();

    for(int i=0; i<x; i++){
        if(abs(a[lefta+i]-b[unused[i]])<d) is=false;
    }

    return is;
}

 
 
void solve(){

    int n; cin>>n;
    vector<int> a(n); vector<int> b(n);

    loop(i,0,n) cin>>a[i];
    loop(i,0,n) cin>>b[i];


    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int ans=0;

    for(int i=0; i<n; i++){
        //we will pair first i as with last i bs

        int d = 1e9;
        for(int j=0; j<i; j++){
            d = min(d, abs(b[n-i+j]-a[j]));
        }

        for(int j=i; j<n; j++){
            d= min(d, abs(a[j]-b[j-i]));
        }

        ans = max(ans, d);
    }
    cout<<ans<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}