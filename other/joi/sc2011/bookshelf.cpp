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

template <typename T>
struct ST{
    using F = function<T(T,T)>;
    F f;
    vector<T> dat;
    int n;
    T ti;
    ST(F f, int n_, T init = INF) : f(f), ti(init) {
        n = 1;
        while(n < n_) n <<= 1;
        dat.assign(n << 1, init);
    }
    ST(int n_, T init = INF){ //RMQ
        ST([](ll a, ll b){return (ll)min(a, b);}, n_, init);   
    }
    void update(int k, int a){
        k += n -1;
        dat[k] = a;
        while(k > 0){
            k = (k - 1) / 2;
            dat[k] = f(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }
    // [a, b)
    T query(int a, int b, int k, int l, int r){
        if(r <= a || b <= l) return ti;
        if(a <= l && r <= b) return dat[k];
        else{
            T vl = query(a,b,k * 2 + 1, l, (l + r) / 2);
            T vr = query(a,b,k * 2 + 2, (l + r) / 2, r);
            return f(vl, vr);
        }
    }
};

int main(void)
{
    int n;
    cin >> n;
    vector<int> w(n);
    REP(i, n){
        cin >> w[i];
    }
    auto f = [](ll a, ll b){return (ll)min(a, b);};
    ST<ll> st(f, n);
    REP(i, n){
        int oi;
        cin >> oi;
        st.update(i, oi);
    }
}