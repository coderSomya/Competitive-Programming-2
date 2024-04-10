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

/*
Problem ->
there are two arrays arr1 and arr2

given k, 

choose any k indices and maximize 

(arr2[i1]+arr2[i2]+arr2[i3]...)*(min(arr1[i1], arr1[i2], arr1[i3],.....))

where i1, i2 ... ik are the chosen k indices
*/

int maxVal(vector<int>& arr1, vector<int>& arr2, int k){

    vector<pair<int, int>> v;
    int n = arr1.size();
    for(int i = 0; i < n; i++){
        v.push_back({arr2[i], i});
    }

    sort(v.rbegin(), v.rend());

    set<int> st;
    int sum, sum2;
    sum=sum2=0;
    int mini = 1000000;
    int smini = 1000000;
    int minidx = -1;
    for(int i=0; i<k; i++){
        st.insert(v[i].second);
        sum+=v[i].first;
        sum2+=v[i].first;
    }

    for(int i=0; i<k; i++){
        int elem = arr1[v[i].second];

        if(elem<mini){
            minidx = i;
            smini = mini;
            mini = elem;
        }
        else if (elem <smini){
            smini = elem;
        }
    }
    sum2-=arr2[minidx];

    int ans = sum*mini;

    for(int i=0; i<n; i++){
        int idx = i;

        if(st.find(idx)==st.end()){
            if(arr1[idx]>mini){
                ans = max(ans, (sum2 + arr2[idx])*min(smini, arr1[idx]));
            }
        }
    }

    return ans;
}
 
 
void solve(){
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}