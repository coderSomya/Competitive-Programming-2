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

int n, m;
vector<vector<pair<int, int>>> adj;
vector<vector<pair<int, int>>> radj;

vector<vector<int>> edges;

void reverse_edges()
{
    for (auto edge : edges)
    {
        int u, v, w;
        u = edge[0];
        v = edge[1];
        w = edge[2];
        radj[v].push_back(pair<int, int>(u, w));
    }
}

void dijkstra(int src, vi &dist)
{

    for (int i = 0; i < n + 1; i++)
    {
        dist[i] = inf;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, src});
    dist[src] = 0;
    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if (dist[u] < dist[src])
            continue;
        for (auto x : adj[u])
        {
            int v = x.first;
            int wt = x.second;
            if (dist[v] > dist[u] + wt)
            {
                dist[v] = dist[u] + wt;
                q.push({dist[v], v});
            }
        }
    }
}

void solve()
{
    cin >> n >> m;

    adj.clear();
    adj.resize(n + 1);
    radj.clear();
    radj.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});

        vi edge = {u, v, w};

        edges.push_back(edge);
    }

    vi dist(n + 1);
    dijkstra(1, dist);

    reverse_edges();
    adj = radj;

    vi dist2(n + 1);
    dijkstra(n, dist2);
    int ans = inf;

    for (auto edge : edges)
    {
        int u, v, w;
        u = edge[0];
        v = edge[1];
        w = edge[2];

        // apply the discount on this edge

        int x = dist[u] + dist2[v];
        int r = x;
        r += w / 2;

        ans = min(ans, r);
    }

    cout << ans << endl;
}

int32_t main()
{
    // int t;
    // cin>>t;
    // while(t--)
    solve();
    return 0;
}