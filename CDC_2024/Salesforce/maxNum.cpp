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


map<int, int> mp;

int func(string s){
    int n = s.size();

    int dp[n][2][5];

    mp['A']=1;
    mp['B']=10;
    mp['C']=100;
    mp['D']=1000;
    mp['E']=10000;
    //dp[i] -> max v

    //i , j , k denotes, ith pos, j changed, k is the max seen so far


    for(int i=0; i<n; i++) for(int j=0; j<2; j++) for(int k=0; k<5; k++) dp[i][j][k] = -inf;

    dp[n-1][0][s[n-1]-'A'] = mp[s[n-1]];
    for(int i=0; i<5; i++){
        if(i!=s[n-1]-'A'){
            dp[n-1][1][i] = mp['A'+i];
        }
    }

    for(int i=n-2; i>=0; i--){
        for(int ch=0; ch<5; ch++){

            //at ith pos, i want to have ch

            if(s[i]=='A'+ch){

                // i  dont need to change here 

                //chr is max seen before ith pos
                for(int chr=0; chr<=s[i]-'A'; chr++){
                    dp[i][0][ch]= max(dp[i][0][ch],mp['A'+ch]+ dp[i+1][0][chr]);
                    dp[i][1][ch]= max(dp[i][1][ch],mp['A'+ch]+ dp[i+1][1][chr]);
                }
                for(int chr = (s[i]-'A')+1; chr<5; chr++){
                    //something bigger is alredy seen
                    dp[i][0][chr]  = max(dp[i][0][chr], -1*mp[s[i]] + dp[i+1][0][chr]);
                    dp[i][1][chr] = max(dp[i][1][chr], -1*mp[s[i]] + dp[i+1][1][chr]);
                }
            }

            else{
                // i have to change here itself

                // so shouldn't have changed before
                for(int chr = 0; chr<5; chr++){
                    if(chr<=ch) dp[i][1][ch] = max(dp[i][1][ch], mp[ch+'A']+dp[i+1][0][chr]);
                    else dp[i][1][chr] = max(dp[i][1][chr], -1*mp[ch+'A'] + dp[i+1][0][chr]);
                }
            }
        }
    }

    int ans = -inf;

    for(int i=0; i<5; i++){
        for(int j=0; j<2; j++){
            ans = max(ans, dp[0][j][i]);
        }
    }
    cout<<ans<<endl;

    return 0;
}
void solve(){


    string s;
    cin>>s;

     func(s);
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}