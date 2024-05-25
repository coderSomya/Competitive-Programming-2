/*
problem link ->
https://codeforces.com/problemset/problem/1932/E
*/


/*

2 + 4*10 + 4

5 + 4*10 + 3*100 + 2*1000 + 1*10000
4 + 3*10 + 2*100 + 1*1000
3 + 2*10 + 1*100
2 + 1*10
1

15 + 10*10 + 6*100  + 3*1000 + 1*10000
15+ 100 + 600 + 3000 + 10000

4,  6
6, 4

9, 18
18 + 9



99

9 + 9*10
9

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
    string s; cin>>s;

    string sum;
    vi v(n);
    loop(i,0,n) v[i]=s[i]-'0';

    vi pref(n);
    pref[0]=v[0];
    loop(i,1,n) pref[i]=pref[i-1]+v[i];

    /*
    1 , (1+2), (1+2+3), (1+2+3+4), (1+2+3+4+5)

    15 
    */
     
    reverse(pref.begin(), pref.end());
    int carry=0;
    for(int i=0; i<pref.size(); i++){
        int num = pref[i]+carry;
        int d = num%10;
        carry = num/10;

        sum+=char(d+'0');
    }

        sum += (char)(carry + '0');
        while (sum.back() == '0') {
            sum.pop_back();
        }

        reverse(sum.begin(), sum.end());
    std::cout<<sum<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}