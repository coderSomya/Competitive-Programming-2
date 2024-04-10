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

problem ->
pick any l...r and XOR every element with any m, and maximize the number of elements in the array 
with value val
*/

int maxFreq(vector<int> v, int val){
    int n = v.size();

    //LOGIC

    /*
    fi(r) - fi[l-1] + val[l-1] + val[n-1]- val[r]

    where val[i] = frequency of val till i
    fi(j) = freq of i till j

    =) maximize fi(r) - val[r] - (fi[l-1]- val[l-1]) + val[n-1]

    =) maximize F[r] - F[l-1]  + val[n-1]
    for every index i, lets find the answer if i is r,
    so find the min F[arr[i]] so far
    */

   vector<int> vals(n);
   unordered_map<int, int> freq;
   unordered_map<int, int> mini;
   vals[0] = (v[0]==val);
   for(int i=1; i<n; i++) vals[i]=vals[i-1]+(v[0]==val);
   int ans =0;

   for(int i=0; i<n; i++){
     if(freq.find(v[i])!=freq.end()){
        freq[v[i]]++;

        int t1 = freq[v[i]] - vals[i];
        int t2 = mini[v[i]];
        int temp = t1-t2;
        if(i!=n-1) temp+=vals[n-1];
        ans = max(ans, temp);

        mini[v[i]]=min(mini[v[i]], t1);
     }

     else{
        //take only one element
        freq[v[i]]=1;
        int t1 = freq[v[i]];
        int temp= t1;

        if(i!=n-1) temp+=vals[n-1];

        ans = max(temp, ans);
        mini[v[i]]= min((long long)0,t1);
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