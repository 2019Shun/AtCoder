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

ll dijkstra(ll s, vector<vector<pll>> cost_map){
    ll n = cost_map.size();
    vector<ll> d(n, MAXINF);
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push(pll(s, 0));
    d[s] = 0;
    while(!q.empty()){
        pll f = q.top();q.pop();
        if(d[f.fi] < f.se) continue;
        for(auto v : cost_map[f.fi]){
            ll value = f.se + v.se;
            if(value < d[v.fi]) {
                d[f.fi] = f.se;
                q.push(pll(v.fi, value));
            }
        }
    }
}

int main(void)
{
    ll n,m;
    cin >> n >> m;
    ll s,t;
    cin >> s >> t;
    s--;t--;

    vector<vector<pair<ll, pll>>> d(n);
    REP(i, m){
        ll u,v;
        cin >> u >> v;
        ll a,b;
        cin >> a >> b;
        u--;v--;
        d[u].pb(make_pair(v, make_pair(a,b)));
        d[v].pb(make_pair(u, make_pair(a,b)));
    }

    vector<ll> yen(n, MAXINF);
    vector<ll> snk(n, MAXINF);

    priority_queue<pll, vector<pll>, greater<pll>> p;
    p.push(pll(s, 0));
    while(p.size()){
        pll f = p.top();p.pop();
        if(yen[f.fi] > f.se) yen[f.fi] = f.se;
        else continue;
        for(auto v : d[f.fi]){
            ll value = f.se + v.se.fi;
            if(value < yen[v.fi]) p.push(pll(v.fi, value));
        }
    }
    p = priority_queue<pll, vector<pll>, greater<pll>>();
    p.push(pll(t, 0));
    while(p.size()){
        pll f = p.top();p.pop();
        if(snk[f.fi] > f.se) snk[f.fi] = f.se;
        else continue;
        for(auto v : d[f.fi]){
            ll value = f.se + v.se.se;
            if(value < snk[v.fi]) p.push(pll(v.fi, value));
        }
    }
    vector<ll> ans(n+1,MAXINF);
    RREP(i, n){
        ans[i]=min(ans[i+1], yen[i] + snk[i]);
    }
    // REP(i, n){
    //     ans[i] = yen[i] + snk[i];
    // }
    // SORT(ans);
    REP(i, n){
        pr(1'000'000'000'000'000 - ans[i]);
    }
}