#include <bits/stdc++.h>
using namespace std;

struct island{
    long long leader;
    long long num;

    island(long long i) : leader(i), num(1){}
};

int main(void){
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    for(int i = 0; i < M; i++){
        cin >> A[i] >> B[i]; 
        A[i]--;
        B[i]--;
    } 

    vector<long long> ans(M);
    ans[M - 1] = (long long)N * (N - 1) / 2;

    vector<island> il;
    for(int i = 0; i < N; i++){
        il.push_back(island(i));
    }

    for(int i = M - 1; i > 0; i--){
        ans[i - 1] = ans[i];
        if(il[A[i]].leader != il[B[i]].leader){
            ans[i - 1] -= il[il[A[i]].leader].num * il[il[B[i]].leader].num;

            il[il[A[i]].leader].num += il[il[B[i]].leader].num;
            long long tmp = il[B[i]].leader;
            for(auto itr = il.begin(); itr != il.end(); ++itr){
                if((*itr).leader == tmp){
                    (*itr).leader = il[A[i]].leader;
                    (*itr).num = 0;
                }
            }
        }
    }

    for(int i = 0; i < M; i++){
        cout << ans[i] << endl;
    }
}