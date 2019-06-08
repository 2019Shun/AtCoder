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

int main(void)
{
    int n;
    cin >> n;
    vector<int> x(n), y(n), h(n);
    REP(i, n){
        cin >> x[i] >> y[i] >> h[i];
    }
    
    ll cx, cy, ch = 0;
    REP(j, 101){
        REP(k, 101){
            ll H;
            H = h[0] + abs(x[0]-j) + abs(y[0]-k);
            H = max(H, 0ll);
            int flag = 1;
            Rep(i, 1, n){
                // ll H_ = h[i] + abs(x[i]-j) + abs(y[i]-k);
                // H_ = max(H_, 0ll);
                // if(H != H_){
                //     flag = 0;
                //     break;
                // }
                ll H_ = H - abs()
                H_ = max(H_, 0ll);
            }
            if(flag == 1 && H > ch) {
                    cx = j;
                    cy = k;
                    ch = H;
            }
        }
    }
    pr(cx,cy,ch);
}