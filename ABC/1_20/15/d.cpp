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

///上手くいかない．多分Kに関して無視している部分がある

int main(void)
{
    int w,n,k;
    cin >> w >> n >> k;
    vector<pii> ab(n);// fi...幅，se...重要度
    REP(i, n){
        cin >> ab[i].fi >> ab[i].se;
    }

    SORT(ab);

    vector<pii> dp(w+1, make_pair(0,0)); // fi...重要度，se...回数
    REP(i, n){
        RREP(j, w+1){
            if(j == 0 || (dp[j].fi && j+ab[i].fi <= w)){
                if(dp[j+ab[i].fi].fi < (dp[j].fi + ab[i].se) && dp[j].se < k){
                    dp[j+ab[i].fi].fi = dp[j].fi + ab[i].se;
                    dp[j+ab[i].fi].se = dp[j].se + 1;
                }
            }
        }
    }

    int ans = 0;
    REP(i, w+1){
        ans = max(ans, dp[i].fi);
    }
    pr(ans);
}