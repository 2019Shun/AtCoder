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
    int N;
    cin >> N;
    string S;
    cin >> S;
    int ans = 0;

    vector<set<string>> sv_set(N, set<string>());

    for (int l = 0; l < N; l++) {
        for (int r = 1; r <= N-l; r++) {
            string s = S.substr(l, r);
            if(sv_set[r-1].find(s) != sv_set[r-1].end()){
                ans = max(ans, r+1);
            }
            sv_set[r-1].insert(s);
        }
    }
    pr(ans);

    // REP(k, N-1){
    //     S = S.substr(1,S.size()-1);
    //     REP(i, (S.size())/2){
    //         string s = S.substr(0, i+1);
    //         for (int j = i+1; j + i < S.size(); j++) {
    //             string s2 = S.substr(j,i+1);
    //             // pr(s, s2, i, j);
    //             if(s2 == s){
    //                 ans = max(ans, i+1);
    //                 break;
    //             }
    //         }
    //     }        
    // }
    // pr(ans);
}