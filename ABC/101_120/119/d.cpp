#include <bits/stdc++.h>
#include <vector>

#define PI 3.14159265358979323846

using namespace std;

typedef long long ll;
typedef pair<int, int> intint;

ll my_abs(ll x){
    return x > 0 ? x : -x;
}

///解けるけどLTEになってしまう．二分探索を使う方をd2.cppに

int main(void)
{
    int a, b, q;
    cin >> a >> b >> q;
    vector<ll> s(a);
    for (int i = 0; i < a; i++) {
        cin >> s[i];
    }
    vector<ll> t(b);
    for (int i = 0; i < b; i++) {
        cin >> t[i];
    }

    vector<ll> x(q);
    for (int i = 0; i < q; i++) {
        cin >> x[i];
    }

    vector<ll> ans(q);
    for (int i = 0; i < q; i++) {
        ans[i] = 100000000000000;
        for (int j = 0; j < a; j++) {
            for (int k = 0; k < b; k++) {
                ll dist;
                if(abs(s[j] - x[i]) < abs(t[k] - x[i])){
                    dist = my_abs(s[j] - x[i]) + my_abs(s[j] - t[k]);
                }else{
                    dist = my_abs(t[k] - x[i]) + my_abs(s[j] - t[k]);
                }
                if(dist < ans[i]){
                    ans[i] = dist;
                }
            }
        }
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }
}