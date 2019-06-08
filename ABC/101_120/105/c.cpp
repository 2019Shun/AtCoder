#include <bits/stdc++.h>
#include <vector>
#include <numeric>
#include <tuple>
#include <string>
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
typedef pair<string, ll> psl;
typedef tuple<int, string, ll> tisl;

int n;

int main(void)
{
    cin >> n;

    queue<tisl> q;
    q.push(make_tuple(0, "1", 1));
    q.push(make_tuple(0, "0", 0));

    while(q.size()){
        tisl t = q.front(); q.pop();
        
        int& cur = get<0>(t);
        string& s = get<1>(t);
        ll& v = get<2>(t); 
        
        if(v == n){
            reverse(ALL(s));
            pr(s);
            return 0;
        }
        
        q.push(make_tuple(cur+1, s + "1", v + ((cur%2?1:-1) * pow(2,cur+1))));
        q.push(make_tuple(cur+1, s + "0", v));
    }
}