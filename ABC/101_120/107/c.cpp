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
#define pb push_back
using namespace std;
template<class A>void pr(A a){cout << (a) << endl;}
template<class A,class B>void pr(A a,B b){cout << a << " "  ;pr(b);}
template<class A,class B,class C>void pr(A a,B b,C c){cout << a << " " ;pr(b,c);}
template<class A,class B,class C,class D>void pr(A a,B b,C c,D d){cout << a << " " ;pr(b,c,d);}
typedef long long ll;
typedef pair<int, int> pii;

///違う

int main(void)
{
    ll n,k;
    cin >> n >> k;
    vector<ll> mx, px;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if(tmp >= 0) px.pb(tmp);
        else mx.pb(abs(tmp));
    }
    px.pb(MAXINF);
    mx.pb(MAXINF);
    SORT(px);SORT(mx);

    int mid = -1, pid = -1;
    for (ll i = 0; i < k; i++) {
        if(px[pid!=-1?pid:0] >= mx[mid!=-1?mid:0]) mid = mid!=-1?mid+1:1;
        else pid = pid!=-1?pid+1:1;
    }

    ll m = (mid != -1 ? mx[mid-1] : 0);
    ll p = (pid != -1 ? px[pid-1] : 0);
    ll ans1 = m > p ? m+p*2 : p+m*2, ans2 = MAXINF, ans3 = MAXINF;
    if(mx.size() >= k) ans2 = mx[k-1];
    if(px.size() >= k) ans3 = px[k-1];
    pr(min(ans1, min(ans2, ans3)));
}