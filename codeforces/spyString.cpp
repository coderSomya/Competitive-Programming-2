#include <bits/stdc++.h>
using namespace std;







bool res(int i, int mask, int ch){
   
   // i want to place 'a'+ch at ith position and i get the mask mask
   // if it is different from any of the strings, i must be coming from a place whose bit was unset in prev mask so i will see if the ans there was yes, and then i will put this character in this place. hence this way i will have my overall ans
}

void solve(){
    int n,m;
    cin>>m>>n;
    vector<string> v;
    int dp[n][(1<<m)+1][26];
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<m; i++){
        string s; cin>>s;
        v.push_back(s);
    }
    int maxmask = (1<<m) -1;

    for(int i=0; i<26; i++){
        //i want to put this in the first place
        int mask=0;
        for(int j=0; j<m; j++){
            if(v[j][0]-'a'!=i){
                mask=mask|(1<<j);
            }
        }
        dp[0][mask][i]=1;
    }




    for(int i=1; i<n; i++){
        for(int mask=0; mask<=maxmask; mask++){
            for(int ch=0; ch<26; ch++){
                int ct=0;
                bool flag=true;
                int prev_mask= mask;
                for(int str = 0; str<m; str++){
                   //check if this string differs

                   string t= v[str];
                   if(t[i]-'a'==ch){
                      //unaffected
                   }
                   else{
                     if(mask&(1<<str)){
                        //it has to be set in this operation
                        prev_mask = prev_mask^(1<<str);
                     }
                     else{
                        //it cannot be that this is unset after this pos
                        flag=false;
                        break;
                     }
                   }
                }

                if(flag){
                    //it was possible to put this char in this pos with this mask
                    for(int prev_ch = 0; prev_ch<26; prev_ch++){
                        if(dp[i-1][prev_mask][prev_ch]) {
                            dp[i][mask][ch]=1;
                        }
                    }
                }
            }
        }
    }
    

    //the above code will give me yes/no it is possible or not to have such a string

    int ans=0;
    int mm,cc;
    for(int i=0; i<26; i++){
        for(int mask=0; mask<=maxmask; mask++){
            if(dp[n-1][mask][i]) {
                ans=1;
                mm=mask;
                cc=i;
                break;
            }
        }
    }

    if(ans==0){
        cout<<-1<<endl;
        return;
    }

    //create the ans

    string res="";
    res+='a'+cc;
    for(int i=n-2; i>=0; i--){

        for(int j=0; j<m; j++)
        {
            string f=v[j];
            if(res.back() != f[i+1]){
                // it has to be unsetted from the mask going forward
                mm=mm^(1<<j);
            }

            //now we have to see if theres any character at the current position which can satisfy this mask 
          
        }
         char put;
            for(int g=0; g<26; g++){
                if(dp[i][mm][g]){
                 put='a'+g;
                 break;
                }
            }

            res+=put;

    }

    reverse(res.begin(), res.end());

    cout<<res<<endl;

    
   
}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}