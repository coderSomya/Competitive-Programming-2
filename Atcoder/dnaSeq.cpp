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

    int pref[n][4];
    
    pref[0][0]=s[0]=='A';
    pref[0][1]=s[0]=='T';
    pref[0][2]=s[0]=='C';
    pref[0][3]=s[0]=='G';
    for(int i=1; i<n; i++){
    pref[i][0]=pref[i-1][0]+(s[i]=='A');
    pref[i][1]=pref[i-1][1]+(s[i]=='T');
    pref[i][3]=pref[i-1][3]+(s[i]=='G');
    pref[i][2]=pref[i-1][2]+(s[i]=='C');
    }


    int ans=0;

    for(int i=0; i<n; i++){
        if(pref[i][0]==pref[i][1] && pref[i][2]==pref[i][3]) ans++;
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if((pref[j][0]-pref[i][0]==pref[j][1]-pref[i][1] && pref[j][2]-pref[i][2]==pref[j][3]-pref[i][3])) ans++;
        }
    }

    cout<<ans<<endl;
}
  
  
int32_t main(){
// int t;
// cin>>t;
// while(t--)
 solve();
return 0;
}