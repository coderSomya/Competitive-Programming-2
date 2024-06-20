/*
problem link->
https://codeforces.com/problemset/problem/1979/D
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
    int n,k; cin>>n>>k;
    string s; cin>>s;
    int x = n;


    vi v;
    int ct =   1;
    for(int i=1; i<n; i++){
        ct++;
        if(s[i]==s[i-1])continue;
        else{
            v.pb(ct-1);
            ct=1;
        }
    }

    v.pb(ct);

    /*
    m k k k k ... 2r+1 times.....k (k-m)

    k k k k m k k k (k-m)

    k k k k (k+r) k k k (k-r)

    k k k k k-r k k k k+r


    k k k k 2k k k k 2k


    k k k k-2 k k k 2

    11 00 11 00 111 00 11 00 1
    3 4 1 yes
    3 1 no

    3 3 1 3 2 yes

    5 yes

    1 1 1 2 1 0

    1 3 3 1

    k k k 2k k k k

    00 11 00 1111 00 11 00

    2 3 2 2 2 1

    */

   /*
   
   3 4 1
   (0,3),(2,1)

   1 1 1 2 1


   */
   vector<pair<int,int>> anomaly;

   for(int i=0; i<v.size(); i++){
    if(v[i]!=k){
        anomaly.push_back({i,v[i]});
    }
   }

   if(anomaly.size()>2){
    cout<<"-1"<<endl;
   }
   else if(anomaly.size()==0){
    cout<<n<<endl;
   }
   else if (anomaly.size()==1){
     int val = (int)anomaly[0].second;
     int prev_elements = anomaly[0].first*k;
     int groups_on_right = (n - (val+ prev_elements))/k;

     if(val/k!=2){
        cout<<"-1"<<endl;
        return;
     }

     if(groups_on_right%2==0){
        cout<<"-1"<<endl;
        return;
     }

     int p = prev_elements + k;

     cout<<p<<endl;
   }
   else{
    //one has to be on the last
       if(anomaly[1].first!=(v.size() - 1)){
        cout<<"-1"<<endl;
        return;
       }

       int x1 = anomaly[0].first;
       int y1 = anomaly[0].second;
       int x2 = anomaly[1].first;
       int y2 = anomaly[1].second;

       if(y1>=2*k || y2>=2*k){
         cout<<-1<<endl;
         return;
       }

       // k + r         .... k - r

       // k - m ...... m

       if((x2-x1)%2!=0){
        cout<<-1<<endl;
        return;
       }

       if(y1<k && y2 <k){
         int ans = x1*k + y1;
         cout<<ans<<endl;
         return;
       }

       if(y2>k){
        cout<<-1<<endl;
        return;
       }

       int ans  = x1*k + (y1-k);
       cout<<ans<<endl;

   }
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}