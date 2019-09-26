#include <bits/stdc++.h>
#include <vector>
#include <numeric>
#define PI 3.14159265358979323846
#define MAXINF (1e18L)
#define INF (1e9L)
#define EPS (1e-9)
#define MOD (1e9+7)
#define REP(i, n) for(int i=0;i<int(n);++i)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
#define ALL(v) v.begin(),v.end()
#define FIND(v,x) (binary_search(ALL(v),(x)))
#define SORT(v) sort(ALL(v))
#define RSORT(v) sort(ALL(v));reverse(ALL(v))
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl
#define Yes(n) cout<<((n)?"Yes":"No")<<endl
#define YES(n) cout<<((n)?"YES":"NO")<<endl
#define pb push_back
#define fi first
#define se second
using namespace std;
template<class A>void pr(A a){cout << (a) << endl;}
template<class A,class B>void pr(A a,B b){cout << a << " "  ;pr(b);}
template<class A,class B,class C>void pr(A a,B b,C c){cout << a << " " ;pr(b,c);}
template<class A,class B,class C,class D>void pr(A a,B b,C c,D d){cout << a << " " ;pr(b,c,d);}
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;

// template <typename T, typename U>
// vector<pair<T, U>> dijkstra(const vector<vector<pair<T, U>>> &E, const U s, const T inf)
// {
//     using P = pair<T, U>;
//     vector<P> d;
//     fr(i, E.size()) { d << P{inf, i}; }
//     PQ<P, vector<P>, greater<P>> pq;
//     pq << (d[s] = P{0, s});
//     while (pq.size())
//     {
//         P a = pq.top();
//         pq.pop();
//         U v = a.second;
//         if (d[v].first >= a.first)
//         {
//             for (P e : E[v])
//             {
//                 if (d[v].first + e.first < d[e.second].first)
//                 {
//                     d[e.second] = P{d[v].first + e.first, v};
//                     pq << P{d[v].first + e.first, e.second};
//                 }
//             }
//         }
//     }
//     return d;
// }
// template <typename T, typename U>
// map<U, pair<T, U>> dijkstra(map<U, vector<pair<T, U>>> E, const U s, const T inf)
// {
//     using P = pair<T, U>;
//     map<U, P> d;
//     for (pair<U, vector<P>> e : E)
//     {
//         d[e.first] = P{inf, e.first};
//     }
//     PQ<P, vector<P>, greater<P>> pq;
//     pq << (d[s] = P{0, s});
//     while (pq.size())
//     {
//         P a = pq.top();
//         pq.pop();
//         U v = a.second;
//         if (d[v].first >= a.first)
//         {
//             for (P e : E[v])
//             {
//                 if (d[v].first + e.first < d[e.second].first)
//                 {
//                     d[e.second] = P{d[v].first + e.first, v};
//                     pq << P{d[v].first + e.first, e.second};
//                 }
//             }
//         }
//     }
//     return d;
// }

//cost_map[vertex] pll -> <to, cost>
vector<ll> dijkstra(ll s, vector<vector<pll>>& cost_map){
    vector<ll> d(cost_map.size(), MAXINF);
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push(pll(0, s));
    d[s] = 0;
    while(!q.empty()){
        pll f = q.top();q.pop();
        if(d[f.se] < f.fi) continue;
        for(auto&& v : cost_map[f.se]){
            ll value = f.fi + v.se;
            if(value < d[v.fi]) q.push(pll(d[v.fi] = f.fi + v.se, v.fi));
        }
    }
    return d;
}

vector<vector<pll>> Map;
vector<vector<int>> m;

void dfs(int p, int c, int d){
    if(d == 3){
        if(p != c){
            // if(!FIND(Map[p], pll(c, 1)))
                Map[p].pb(pll(c, 1));
        }
        return;
    }

    for(auto&& ch : m[c]){
        if(d==2 && FIND(Map[p], pll(ch, 1)))continue;
        dfs(p, ch, d+1);
    }

}

int main(void)
{
    int N,M;
    cin >> N >> M;
    Map = vector<vector<pll>>(N);
    m = vector<vector<int>>(N);

    REP(i, M){
        int u,v;
        cin >> u >> v;
        u--;v--;
        m[u].pb(v);
    }
    int S,T;
    cin >> S >> T;
    S--;T--;

    REP(i, N){
        dfs(i, i, 0);
    }

    // auto di = dijkstra(S, Map);
    // if(di[T] == MAXINF || di[T] == 0) pr(-1);
    // else pr(di[T]);
    // int i = 0;
    // for(auto&& tmp : Map){
    //     i++;
    //     for(auto&& tmp2 :tmp)
    //         pr(i, tmp2.fi+1);
    // }
    // DEBUG_VEC(di);
}