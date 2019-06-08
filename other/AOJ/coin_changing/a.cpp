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
using namespace std;
template<class A>void pr(A a){cout << (a) << endl;}
template<class A,class B>void pr(A a,B b){cout << a << " "  ;pr(b);}
template<class A,class B,class C>void pr(A a,B b,C c){cout << a << " " ;pr(b,c);}
template<class A,class B,class C,class D>void pr(A a,B b,C c,D d){cout << a << " " ;pr(b,c,d);}
typedef long long ll;
typedef pair<int, int> pii;

//だめやん！！

int main(void)
{
    int n,m;
    cin >> n >> m;
    vector<int> c(m);
    REP(i, m){
        cin >> c[i];
    }
    RSORT(c);

    int ans = INF;
    Rep(i, 1, (1<<m)+1){
        vector<int> d;
        REP(j, m){
            if(i&(1<<j))d.pb(c[j]);
        }

        // DEBUG_VEC(d);

        int tmp_ans = 0;
        int tmp_n = n;
        REP(j, d.size()){
            while(tmp_n >= d[j]) {
                tmp_ans++;
                tmp_n -= d[j];
                if(tmp_ans > ans) break;
            }
            if(tmp_ans > ans) break;
        }
        if(tmp_n) continue;
        ans = min(ans, tmp_ans);
    }
    pr(ans);
}