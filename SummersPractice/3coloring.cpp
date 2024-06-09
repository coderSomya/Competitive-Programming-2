/*
problem link ->
https://codeforces.com/problemset/problem/1503/B
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


int query(){
    int col;
    cin>>col;
    return col;
}

void print(int col, int i, int j){
    cout<<col<<" "<<i<<" "<<j<<endl;
}


void update_pos(pair<int,int> &pos, int n){
    int row = pos.first;
    int col = pos.second;

    if(col+2<=n){
        pos = {row, col+2};
    }
    else{
        if(row+1<=n){
            //shift to next row
            //1st, or 2nd pos?
            if(col%2){
                col=2;
            }
            else col=1;
            pos = {row+1, col};
        }
        else{
            // cout<<"control should never reach here"<<endl;
        }
    }
}
 
 
void solve(){
    int ct1; int ct2;
    ct1=ct2=0;

    int c1= 1; int c2=2;

    take_n
    /*
    1-> (i+j)/2 mod 2 == 0
    2-> (i+j)/2 mod 2 != 0
    */
   pair<int,int> curr1 = {1,1}; 
   pair<int,int> curr2 = {1,2}; 
   int q = n*n;

   //if the other is exhausted, we can put green here

   while(q--){
      int color = query();

      if(color == c1 || color == c2){
        // he gave something we are playing on..

        // so we should just put the other color somewhere
        if(color == c1){
            // check if we can c2
            if(ct2==(n*n)/2){
                // we have exhausted c2
                
                //put something else 
                print(3,curr1.first, curr1.second);
                update_pos(curr1,n);
                ct1++;
            }
            else{
                print(2,curr2.first, curr2.second);
                update_pos(curr2,n);
                ct2++;
            }
        }
        else{

            //similar thing 

            if(ct1==(n*n+1)/2){
                // we have exhausted c1
                
                //put something else 
                print(3,curr2.first, curr2.second);
                update_pos(curr2, n);
                ct2++;
            }
            else{
                print(1,curr1.first, curr1.second);
                update_pos(curr1, n);
                ct1++;
            }
        }

      }
      else{
        // we can use one of the colors we are playing with

        //arbitrarily choose c1
        if(ct1 != (n*n+1)/2){
            print(c1, curr1.first, curr1.second);
            update_pos(curr1,n);
            ct1++;
        }
        //or choose 2
        else{
            print(c2, curr2.first, curr2.second);
            update_pos(curr2,n);
            ct2++;
        }
      }
   }

}
  
  
int32_t main(){
solve();
return 0;
}