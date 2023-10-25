/*
problem link ->
https://codeforces.com/problemset/problem/1697/C
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    string s,t;
    cin>>s>>t;

    int as, at,cs,ct;

    as=at=cs=ct=0;

    for(int i=0; i<n; i++){
        as+=s[i]=='a';
        cs+=s[i]=='c';
        at+=t[i]=='a';
        ct+=t[i]=='c';

        if(as<at){
            cout<<"NO\n";
            return;
        }
        if(cs>ct){
            cout<<"NO\n";
            return;
        }
    }
    
    
  string ss,tt;
    for(int i=0; i<n;i++){
        if(s[i]!='b') ss+=s[i];
        if(t[i]!='b') tt+=t[i];
    }

    if(ss!=tt) cout<<"NO\n";
    else cout<<"YES\n";
}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}
