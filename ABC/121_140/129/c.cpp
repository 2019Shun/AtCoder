#include <bits/stdc++.h>
#include <vector>
#include <numeric>
#define PI 3.14159265358979323846
#define MAXINF 1e18L
#define INF 1e9L
#define EPS 1e-9
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

map<ll,ll> fm;

ll fi(ll n){
    if(n <= 2) return n;

    if(fm.count(n)) return fm[n];

    ll f;
    if(fm.count(n-2)){
        f = fm[n-2];
    }else{
        f = fi(n-2);
    }

    ll s;
    if(fm.count(n-1)){
        s = fm[n-1];
    }else{
        s = fi(n-1);
    }

    fm[n] = (f+s) % 1'000'000'007;
    return fm[n];
}

int main(void)
{
    int n,m;
    cin >> n >> m;
    vector<int> a;
    int prev = 0;
    for (int i = 0; i < m; i++) {
        int ai;
        cin >> ai;
        a.pb(ai-prev-1);
        prev = ai;
    }
    a.pb(n-prev-1);

    if(a.front()==0) a.erase(a.begin());
    if(a.back()<=0) a.erase(a.end()-1);

    // DEBUG_VEC(a);
    
    ll ans = fi(a[0]);
    Rep(i,1,a.size()){
        DEBUG(fi(a[i]));
        ans *= fi(a[i]);
        ans %= 1'000'000'007;
    }
    pr(ans);

}