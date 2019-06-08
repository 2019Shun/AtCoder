#include <bits/stdc++.h>
#define REP(i, n) for(int i=0;i<int(n);++i)
#define Yes(n) cout<<((n)?"Yes":"No")<<endl
using namespace std;
template<class A>void pr(A a){cout << (a) << endl;}
int main(void)
{
    int ans=0;
    for (int i = 0; i < 3; i++) {
        char c;cin>>c;
        if(c=='1')ans++;
    }   
    cout << ans << endl;
}