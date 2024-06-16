/*
problem link ->
https://codeforces.com/problemset/problem/1985/H1
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



class DSU {
public:

   vector<vector<pair<int,int>>> parent;
   vector<vector<int>> rank;

public:
    DSU(int n, int m) {
        parent.resize(n, vector<pair<int,int>>(m));
        rank.resize(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for(int j=0; j<m; j++){
                parent[i][j] = {i,j};
                rank[i][j] = 1;
            }
        }
    }

    pair<int,int> find(int x, int y) {
        if (parent[x][y] != make_pair(x, y)) {
            pair<int,int> curr_parent = parent[x][y];
            parent[x][y] = find(parent[curr_parent.first][curr_parent.second].first,parent[curr_parent.first][curr_parent.second].second); // Path compression
        }
        return parent[x][y];
    }

    // Union by rank
    void unite(pair<int,int> x, pair<int,int> y) {
        pair<int,int> rootX = find(x.first, x.second);
        pair<int,int> rootY = find(y.first, y.second);

        if (rootX != rootY) {
            if (rank[rootX.first][rootX.second] >= rank[rootY.first][rootY.second]) {
                rank[rootX.first][rootX.second]+=rank[rootY.first][rootY.second];
                parent[rootY.first][rootY.second] = rootX;
            } else {
                rank[rootY.first][rootY.second]+=rank[rootX.first][rootX.second];
                parent[rootX.first][rootX.second] = rootY;
            }
        }
    }
};


 
 
void solve(){
    int n,m; 
    cin>>n>>m;

    vector<vi> grid(n, vi(m,0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char c; cin>>c;
            if(c=='.') grid[i][j]=0;
            else grid[i][j] = 1;
        }
    }

    DSU dsu(n,m);

    //merge

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(j!=0){
                //left se merge
                if(grid[i][j] == 1 && grid[i][j-1] == 1){
                    dsu.unite(make_pair(i,j), make_pair(i, j-1));
                }
            }
            if(i!=0){
                //top se merge
                if(grid[i][j] == 1 && grid[i-1][j] == 1){
                    dsu.unite(make_pair(i,j), make_pair(i-1,j));
                }
            }
        }
    }

    int ans  = 0;


    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //        if(grid[i][j]==0) dsu.rank[i][j]=0;
    //     }
    // }



    for(int i=0; i<n; i++){
        //try every row

        set<pair<int,int>> st;
        for(int j=0; j<m; j++){
            st.insert(dsu.find(i,j));
        }
        if(i>0){
            for(int j=0; j<m; j++){
                if(grid[i-1][j]!=0)
                st.insert(dsu.find(i-1,j));
            }
        }
        if(i<n-1){
            for(int j=0; j<m; j++){
                if(grid[i+1][j]!=0)
                st.insert(dsu.find(i+1,j));
            }
        }

        int temp = 0;
        for(auto x: st){
            int r = x.first;
            int c = x.second;

            temp += dsu.rank[r][c];
        }


        ans  = max(ans, temp);
    }


    for(int j=0; j<m; j++){
        //try every column

        set<pair<int,int>> st;
        for(int i=0; i<n; i++){
            st.insert(dsu.find(i,j));
        }
        if(j>0){
            for(int i=0; i<n; i++){
                if(grid[i][j-1]!=0)
                st.insert(dsu.find(i,j-1));
            }
        }
        if(j<m-1){
            for(int i=0; i<n; i++){
                if(grid[i][j+1]!=0)
                st.insert(dsu.find(i,j+1));
            }
        }

        int temp = 0;
        for(auto x: st){
            int r = x.first;
            int c = x.second;

            temp += dsu.rank[r][c];
        }


        ans  = max(ans, temp);
    }

    cout<<ans<<endl;


}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}