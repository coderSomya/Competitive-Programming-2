/*
problem link ->
https://codeforces.com/problemset/problem/1968/G1
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

// rolling hash

const int BASE1 = 26;
const int BASE2 = 37;
const int mod2 = 1e9 + 9;

void computePrefixHashes(const string &s, vector<long long> &H1, vector<long long> &H2, vector<long long> &power_b1, vector<long long> &power_b2) {
    int n = s.size();
    H1[0] = H2[0] = 0;
    power_b1[0] = power_b2[0] = 1;
    for (int i = 1; i <= n; ++i) {
        H1[i] = (H1[i - 1] * BASE1 + s[i - 1]) % mod;
        power_b1[i] = (power_b1[i - 1] * BASE1) % mod;
        H2[i] = (H2[i - 1] * BASE2 + s[i - 1]) % mod2;
        power_b2[i] = (power_b2[i - 1] * BASE2) % mod2;
    }
}

pair<long long, long long> getSubstringHash(const vector<long long> &H1, const vector<long long> &H2, const vector<long long> &power_b1, const vector<long long> &power_b2, int l, int r) {
    long long hash_value1 = (H1[r] - H1[l] * power_b1[r - l]) % mod;
    if (hash_value1 < 0) {
        hash_value1 += mod;
    }
    long long hash_value2 = (H2[r] - H2[l] * power_b2[r - l]) % mod2;
    if (hash_value2 < 0) {
        hash_value2 += mod2;
    }
    return {hash_value1, hash_value2};
}

int bs(string s, int n, int len)
{
    string t = s.substr(0, len);

    int ps = 0;
    int pt = 0;

    vector<long long> H1(n + 1), H2(n + 1);
    vector<long long> power_b1(n + 1), power_b2(n + 1);

    // Compute prefix hashes and powers of BASE
    computePrefixHashes(s, H1, H2, power_b1, power_b2);
    pair<long long, long long> hash1 = getSubstringHash(H1, H2, power_b1, power_b2,0,len);


    int ct = 0;
    while (ps + len<= n)
    {
        pair<long long, long long> hash2 = getSubstringHash(H1, H2, power_b1, power_b2, ps, ps+len);
        if (hash1==hash2)
        {
            ps += len;
            ct++;
        }
        else
        {
            ps += 1;
        }
    }

    return ct;
}

void solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    string s;
    cin >> s;

    int low = 1;
    int hi = n / l;

    int ans = 0;

    while (low <= hi)
    {
        int mid = (low + hi) / 2;

        // can we make a prefix of lenght mid as the best
        // lcp ?

        int k = bs(s, n, mid);
        if (k >= l)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    cout << ans << endl;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}