/*
problem link->
https://codeforces.com/problemset/problem/1957/D
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
    take_n
    take_arr

    vector<vector<int>> odds(31, vector<int>(n));
    vector<vector<int>> even(31, vector<int>(n));
    vector<vector<int>> even1(31, vector<int>(n));
    vector<vector<int>> odds1(31, vector<int>(n));

    for(int i=0; i<=30; i++){
        if(arr[0]&(1<<i)){
            odds[i][0]=1;
            even[i][0]=0;
        }else{
            odds[i][0]=0;
            even[i][0]=1;
        }
    }

    for(int i=0; i<=30; i++){
        if(arr[n-1]&(1<<i)){
            odds1[i][n-1]=1;
            even1[i][n-1]=0;
        }else{
            odds1[i][n-1]=0;
            even1[i][n-1]=1;
        }
    }

    for(int j=0; j<=30; j++){
        int is_set = odds[j][0];
        for(int i=1; i<n; i++){
            int is_set_locally = ((arr[i]&(1<<j))!=0) ? 1 : 0;
            is_set = is_set ^ is_set_locally;
            if(is_set){
                odds[j][i]=odds[j][i-1]+1;
                even[j][i]= even[j][i-1];
            }else{
                odds[j][i]=odds[j][i-1];
                even[j][i]= even[j][i-1]+1;
            }
        }
    }


    for(int j=0; j<=30; j++){
        int is_set = odds1[j][n-1];
        for(int i=n-2; i>=0; i--){
            int is_set_locally = ((arr[i]&(1<<j))!=0) ? 1 : 0;
            is_set = is_set ^ is_set_locally;
            if(is_set){
                odds1[j][i]=odds1[j][i+1]+1;
                even1[j][i]= even1[j][i+1];
            }
            else{
                odds1[j][i]=odds1[j][i+1];
                even1[j][i]= even1[j][i+1]+1;
            }
        }
    }

    int ans = 0;

    for(int i=0; i<n; i++){
        for(int j=30; j>=0; j--){
            if(arr[i]&(1<<j)){

                // vi nodd(odds[j]);
                // vi nev(even[j]);
                
                // vi bodd(odds1[j]);
                // vi bev(even1[j]);
                //

                int t1 = (odds[j][n-1] - odds[j][i])*(odds1[j][0]-odds1[j][i]);
                int t2 = (even[j][n-1] - even[j][i])*(even1[j][0]-even1[j][i]);
                
                ans += t1 + t2;

                //we need to add the series where we start at i
                ans+= odds[j][n-1]- odds[j][i];
                ans+= odds1[j][0] - odds1[j][i];
                break;
            }
        }
    }

    cout<<ans<<endl;


}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}