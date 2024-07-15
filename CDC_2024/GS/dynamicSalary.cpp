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

void func()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    vector<set<int>> child(n + 1, set<int>());
    vi salary(n + 1);
    map<int, int> dad;
    int change[n + 1] = {0};
    for (int i = 1; i <= n; i++)
    {
        int sal;
        int par = -1;
        cin >> sal;
        if (i != 1)
        {
            cin >> par;
        }

        if (par != -1)
        {
            dad[i] = par;
        }

        salary[i] = sal;
    }

for(int i=1; i<=n; i++) cout<<salary[i]<<" ";
cout<<endl;
    while (m--)
    {
        char ch; cin>>ch;
        if (ch == 'p')
        {
            int x;
            int val;
            cin >> x >> val;
            change[x] += val;
        }
        else
        {
            int x; cin>>x;
            int temp = salary[x];
            if (x != 1)
            {
                temp += change[dad[x]];
            }

            cout << temp << endl;
        }
    }
}

void solve()
{
    func();
}

int32_t main()
{

        solve();
    return 0;
}