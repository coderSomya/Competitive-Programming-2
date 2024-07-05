/*
problem link ->
https://codeforces.com/problemset/problem/1846/F
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


int index_mimic(vi &pos, int n, int r){

    int ans = -1;
    for(int i=0; i<n; i++){
        if(pos[i]!=r) ans = i+1;
    }

    return ans;
}
 
 
void solve(){

    int n; cin>>n;

    int freq_prev[11]={0};
    int freq_curr[11]={0};
    vector<int> pos(n);
    for(int i=0; i<n; i++){
        cin>>pos[i];
        freq_prev[pos[i]]++;
    }

    cout<<"- 0"<<endl;


    for(int i=0; i<n; i++){
        cin>>pos[i];
        freq_curr[pos[i]]++;
    }

    bool flag = false;
    int form = -1;

    for(int i=1; i<=10; i++){
        if(freq_curr[i]>freq_prev[i]){
            flag = true;
            form = i;
        }
    }

    if(flag){
        // remove everything except the current form

        vi remove;
        for(int i=0; i<n; i++){
            if(pos[i]!=form){
                remove.pb(i+1);
            }
        }

        cout<<"- "<<remove.size()<<" ";
        for(int i=0; i<remove.size(); i++){
            cout<<remove[i]<<" ";
        }
        cout<<endl;

        n-= remove.size();

        //now we have only one type
        for(int i=0; i<n; i++){
            cin>>pos[i];
        }

        int index = index_mimic(pos,n, form);
        if(index!=-1){
            cout<<"! "<<index<<endl;
            return;
        }

        cout<<"- 0"<<endl;
        for(int i=0; i<n; i++){
            cin>>pos[i];
        }

        index = index_mimic(pos,n, form);

        cout<<"! "<<index<<endl;
        return;
    }

    for(int i=1; i<=10; i++){
        freq_prev[i] =freq_curr[i];
        freq_curr[i] = 0;
    }

    cout<<"- 0"<<endl;

 
    for(int i=0; i<n; i++){
        cin>>pos[i];
        freq_curr[pos[i]]++;
    }

    for(int i=1; i<=10; i++){
        if(freq_curr[i]>freq_prev[i]){
            flag = true;
            form = i;
        }
    }

    vi rem;

    for(int i=0; i<n; i++){
        if(pos[i]!=form){
            rem.pb(i+1);
        }
    }

    cout<<"- "<<rem.size()<<" ";

    for(int i=0; i<rem.size(); i++){
        cout<<rem[i]<<" ";
    }

    cout<<endl;

    n-=rem.size();

    for(int i=0; i<n; i++){
        cin>>pos[i];
    }

    int index = index_mimic(pos, n, form);

    if(index!=-1){
        cout<<"! "<<index<<endl;
        return;
    }

    cout<<"- 0"<<endl;

    for(int i=0; i<n; i++){
        cin>>pos[i];
    }

    index = index_mimic(pos, n, form);

    cout<<"! "<<index<<endl;
    
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--)
solve();
return 0;
}