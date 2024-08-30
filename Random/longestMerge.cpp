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
 
 

  

string f(int AA, int BB, int AB){
    string ans;
    if(AA>=BB){
        for(int i=1; i<=BB; i++){
             ans+="AA";
            ans+="BB";
        }
   

        string res="";
        for(int j=0; j<AB; j++) res+="AB";
        res+=ans;

        if(AA-BB>0) res+="AA";

        return res;
    }

    else{
       
        for(int i=1; i<=AA; i++){
            ans+="BB";
            ans+="AA";
        }

        if(BB-AA>0) ans+="BB";

        string res="";
        for(int j=0; j<AB; j++) res+="AB";
        ans+=res;
        return ans;
    }
}  

void solve(){
    int i,j,k; 
    cin>>i>>j>>k;
    string ans = f(i,j,k);
    cout<<ans<<endl;
}
  
int32_t main(){
 solve();
return 0;
}

