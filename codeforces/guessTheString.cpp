/*
problem link->
https://codeforces.com/problemset/problem/1697/D
*/

#include <bits/stdc++.h>
using namespace std;


int query(int l, int r){
    //return number of distinct in l...r
    l++; r++;
    cout<<"? 2 "<<l<<" "<<r<<endl;
    int res;
    cin>>res;
    return res;
}

char query(int i){
   //return char at i
   i++;
   cout<<"? 1 "<<i<<endl;
   char ch; cin>>ch;

   return ch;
}

void answer(string s){
    cout<<"! "<<s<<endl;
}


void solve(){
   int n; cin>>n;
   string s;

   s.push_back(query(0));

   set<int> relevant;
   relevant.insert(0);

   for(int i=1; i<n; i++){
     vector<int> v(relevant.begin(), relevant.end());

     int l=0; int r=v.size()-1;
     int ans=-1;
     while(l<=r){
        int mid=(l+r)/2;

        if(query(v[mid], i)==(v.size()-mid)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
     }

     if(ans==-1){
        s.push_back(query(i));
     }
     else{
        s.push_back(s[v[ans]]);
        relevant.erase(v[ans]);
     }
        relevant.insert(i);
   }

    answer(s);
}

int main(){
   solve();

    return 0;
}