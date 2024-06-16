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
 

void swap(int arr[], int l ,int r){
    int temp = arr[l];
    arr[l]=arr[r];
    arr[r] = temp; 
}
 
void solve(){

    int n, k; cin>>n>>k;
    int arr[n+1];

    for(int i=1; i<=n; i++){
        arr[i] = i;
    }

    int l = 1;
    int r = n;

    if(k%2){
        cout<<"NO"<<endl;
        return;
    }

    k/=2;
    while(l<=r){
        if(k==0) break;
        int diff = r - l;
        if(k>=diff){
            swap(arr, l, r);
            k-=diff;
        }
        else{
            swap(arr, l, l+k);
            k = 0;
        }
        l++;
        r--;
    }

    if(k!=0){
        cout<<"No"<<endl;
        return;
    }

    cout<<"YES"<<endl;
    for(int i=1; i<=n; i++) cout<<arr[i]<<" ";
    cout<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}