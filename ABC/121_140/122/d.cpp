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

ll POW(ll x, ll y){
    if(y<=0)return 1;
    ll ret=x;
    REP(i,y-1){ret*=x;}
    return ret;
}

bool check(string s){
    if(s.size()<3) return false;
    REP(i, s.size()-2){
        if(s[i]=='A' && s[i+1]=='G' && s[i+2]=='C') return true;
        if(s[i]=='A' && s[i+1]=='C' && s[i+2]=='G') return true;
        if(s[i]=='G' && s[i+1]=='A' && s[i+2]=='C') return true;
    }
    return false;
}

void dfs(string s, bool flag, int d, int n, ll &result){
    if(d == n+1) return;
    if(flag) return;

    if(check(s)){
        result+=POW(4,(n-d));
        if(d!=n)result+=1;
        flag = true;
        return;
    }

    dfs(s+'A',flag,d+1,n,result);
    dfs(s+'C',flag,d+1,n,result);
    dfs(s+'G',flag,d+1,n,result);
    dfs(s+'T',flag,d+1,n,result);
}

int main(void)
{
    int n;
    cin >> n;

    ll result = 0;
    string s;
    dfs(s, false, 0, n, result); 
    pr((POW(4ll,(ll)n) - result) % 1000000007);
}