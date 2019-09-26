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

int dp[101][10001];

int main(void)
{
    int N, W;
    cin >> N >> W;
    
    vector<int> v(N), w(N);
    REP(i, N){
        cin >> v[i] >> w[i];
    }

    // vector<vector<int>> dp(N+1, vector<int>(W+1, -1)); //AOJだとなんか怒られる
    REP(i, N+1)REP(j, W+1)dp[i][j] = -1;

    dp[0][0] = 0;
    REP(i, N){
        REP(j, W+1){
            if(dp[i][j]<0)continue;
            
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if(j+w[i] <= W)
                dp[i+1][j+w[i]] = max(dp[i+1][j+w[i]], dp[i][j] + v[i]);
        }
    }

    int ans = 0;
    REP(i, N+1){
        REP(j, W+1){
            ans = max(ans, dp[i][j]);
        }
    }
    pr(ans);
}