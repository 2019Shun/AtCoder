#include <bits/stdc++.h>
#include <vector>
#include <cmath>
#include <cstdlib>

#define PI 3.14159265358979323846
#define MAXINF 1e18L
#define MININF -1e18L

using namespace std;

typedef long long int ll;
typedef pair<int, int> intint;

int binarysearch(vector<ll> &v, ll x){
    ll ok = 0;
    ll ng = (ll)v.size();
    while(llabs(ok - ng) > 1){
        ll mid = (ok + ng) / 2;
        if(v[mid] <= x) ok = mid;
        else ng = mid;
    }
    return ok;
}

ll calc(vector<ll> &s, vector<ll> &t, ll x){
    vector<ll> a, b;
    ll ans = MAXINF;
    for (int i = 0; i < 2; i++) {
        if(i == 0){
            a = s; 
            b = t;
        }else{
            a = t;
            b = s; 
        }

        for (int j = 0; j < 2; j++) {
            ll apos = binarysearch(a, x) + j;
            ll ax = a[apos];
            for (int k = 0; k < 2; k++) {
                ll bpos = binarysearch(b, ax) + k;
                ll bx = b[bpos];
                ans = min(ans, llabs(ax- x) + llabs(bx - ax));
            }
        }
    }
    return ans;
}

int main(void)
{
    // int a, b, q;
    // cin >> a >> b >> q;
    // vector<ll> s(a);
    // for (int i = 0; i < a; i++) {
    //     cin >> s[i];
    // }
    // s.push_back(MININF);
    // s.push_back(MAXINF);
    // vector<ll> t(b);
    // for (int i = 0; i < b; i++) {
    //     cin >> t[i];
    // }
    // t.push_back(MININF);
    // t.push_back(MAXINF); 

    // sort(s.begin(), s.end());
    // sort(t.begin(), t.end());

    // vector<ll> x(q);
    // for (int i = 0; i < q; i++) {
    //     cin >> x[i];
    // }

    // for (int i = 0; i < q; i++) {
    //     cout << calc(s, t, x[i]) << endl;
    // }
    int a = 100000, b = 100000, q = 100000;
    vector<ll> s(a);
    for (int i = 0; i < a; i++) {
        s[i] = 1;
    }
    s.push_back(MININF);
    s.push_back(MAXINF);
    vector<ll> t(b);
    for (int i = 0; i < b; i++) {
        t[i] = i;
    }
    t.push_back(MININF);
    t.push_back(MAXINF); 

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    vector<ll> x(q);
    for (int i = 0; i < q; i++) {
        x[i] = i;
    }

    for (int i = 0; i < q; i++) {
        cout << calc(s, t, x[i]) << endl;
    }
}