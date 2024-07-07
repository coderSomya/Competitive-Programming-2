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

int bs(int arr[], int l, int r, int val){
    
    int p = l;

    int ans = r;
    while(l<=r){
        int mid = (l+r)/2;

        if(arr[mid]-arr[p-1]>=val){
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }

    return ans;
}

void print(int la, int ra, int lb, int rb, int lc, int rc){
    cout<<la+1<<" "<<ra+1<<" "<<lb+1<<" "<<rb+1<<" "<<lc+1<<" "<<rc+1<<endl;
}
 
 
void solve(){
    take_n
    int a[n];
    int b[n];
    int c[n];
    loop(i,0,n) cin>>a[i];
    loop(i,0,n) cin>>b[i];
    loop(i,0,n) cin>>c[i];

    int tot = 0;
    loop(i,0,n) tot+=a[i];

    int r = (tot+2)/3;

    loop(i,1,n){
        a[i]+=a[i-1];
        b[i]+=b[i-1];
        c[i]+=c[i-1];
    }

    for(int i=1; i<n; i++){
        if(a[i-1]>=r){
            int x = bs(b, i, n-1, r);
      

            //a[i]...a[x]>tot/3 for b
            if(c[n-1]- c[x]>= r){
                print(0,i-1,i,x,x+1,n-1);
                return;
            }

            int y = bs(c,i,n-1,r);

            if(b[n-1]-b[y]>=r){
                print(0,i-1,y+1,n-1,i,y);
                return;
            }
        }

        if(b[i-1]>=r){
            int x = bs(a, i,n-1, r);

            //a[i]...a[x]>tot/3 for b
            if(c[n-1]- c[x]>= r){
                print(i,x,0,i-1,x+1,n-1);
                return;
            }

            int y = bs(c,i,n-1,r);

            if(a[n-1]-a[y]>=r){
                print(y+1,n-1,0,i-1,i,y);
                return;
            }
        }

        if(c[i-1]>=r){
            int x = bs(a, i,n-1, r);

            //a[i]...a[x]>tot/3 for b
            if(b[n-1]- b[x]>= r){
                print(i,x,x+1,n-1,0,i-1);
                return;
            }

            int y = bs(b,i,n-1,r);

            if(a[n-1]-a[y]>=r){
                print(y+1,n-1,i,y,0,i-1);
                return;
            }
        }
    }

    cout<<"-1"<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}