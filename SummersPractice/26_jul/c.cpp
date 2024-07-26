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
    int n; cin>>n; int q; cin>>q;
    string a,b; cin>>a>>b;

    int v1[n][26];
    int v2[n][26];

    memset(v1,0,sizeof(v1));
    memset(v2,0,sizeof(v2));

    v1[0][a[0]-'a']=1;
    v2[0][b[0]-'a']=1;

    for(int i=1; i<n; i++){
        for(int j=0; j<26; j++){
            v1[i][j]=v1[i-1][j]+ (a[i]=='a'+j);
            v2[i][j]=v2[i-1][j]+ (b[i]=='a'+j);
        }
    }

    while(q--){
        int l,r;
        cin>>l>>r;
        l--; r--;
        int ans = 0;
        for(int j=0; j<26; j++){
            int x = v1[r][j];
            if(l>0)x-=v1[l-1][j];
            int y = v2[r][j];
            if(l>0) y-= v2[l-1][j];

            ans+= max((int)0,x-y);
        }

        cout<<ans<<endl;
    }

    
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}