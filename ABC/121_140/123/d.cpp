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
#define RSORT(v) sort(ALL(v), greater<int>())
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

void dfs(ll t, int d, vector<ll> &A, vector<ll> &B, vector<ll> &C, vector<ll> &v){
    if(d == 0){
        REP(i, A.size()){
            dfs(t+A[i],1,A,B,C,v);
        }
    }else if(d == 1){
        REP(i, B.size()){
            dfs(t+B[i],2,A,B,C,v);
        }
    }else if(d == 2){
        REP(i, C.size()){
            v.pb(t+C[i]);
        }
        return;
    }
}

int main(void)
{
    vector<ll> v;
    int x,y,z;
    cin >> x >> y >> z;
    int k;
    cin >> k;

    vector<ll> A(x);
    for (int i = 0; i < x; i++) {
        cin >> A[i];
    }   
    vector<ll> B(y);
    for (int i = 0; i < y; i++) {
        cin >> B[i];
    }   
    vector<ll> C(z);
    for (int i = 0; i < z; i++) {
        cin >> C[i];
    }

    dfs(0,0,A,B,C,v);
    
    SORT(v);
    REP(i, k){
        pr(v[v.size()-i-1]);
    }
}