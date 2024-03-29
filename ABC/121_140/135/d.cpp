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
    string S;
    cin >> S;
    int N = S.size();
    reverse(ALL(S));
    vector<vector<ll>> dp(N+1, vector<ll>(13, 0));
    dp[0][0] = 1;
    // if(S[0] == '?') REP(i, 10) dp[0][i] = 1;
    // else dp[0][S[0]-'0'] = 1;

    for (int i = 0; i < N; i++) {
        int c;
        if(S[i] == '?') c = -1;
        else c = S[i] - '0';
        REP(j, 10){
            if(c != -1 && c != j) continue;
            REP(k, 13){
                (dp[i+1][(j*10+k)%13] += dp[i][k]) %= MOD;
            }
        }         
    }
    pr(dp[N][5]);

    // RREP(i, N){
    //     int c;
    //     if(S[i] == '?') c = -1;
    //     else c = S[i] - '0';
    //     REP(j, 10){
    //         if(c != -1 && c != j) continue;
    //         REP(k, 13){
    //             (dp[i][(j * mul + k) % 13] += dp[i+1][k]) %= MOD;
    //         }
    //     }
    //     mul *= 10;
    //     mul %= 13;
    // }
}