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
template<class T> inline bool chmin(T& a, T b){return a>b ? a=b, true : false;}
template<class T> inline bool chmax(T& a, T b){return a<b ? a=b, true : false;}
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;

int comp(vector<int> &x1, vector<int> &x2, int n, int h){
    vector<int> xs;
    xs.pb(0);xs.pb(h);
    REP(i, n){
        xs.pb(x1[i]);
        xs.pb(x2[i]);
    }
    SORT(xs);
    xs.erase(unique(ALL(xs)), xs.end());
    REP(i, n){
        x1[i] = lower_bound(ALL(xs), x1[i]) - xs.begin();
        x2[i] = lower_bound(ALL(xs), x2[i]) - xs.begin();
        
    }
    return xs.size()-1;
}

int main(void)
{
    int h,w,n;
    cin >> h >> w >> n;
    vector<int> x1(n), x2(n), y1(n), y2(n);
    REP(i, n){
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    }
    
    h = comp(x1,x2,n,h);
    w = comp(y1,y2,n,w);
    
    vector<vector<int>> m(h, vector<int>(w, 0));
    REP(i, n){
        for(int x = x1[i]; x < x2[i]; x++){
            m[x][y1[i]]++;
            m[x][y2[i]]--;
        }
    }
    REP(i, h){
        Rep(j, 1, w){
            m[i][j] += m[i][j-1];
        }
    }

    int ans = 0;
    REP(i, h){
        REP(j, w){
            if(m[i][j] == 0){
                m[i][j] = 1;
                ans++;
                int dx[4]={-1,1,0,0}, dy[4]={0,0,-1,1};
                queue<pii> q;
                q.push(pii(i,j));
                while(!q.empty()){
                    auto f = q.front();q.pop();
                    REP(k, 4){
                        int x = f.fi + dx[k];
                        int y = f.se + dy[k];
                        if(0 <= x && x < h && 0 <= y && y < w ){
                            if(!m[x][y]) {
                                m[x][y] = 1;
                                q.push(pii(x,y));
                            }
                        }
                    }
                }
            }
        }
    }

    pr(ans);
}