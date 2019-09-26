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
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;

int lake[50][50];
int w,h;

bool dfs(int x, int y){
    if(lake[x][y]==0) return false;

    int dx[8]={-1,1,0,0,1,1,-1,-1};
    int dy[8]={0,0,-1,1,1,-1,1,-1};
    
    lake[x][y] = 0;

    REP(i, 8){
        int nx = x + dx[i]; 
        int ny = y + dy[i];
        if(0 <= nx && nx < h && 0 <= ny && ny < w && lake[nx][ny] == 1){
            dfs(nx,ny);
        } 
    }
    return true;
}

int main(void)
{
    vector<int> ans;

    while(1){
        cin >> w >> h;
        if(w == 0 && h == 0) break;
        REP(i, h){
            REP(j, w){
                cin >> lake[i][j];
            }
        }

        int a = 0;
        REP(i, h){
            REP(j, w){
                a += dfs(i,j);
            }
        }
        ans.pb(a);
    }

    REP(i, ans.size()){
        pr(ans[i]);
    }
}