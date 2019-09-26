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

const int MAX_DIGIT = 60;

int main(void)
{
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }   
    vector<vector<ll>> dp(MAX_DIGIT+1, vector<ll>(2, 0));
    bool flag = false;
    REP(d, MAX_DIGIT){
        ll mask = 1LL << (MAX_DIGIT-d-1);
    
        int num = 0;
        REP(i, N) if(A[i]&mask) num++;
        ll cost0 = mask * num;
        ll cost1 = mask * (N-num);

        if(dp[d][0])
            chmax(dp[d+1][1], dp[d][1] + max(cost0, cost1));

        if (K & mask) chmax(dp[d+1][0], dp[d][0] + cost1);
        else chmax(dp[d+1][0], dp[d][0] + cost0);

    }
    pr(max(dp[MAX_DIGIT][0], dp[MAX_DIGIT][1]));
}