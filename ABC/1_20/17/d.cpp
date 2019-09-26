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

template<typename T>
istream& operator>>(istream& is, vector<T>& vec) {
    for(auto&& x:vec) is >> x;
    return is;
}

int main(void)
{
    int n,m;
    cin >> n >> m;
    vector<int> f(n);
    cin >> f;
    // REP(i, n){
    //     cin >> f[i];
    // }
    vector<ll> dp(n,0);
    dp[0] = 1;
    int lb = 0,ub =1;
    Rep(i,1,n){
        ub = i;
        int next_lb = lb;
        bool flag = false;
        for (int j = lb; j < ub; j++) {
            if(f[j] == f[i]) {
                next_lb = j;
                flag = true;
            }
        }
        if(flag){
            lb = next_lb + 1;
            if(lb == i) dp[i] = dp[i-1];
            else dp[i] = (dp[i-1] * 2 - 1) % MOD;
        }else{
            dp[i] = (dp[i-1] * 2) % MOD;
        }
    }
    pr(dp[n-1]);
}