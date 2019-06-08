#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>
#include <algorithm>
#include <set>
#include <string>
#include <queue>
 
using namespace std;
#define rep(i, n) for(int (i) = 0; (i) < (n); (i) ++)
#define MAXINF 1e18L
#define MININF -1e18L
 
typedef long long ll;
 
vector<pair<ll, ll>> pf;
 
int sign(ll x){
    if(x < 0){
        return -1;
    }
    if(x > 0){
        return 1;
    }
    return 0;
}
 
int main(){
    int A, B, Q;
    cin >> A >> B >> Q;
    vector<ll> ss;
    vector<ll> ts;
    vector<ll> xs;
    rep(i, A){
        ll tmp;
        cin >> tmp;
        ss.push_back(tmp);
    }
    rep(i, B){
        ll tmp;
        cin >> tmp;
        ts.push_back(tmp);
    }
    rep(i, Q){
        ll tmp;
        cin >> tmp;
        xs.push_back(tmp);
    }
 
    ss.push_back(MAXINF);
    ss.push_back(MININF);
    ts.push_back(MAXINF);
    ts.push_back(MININF);
 
    sort(ss.begin(), ss.end());
    sort(ts.begin(), ts.end());
 
 
    rep(i, Q){
        ll x = xs[i];
        auto r1 = lower_bound(ss.begin(), ss.end(), x);
        auto r2 = lower_bound(ts.begin(), ts.end(), x);
        vector<ll> slr;
        slr.push_back(*r1);
        slr.push_back(*(r1 - 1));
 
        vector<ll> tlr;
        tlr.push_back(*r2);
        tlr.push_back(*(r2 - 1));
 
        ll ans = MAXINF;
 
        for(ll s : slr){
            for(ll t : tlr){
                ll delta_s = s - x;
                ll delta_t = t - x;
                if(sign(delta_s) * sign(delta_t) <= 0){
                    ans = min(ans, 2 * abs(delta_s - delta_t) - max(abs(delta_s), abs(delta_t)));
                }else{
                    ans = min(ans, max(abs(delta_s), abs(delta_t)));
                }
            }
        }
        cout << ans << endl;
    }
 
    return 0;
}