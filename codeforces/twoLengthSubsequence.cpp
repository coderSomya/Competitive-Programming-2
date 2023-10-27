#include <bits/stdc++.h>
using namespace std;

vector<int> s;
vector<int> t;
int n,k;

int dp[202][28][200];

int maxi(int i, int last, int k){

    int res=maxi(i+1, s[i], k);

    if(dp[i][last][k]!=-1) return dp[i][last][k];

    if(i==n) return 0;
    //s[i] is t[0]
    if(s[i]==t[0]){
        //keep it
        int get= (last==t[0]) && (s[i]==t[1]);

        res=max(res, get+ maxi(i+1,s[i], k));
        //change it to t[1]
        if(k!=0){
           int get2= (last==t[0]);
           res=max(res, get2+ maxi(i+1,t[1], k-1));
        }
    }

    else if(s[i]==t[1]){
        //keep it

        int get= last==t[0];

        res= max(res, get+ maxi(i+1,s[i], k));

        //change it to t[0]

        if(k!=0){
            int get2= (last==t[0]) && t[0]==t[1];

            res= max(res, get2+ maxi(i+1, t[0], k-1));
        }
    }

    else {
        if(k!=0){
             //change it to t[0]

             int get3= (last==t[0]) && (t[1]==t[0]);
            res= max(res, get3+ maxi(i+1, t[0], k-1));


            //change it to t[1]

            int get4 = (last==t[0]) ;

            res= max(res, get4+ maxi(i+1, t[1], k-1));
        }


        return dp[i][last][k] = res;

        
    }
   

}

void solve(){
    scanf("%d%d", &n, &k);


    string ss, tt;
    scanf("%s", &ss);
    scanf("%s", &tt);

    s.clear();
    t.clear();

    for(int i=0; i<n; i++){
        s.push_back(ss[i]-'a');
    }

    for(int i=0; i<2; i++){
        t.push_back(tt[i]-'a');
    }

    memset(dp, -1, sizeof(dp));

    int ans= maxi(0, 27, k);
    cout<<ans<<"\n";


}

int main(){
    int t;
    t=1;
    while(t-->0){
        solve();
    }

    return 0;
}