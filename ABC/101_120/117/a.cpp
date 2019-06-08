#include <bits/stdc++.h>
#include <vector>
#define PI 3.14159265358979323846
#define MAXINF 1e18L
#define MININF -1e18L
#define REP(w, n) for(int w=0;w<int(n);++w)
#define RREP(w, n) for(int w=int(n)-1;w>=0;--w)
using namespace std;
typedef long long ll;
typedef pair<int, int> intint;

int main(void)
{
    int t,x;
    cin >> t >> x;
    double ans = (double)t / x;
    printf("%.10f\n", ans);
}