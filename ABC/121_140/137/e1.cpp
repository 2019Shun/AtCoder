#include "bits/stdc++.h"
#define ALL(obj) (obj).begin(),(obj).end()
#define RALL(obj) (obj).rbegin(),(obj).rend()
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = (int)(n); i >= 0; i--)
#define FOR(i,n,m) for(int i = (int)(n); i < int(m); i++)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 6;
const ll LLINF = 4e18;
 
// bellman-ford法
struct edge { int to, cost; };
 
void bellman_ford(int s, int n, const vector<vector<edge>> &G, vector<ll> &d) {
    const int V = G.size();
    d = vector<ll>(V, LLINF);
    d[s] = 0;
    bool update = true;
    int i = 0;
    while (update)
    {
        update = false;
        for (int j = 0; j < V; j++)
        {
            for (edge e : G[j])
            {
                if (d[j] != -LLINF && d[j] != LLINF && d[j] + e.cost < d[e.to]) {
                    d[e.to] = d[j] + e.cost;
                    if (i == V - 1) {
                        d[e.to] = -LLINF;
                    }
                    update = true;
                }
                else if (d[j] == -LLINF && d[e.to] != -LLINF) {
                    d[e.to] = -LLINF;
                    update = true;
                }
            }
        }
        if (i < V - 1) i++;
    }
}
 
int main() {
    int n, m, p; cin >> n >> m >> p;
    vector<vector<edge>> G(n);
    vector<ll> dist(n);
    REP(i, m) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--; c -= p;
        c *= -1;
        G[a].push_back({b,c});
    }
    bellman_ford(0, n - 1, G, dist);
    if (dist[n - 1] == -LLINF) cout << -1 << endl;
    else cout << max(0LL, -dist[n - 1]) << endl;
    getchar(); getchar();
}