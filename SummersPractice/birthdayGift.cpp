/*
problem link->
https://codeforces.com/problemset/problem/1946/D
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

const int N = 1e5+1;
const int M = 31;
int mat[M][N];

int check(set<int> risky, int n, int x){
    set<int> riksy;
    int ans = 0;

    for(int i=0; i<n; i++){
        for(int bit: risky){
            int val = mat[bit][i];

            if(val==1){
                if(riksy.find(bit)==riksy.end()){
                    riksy.insert(bit);
                }else riksy.erase(bit);
            }
        }
        if(riksy.size()==0){
            ans++;
        }
    }

    return ans;
}
 
void solve(){

    int n, x;
    cin>>n>>x;
    int  arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    for(int i=0; i<n; i++){
        for(int bit=0; bit<=30; bit++){
            mat[bit][i]= ((arr[i]&(1<<bit))!=0);
        }
    }

    set<int> risky;
    for(int bit =30; bit>=0; bit--){
        int ct=0;
        for(int i=0; i<n; i++){
            ct+=mat[bit][i];
        }
        int at=ct%2;
        int st = (x&(1<<bit))!=0 ? 1:0;

        if(st>ct){
            cout<<"-1"<<endl;
            return;
        }
        if(st==1 && at==1){
            continue;
        }
        else if(st==1 && at==0){
            risky.insert(bit);
        }
        else if(st==0 && at==0){
//check till here
        risky.insert(bit);
        int ans = check(risky,n,x);
        if(ans){
            cout<<ans<<endl;
            return;
        }else risky.erase(bit);
        }else{
            int ans = check(risky, n,x);
            cout<<ans<<endl;
            return;
        }
    }


    cout<<-1<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}