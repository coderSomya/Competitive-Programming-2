/*
problem link ->
https://codeforces.com/problemset/problem/1945/E
*/

/*
4 3 1 5 2 6
4 3 1 2 5 6
4 2 1 3 5 6
*/

//Hypothesis -> x needs to be between a smaller and a larger element adjacently.

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
    int n,x; cin>>n>>x;

    vi v(n);
    loop(i,0,n) cin>>v[i];

    int idx = -1;

    for(int i=0; i<n; i++){
        if(v[i]==x) idx=i;
    }

    int small, big;
    small=big=-1;

    for(int i=idx-1; i>=0; i--){
        if(v[i]<x) small=i;
    }
    for(int i=idx+1; i<n; i++){
        if(v[i]>x) big=i;
    }

    idx++; small++; big++;

    //only one element hai

    if(n==1){
        cout<<0<<endl;
        return;
    }

    //atleast 2 elements hai

    //x sabse left me hai

    if(idx==1){
        if(big!=0){
            cout<<1<<endl;
            cout<<idx+1<<" "<<big<<endl;
        }
        else{
            //evrything is smaller than idx

            //just put it in the last position
            cout<<1<<endl;
            cout<<idx<<" "<<n<<endl;
        }
        return;
    }

    //x sabse last me hai

    if(idx==n){
        if(small!=0){
            cout<<1<<endl;
            cout<<idx-1<<" "<<small<<endl;
        }
        else{
            cout<<1<<endl;
            cout<<idx<<" "<<1<<endl;
        }

        return;
    }


    //atleast 3 elements are there now...

    if(small!=0 && big!=0){
        cout<<2<<endl;
        cout<<idx-1<<" "<<small<<endl;
        cout<<idx+1<<" "<<big<<endl;
        return;   
    }


    //either there is nothing smaller on left or nothing greater on right
    if(small==0 and big==0){
        cout<<1<<endl;
        cout<<idx-1<<" "<<idx+1<<endl;
        return;
    } 

    //nothing smaller on left but something larger on right
    if(small==0){
        cout<<1<<endl;
        cout<<1<<" "<<idx<<endl;
        return;
    }
    //nothing bigger on right
    if(big==0){
        cout<<1<<endl;
        cout<<idx<<" "<<n<<endl;
        return;
    }


}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}