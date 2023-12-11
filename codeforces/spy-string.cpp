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


string ans;
string global_ans;

const int N=10;

int dp[N][(1<<N)+1];

int n,m;
vector<string> v(N);
 
bool rec(int pos, int mask){

    if(pos==m){
        global_ans=ans;
        return true;
    }

   
   if(dp[pos][mask]!=-1) return dp[pos][mask];
    bool temp=false;

    for(int j=0; j<26; j++){
        //i want to place 'a'+j
        bool flag=true;
        for(int i=0; i<n; i++){
          if((v[i][pos]!='a'+j) && ((mask&(1<<i))==0)) flag=false;
          break;
        }
        if(flag){
        //yes we can place it
        //so mark those who are affected by this operation

        ans+='a'+j;
        int temp_mask=mask;

        for(int i=0; i<n; i++){
            if(v[i][pos]!='a'+j && mask&(1<<i)) temp_mask^=(1<<i);
        }

        temp=temp|rec(pos+1, temp_mask);

        ans.pop_back();


        }
    }

    return dp[pos][mask]=temp;
}
 
void solve(){
  cin>>n>>m;
  
  for(int i=0; i<n; i++){
    cin>>v[i];
  }

    ans="";
    global_ans="";
  memset(dp, -1 ,sizeof(dp));

  int init_mask=(1<<n)-1;

  bool ans=rec(0,init_mask);

  if(ans){
    cout<<global_ans<<endl;
  }
  else cout<<"-1"<<endl;

  
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}