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
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    int mv = INF;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mv = min(mv, a[i]);
    }
    vector<int> v;
    int tmp = 0;
    REP(i, n){
        if(a[i] == mv){
            v.pb(tmp);
            tmp = 0;
        }else{
            tmp++;
        }
    }
    v.pb(tmp);

    int ans = 0;
    int carry = 0;
    REP(i, v.size()){
        if(v[i] == 0) continue;
        if((v[i] - carry)>=0) ans += (v[i] - carry) / (k-1) + ((v[i] - carry) % (k-1)?1:0);
        carry = k - v[i] % (k-1);
    }
    pr(ans);
}