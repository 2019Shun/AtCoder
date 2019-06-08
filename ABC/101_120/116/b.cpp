#include <bits/stdc++.h>
#include <vector>
#include <numeric>
#define PI 3.14159265358979323846
#define MAXINF 1e18L
#define MININF -1e18L
#define REP(i, n) for(int i=0;i<int(n);++i)
#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
#define ALL(v) v.begin(),v.end()
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> intint;

int f(int n){
    if(n % 2 == 0) return n / 2;
    else return 3 * n + 1;
}

int main(void)
{
    int s;
    cin >> s;
    vector<int> v;  
    v.pb(s);
    REP(i, 1000000){
        int fi = f(v[i]);
        if(find(ALL(v), fi) != v.end()){
            cout << i + 2 << endl;
            return 0;
        }
        // for (int x : v) {
        //     if(x == fi){
        //         cout << i + 2 << endl;
        //         return 0;
        //     }
        // }
        DEBUG_VEC(v);
        v.push_back(fi);
    }
}