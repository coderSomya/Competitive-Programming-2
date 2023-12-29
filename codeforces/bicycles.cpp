//not my code

#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h> 
 
using namespace std;
double EPS = 1e-12;
typedef long long int lld;
typedef pair<lld,lld> PA;
long double tick(){static clock_t oldt; clock_t newt=clock();
    long double diff=1.0L*(newt-oldt)/CLOCKS_PER_SEC; oldt = newt; return diff; }
#define rep(i,a,n) for(long long int i = (a); i <= (n); ++i)
#define repI(i,a,n) for(int i = (a); i <= (n); ++i)
#define repD(i,a,n) for(long long int i = (a); i >= (n); --i)
#define repDI(i,a,n) for(int i = (a); i >= (n); --i)
inline lld sc() { lld a; scanf("%lld", &a); return a; }
inline int scd() { int a; scanf("%d", &a); return a; }
#define prL(a) printf("%lld\n",a)
#define prS(a) printf("%lld ",a)
#define prdL(a) printf("%d\n",a)
#define prdS(a) printf("%d ",a)
#define all(c) (c).begin(), (c).end()
#define sz(a) ((int)a.size())
#ifdef LOCAL_RUN
#define Error(x...) { cout << "(" << #x << ")" << " = ( "; printIt(x); }
#else
#define Error(x...) 42
#endif
template <typename T1> void printIt(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void printIt(T1 t1, T2... t2) { cout << t1 << " , "; printIt(t2...); }
#define popcount __builtin_popcountll
 
#define lim 300010
#define lim2 200010
// std::ios::sync_with_stdio(false); // Ab :)
 
 
lld A[lim];
 
 
int main(){
    int tt = scd();
    while(tt--) {
        int n = scd(), m = scd();
        vector<vector<array<int, 2>>> G(n + 1);
        repI(i, 1, m) {
            int u = scd(), v = scd(), w = scd();
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }
        vector<lld> Slowness(n + 1, 0);
        repI(i, 1, n) {
            Slowness[i] = sc();
        }
        vector<vector<lld>> dist(n + 1, vector<lld>(1005, 1e18));
        dist[1][Slowness[1]] = 0;
        priority_queue<array<lld, 3>, vector<array<lld, 3>>, greater<array<lld, 3>>> pq;
        pq.push({0, 1, Slowness[1]});
        while(!pq.empty()) {
            array<lld, 3> top = pq.top();
            pq.pop();
            lld d = top[0], u = top[1], s = top[2];
            if(d > dist[u][s]) continue;
            for(array<int, 2> v : G[u]) {
                lld newDist = dist[u][s] + v[1] * s;
                lld newSlowness = min(s, Slowness[v[0]]);
                if(newDist < dist[v[0]][newSlowness]) {
                    dist[v[0]][newSlowness] = newDist;
                    pq.push({newDist, v[0], newSlowness});
                }
            }
        }
        lld ans = 1e18;
        repI(i, 1, 1000) {
            ans = min(ans, dist[n][i]);
        }
        prL(ans);
    }
    return 0;
}
