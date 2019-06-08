#include <bits/stdc++.h>
#include <vector>
#include <numeric>
#define PI 3.14159265358979323846
#define MAXINF 1e18L
#define INF 1e9L
#define EPS 1e-9
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

class Vec2{
public:
    int x;int y;
    Vec2(int x=0, int y=0) : x(x), y(y){};
    Vec2 operator+(Vec2 v){
        return Vec2(x+v.x, y+v.y);
    }
    Vec2 operator-(Vec2 v){
        return Vec2(x-v.x, y-v.y);
    }
};

int main(void)
{
    int n;
    cin >> n;
    vector<pii> a(n, make_pair(0,0));
    vector<int> c(n);

    REP(i, n){
        a[i].fi = 0;
        a[i].se = i;
    }

    vector<int> ai(n), bi(n);

    REP(i, n-1){
        cin >> ai[i] >> bi[i];
        a[--ai[i]].fi++;
        a[--bi[i]].fi++;
    }

    REP(i, n){
        cin >> c[i];
    }

    vector<int> b(n);
    SORT(c);
    SORT(a);
    REP(i, n){
        b[a[i].se] = c[i];
    }
    
    int ans = 0;
    REP(i, n-1){
        ans += min(b[ai[i]], b[bi[i]]);
    }

    pr(ans);
    REP(i, n){
        cout << b[i] << ' ';
    }
    cout << endl;
}