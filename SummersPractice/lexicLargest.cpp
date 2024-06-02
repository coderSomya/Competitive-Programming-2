/*
problem link ->
https://codeforces.com/problemset/problem/1930/C
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


void solve2(){
    
    int n; cin>>n;
    vi v(n);

    loop(i,0,n) cin>>v[i];

    vi uniq;
    loop(i,0,n) uniq.pb(v[i]+i+1);

    sort(uniq.rbegin(), uniq.rend());

    vi ans;

    unordered_map<int,int> seen;
    unordered_map<int,int> put;

    for(int i=0; i<n; i++){
        int a = uniq[i];

        // it must have changed so far, lets see how much
        int x = (seen.find(a) == seen.end()) ? 0 : seen[a];
        int b = a - x;

        int y = (put.find(b) == put.end()) ? 0 : put[b];

        //so seen should always store the exact count
        seen[a]++;
        ans.pb(b-y);

        //put should store the modified count
        put[b-y]++;
    }    


    loop(i,0,n) cout<<ans[i]<<" ";
    cout<<endl;
}

 
void solve(){

    int n; cin>>n;
    vi v(n);

    loop(i,0,n) cin>>v[i];

    vi uniq;
    loop(i,0,n) uniq.pb(v[i]+i+1);

    sort(uniq.rbegin(), uniq.rend());

    vi ans;

    unordered_map<int,int>mp;
    for(int i=0; i<n; i++){
        int r = (mp.find(uniq[i])!=mp.end()) ? mp[uniq[i]] : 0;
        int x = uniq[i]-r;

        mp[uniq[i]]++;
        ans.pb(x);
    }

    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve2();
return 0;
}


/*

its better to remove things from the back

however its unoptimal when doing so reduces an element

6 5 4 3 2 1
1 1 1 1 1 1

7 6 5 4 3 2
7 7 7 7 7 7

8 10 ..... 6 8 9...

6 5 4 3 2 1
1 2 3 4 5 6

7

2 1
1 2


....  ..x-1... x......x-1 ....x-1...
x
x-1
x-2

x
x-1

set<set<int>> st?????


2 1
1 2

3,3

3, 
2

3 2

7 7 7 7 7 7
7 6 5 4 3 2

*/ 