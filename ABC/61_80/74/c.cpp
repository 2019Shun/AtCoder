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

int A,B,C,D,E,F;
void dfs(int a, int b, int A, int B, vector<int> &w){
    if(a+b+A <= F){
        w.pb(a+b+A);
        dfs(a+A, b, A, B, w);
    }
    
    if(a+b+B <= F){
        w.pb(a+b+B);
        dfs(a, b+B, A, B, w);
    }
}

void aaa(int a, int b, vector<int> &w){
    Rep(i, 1, F+1){
        if(i % a == 0 || i % b == 0){
            w.pb(i);
        }
    }
}

double calc(int w, int s){
    return 100 * s / double(w + s);
}

int main(void)
{
    cin >> A >> B >> C >> D >> E >> F;
    vector<int> w;
    vector<int> s;

    A *= 100;
    B *= 100;

    // dfs(0,0,A,B,w);
    // dfs(0,0,C,D,s);
    aaa(A, B, w);
    aaa(C, D, s);

    SORT(w);
    SORT(s);

    w.erase(unique(ALL(w)), w.end());
    s.erase(unique(ALL(s)), s.end());

    int wa = 0;
    int sa = 0;
    double va = 0;
    double e = calc(100, E);
    for(auto&& wi : w){
        for(auto&& si : s){
            if(wi+si>F)continue;
            double v = calc(wi, si);
            if(v>e) continue;
            if(chmax(va, v)){
                wa = wi;
                sa = si;
            }
        }
    }
    pr(wa+sa, sa);
}