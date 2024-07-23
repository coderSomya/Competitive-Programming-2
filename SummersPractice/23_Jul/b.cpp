#include <bits/stdc++.h>
using namespace std;
#define loop(i, l, r) for (int i = l; i < r; i++)
#define int long long
#define pb push_back
#define vi vector<int>
#define mkp make_pair<int, int>
#define umpii unordered_map<int, int>
#define maxheap priority_queue<int>
#define minheap priority_queue<int, vi, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define in_arr(A, n) loop(i, 0, n) cin >> A[i];
#define p_arr(A, n) loop(i, 0, n) cout << A[i]
;
#define pln_arr(A, n) loop(i, 0, n) cout << A[i] << endl
#define take_n \
    int n;     \
    cin >> n;
#define take_arr \
    int arr[n];  \
    loop(i, 0, n) cin >> arr[i];

const int mod = 1e9 + 7;
const int inf = 1e15;

void solve()
{

    int n, m; cin>>n>>m;
    map<int,int> mp;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        if(mp.find(x) != mp.end()) mp[x]++;
        else mp[x] = 1;
    }

    vector<pair<int,int>>v;

    for(auto x: mp){
        v.pb({x.first, x.second});
    }

    sort(v.begin(), v.end());
    int ans = v[0].first*(min(m/v[0].first,v[0].second));
    int r  = v.size();
    for(int i=1; i<r; i++){
        if(v[i].first>m) break;
        int mon = m;
        // m/v[i].first
        int max_take = min(m/v[i].first, v[i].second);
        int max_val = max_take*v[i].first;

        int left = m - max_val;
        int p = 0;
        if(v[i-1].first==v[i].first-1){
           int take = min(left/v[i-1].first,v[i-1].second);
           p = take*v[i-1].first;
        }

        max_val += p;

        int temp = max_val-p;
        temp-= v[i].first;
        left+= v[i].first;
        if(v[i-1].first==v[i].first-1){
           int take2 = min(left/v[i-1].first,v[i-1].second);
           p = take2*v[i-1].first;
           temp+=p;
        }

  

        ans = max(ans, max_val);
        ans = max(ans, temp);
    }


    cout<<ans<<endl;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}