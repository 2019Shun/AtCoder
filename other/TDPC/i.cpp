// #include <bits/stdc++.h>
// #include <vector>
// #include <numeric>
// #define PI 3.14159265358979323846
// #define MAXINF (1e18L)
// #define INF (1e9L)
// #define EPS (1e-9)
// #define MOD (1e9+7)
// #define REP(i, n) for(int i=0;i<int(n);++i)
// #define Rep(i,sta,n) for(int i=sta;i<n;i++)
// #define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
// #define ALL(v) v.begin(),v.end()
// #define FIND(v,x) (binary_search(ALL(v),(x)))
// #define SORT(v) sort(ALL(v))
// #define RSORT(v) sort(ALL(v));reverse(ALL(v))
// #define DEBUG(x) cerr<<#x<<": "<<x<<endl;
// #define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl
// #define Yes(n) cout<<((n)?"Yes":"No")<<endl
// #define YES(n) cout<<((n)?"YES":"NO")<<endl
// #define pb push_back
// #define fi first
// #define se second
// using namespace std;
// template<class A>void pr(A a){cout << (a) << endl;}
// template<class A,class B>void pr(A a,B b){cout << a << " "  ;pr(b);}
// template<class A,class B,class C>void pr(A a,B b,C c){cout << a << " " ;pr(b,c);}
// template<class A,class B,class C,class D>void pr(A a,B b,C c,D d){cout << a << " " ;pr(b,c,d);}
// typedef long long ll;
// typedef pair<int, int> pii;

// int main(void)
// {
//     string s;
//     cin >> s;
//     vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1, 0));

//     REP(w, s.size()+1){
//         if(w%3!=0)continue;
//         REP(l, s.size()+1){
//             Rep(r, l+1, s.size()+1){
//                 for(int i = l; i <= r; ++i) {
//                     dp[l][r] = max(dp[l][r], dp[l][i] + dp[i][r]);
//                 }
//                 for(int d = -2; d <= 1; ++d) {
//                     if(l - d < 0 || s.size() < r + 2 - d) {
//                         continue;
//                     }
//                     auto iwi = s.substr(l - d, d) + s.substr(r-1, 3 - d);
//                     if(iwi == "iwi") {
//                         dp[l - d][r + 2 - d] = dp[l][r] + 3;
//                     }
//                 }
//             }

//         }
//     }
//     int ans = 0;
//     REP(l, s.size()+1){
//         REP(r, s.size()+1){
//             ans=max(dp[l][r],ans);
//             // cout << dp[l][r] << " ";
//         }
//         // cout << endl;
//     }
//     pr(ans/3);
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int const n = s.size();
    // [l, r)
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for(int w = 0; w <= n; ++w) {
        for(int l = 0; l + w <= n; ++l) {
            for(int i = l; i <= l + w; ++i) {
                dp[l][l + w] = max(dp[l][l + w], dp[l][i] + dp[i][l + w]);
            }
            if(dp[l][l + w] != w) {
                continue;
            }
            for(int d = 0; d <= 3; ++d) {
                if(l - d < 0 || n < l + w + 3 - d) {
                    continue;
                }
                auto iwi = s.substr(l - d, d) + s.substr(l + w, 3 - d);
                if(iwi == "iwi") {
                    dp[l - d][l + w + 3 - d] = dp[l][l + w] + 3;
                }
            }
        }
    }

    int res = 0;
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= n; ++j) {
            res = max(dp[i][j], res);
        }
    }
    res /= 3;
    cout << res << endl;
}