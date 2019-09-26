#include <bits/stdc++.h>
#include <vector>
#include <numeric>
#define PI 3.14159265358979323846
#define MAXINF (1e18L)
#define INF (1e9L)
#define EPS (1e-9)
#define MOD ((ll)(1e9+7))
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
template<class T> inline bool chmin(T& a, T b){return a>b ? a=b, true : false;}
template<class T> inline bool chmax(T& a, T b){return a<b ? a=b, true : false;}
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;

int main(void)
{
    vector<int> aans;
    while(1){
        int n,m;
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        vector<vector<int>> c(5, vector<int>());
        REP(i, 3){
            int a;
            cin >> a;
            REP(j, a){
                int b;
                cin >> b;
                c[i].pb(b);
            }
        }

        queue<vector<vector<int>>> q;
        c[3].pb(0);
        c[4].pb(-1);c[4].pb(-2);c[4].pb(-3);
        q.push(c);
        int ans = -1;
        while(!q.empty()){
            vector<vector<int>> f = q.front();q.pop();

            if(f[3][0] >= m){
                ans = -1;
                break;
            }
            if(f[0].size() == n || f[2].size() == n) {
                ans = f[3][0];
                break;
            }

            REP(from, 3){
                REP(to, 3){
                    if(abs(from - to) != 1) continue;
                    vector<vector<int>> t = f;
                    if(t[from].empty()) continue;
                    if(t[4][from] == from) continue;
                    else{
                        if(t[to].empty() || (t[from].back() > t[to].back())){
                            t[to].pb(t[from].back());
                            t[from].pop_back();
                            t[3][0]++;
                            t[4][to] = from;
                            t[4][from] = to;
                            q.push(t);
                        }
                    }
                }
            }
        }
        aans.pb(ans);
    }
    for(auto&& a : aans) pr(a);
}