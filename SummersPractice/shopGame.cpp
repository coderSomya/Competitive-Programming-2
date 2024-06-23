/*
problem link->
https://codeforces.com/problemset/problem/1969/D
*/

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

auto comparator = [](const std::pair<std::pair<int, int>, int> &a, const std::pair<std::pair<int, int>, int> &b)
{
    if (a.first.first != b.first.first)
    {
        return a.first.first > b.first.first; 
    }
    return a.first.second < b.first.second;
};

void solve()
{
    int n, k;
    cin >> n >> k;

    int a[n], b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    vector<pair<pair<int, int>, int>> v;
    loop(i, 0, n) v.pb({{b[i]-a[i], b[i]},i});

    sort(v.begin(), v.end(), comparator);

    multiset<int> mst;

    int a_sum,b_sum,big_k;
    a_sum =b_sum = big_k = 0;
    for(int i=0; i<k; i++){
        int idx = v[i].second;
        mst.insert(b[idx]);
        big_k+=b[idx];
        a_sum+=a[idx];
        b_sum+=b[idx];
    }

    int ans = 0;
    for(int i=k; i<n; i++){
        int now = v[i].second;
        int a_now = a[now];
        int b_now = b[now];

        a_sum+=a[now];
        b_sum+=b[now];

        if(mst.size()!=0){
            int small = *mst.begin();
            if(b_now>small){
                mst.erase(mst.find(small));
                mst.insert(b_now);
                big_k-=small;
                big_k+=b_now;
            }
        }

        int sum = b_sum - big_k - a_sum;
        ans = max(ans, sum);
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