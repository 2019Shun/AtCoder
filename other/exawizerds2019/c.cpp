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
#define SORT(v) sort(ALL(v))
#define RSORT(v) sort(ALL(v), greater<int>())S
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
typedef pair<char, int> pci;

int main(void)
{
    int n,q;
    cin >> n >> q;
    vector<pci> s(n);
    REP(i, n){
        char si;
        cin >> si;
        s[i] = make_pair(si, i+1);
    }

    vector<char> ti(n), di(n);
    REP(i, q){
        cin >> ti[i] >> di[i];
    }

    REP(i, q){
        DEBUG(i);
        REP(j, n){
            if(s[j].first == ti[i] && s[j].second > 0){
                int v = s[j].second;
                DEBUG(v);
                REP(k, n){
                    if(s[k].second == v){
                        if(di[i] == 'L') s[k].second--;
                        else s[k].second++;
                    }
                    if(s[k].second == 0 || s[k].second == n+1) s[k].second = -1;
                }

            }
        }
        REP(j, n) DEBUG(s[j].second);
    }

    int ans = 0;
    REP(i, n){
        if(s[i].second > 0 && s[i].second < n+1) ans++;
    }

    pr(ans);
}