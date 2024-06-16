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
    int n,c;
    cin>>n>>c;

    vi v(n);
    int pref[n];
    multiset<int> mst;
    multiset<int> rst;
    loop(i,0,n) {
        cin>>v[i];
        mst.insert(v[i]);
        pref[i]= v[i];
        if(i>0) pref[i]+=pref[i-1];
    }


    if(n==1){
        std::cout<<0<<endl;
        return;
    }

    int umax = v[0]+c;
    int ans[n];

    mst.erase(mst.find(v[0]));
    if(umax>=*mst.rbegin()){
        ans[0]=0;
    }
    else ans[0]=1;
    rst.insert(v[0]);

    for(int i=1; i<n; i++){
        int temp = 0; 

        if(v[i]<=umax){
            //take everything on the left
            temp = i;
            if(*mst.rbegin() > pref[i]+c){
                //take the max from the right
                temp+=1;
            }
        }
        else{
            if(v[i]>*rst.rbegin() && v[i]>=*mst.rbegin()){
                temp = 0;
                //he is the max

            }
            else if(v[i]>=*mst.rbegin()){
                //everything is smaller on the right
                //but something larger exists on the left

                //have to take everythin on the left

                temp+=i;
            }
            else if(v[i]>=*rst.rbegin()){
                // everything smaller on the left
                // something larger exists on the right

                //first take evrything on the left

                temp+=i;
                int me = pref[i]+c;

                if(me<*mst.rbegin()){
                    //take the larget on the right

                    temp+=1;
                }
            }
            else{

                temp = i;
                int me = pref[i]+c;
                if(me<*mst.rbegin()){
                    temp+=1;
                }
            }
        }


        ans[i]=temp;
        mst.erase(mst.find(v[i]));
        rst.insert(v[i]);
    }


    loop(i,0,n)std::cout<<ans[i]<<" ";
    std::cout<<endl;


}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}