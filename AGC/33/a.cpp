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

int h,w;
int a[1000][1000];
vector<pii> b;

bool check(){
    REP(i, h){
        REP(j, w){
            if(a[i][j] == 0) return false;
        }
    }
    return true;
}

void tb(int i, int j){ //turn black
    if(i>0 && j>0 && i<h && j<w){
        a[i-1][j] = a[i+1][j] = a[i][j-1] = a[i][j+1] = 1;
        b.pb(make_pair(i-1,j));
        b.pb(make_pair(i+1,j));
        b.pb(make_pair(i,j-1));
        b.pb(make_pair(i,j+1));
    }else if(j>0 && i<h && j<w){
        a[i+1][j] = a[i][j-1] = a[i][j+1] = 1;
        b.pb(make_pair(i+1,j));
        b.pb(make_pair(i,j-1));
        b.pb(make_pair(i,j+1));
    }else if(i>0 && i<h && j<w){
        a[i-1][j] = a[i+1][j] = a[i][j+1] = 1;
        b.pb(make_pair(i-1,j));
        b.pb(make_pair(i+1,j));
        b.pb(make_pair(i,j+1));
    }
}

int main(void)
{
    cin >> h >> w;
    REP(i, h){
        REP(j, w){
            char s;
            cin >> s;
            if(s == 46){
                a[i][j] = 0;
            }else{
                a[i][j] = 1;
                b.pb(make_pair(i, j));
            }
        }
    }
    
    int ans = 0;
    while(!check()){
        ans++;
        int bs = b.size();
        REP(i, bs){
            tb(b[i].first, b[i].second);
        }
        b.erase(b.begin(), b.begin()+bs);
    }
    pr(ans);
}