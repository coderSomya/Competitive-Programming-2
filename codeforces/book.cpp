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
    
    vector<vector<int>> adj(n+1);
        vector<int> indegree(n+1,0);

    loop(i,1,n+1){
        int k; cin>>k;
        loop(j,0,k){
         int x; cin>>x;
         adj[x].push_back(i);
         indegree[i]++;
        }
    }


    minheap mh;
    minheap cmh;
    


    int done[n+1]={0};
    int steps=0;


 for(int i=1; i<=n; i++){
    if(indegree[i]==0) {
        mh.push(i);
 }
 }

 while(!mh.empty()){
    steps++;
    if(steps>n) {
        cout<<-1<<endl;
        return;
    }

    minheap naya;

     while(!mh.empty()){

        int x= mh.top();
        mh.pop();

        done[x]=1;
        for(auto m: adj[x]){
            indegree[m]--;
            if(indegree[m]==0){
                if(m<x){
                    naya.push(m);
                }
                else mh.push(m);
            }
        }
    
     }


        mh=naya;  
   
 }


  
    
    
    bool flag=true;
    for(int i=1; i<=n; i++){
      flag&= done[i];
    }

    if(flag) cout<<steps<<endl;
    else cout<<-1<<endl;

    
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}