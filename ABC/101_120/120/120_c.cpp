#include <bits/stdc++.h>
using namespace std;

int main(void){
    string s;
    cin >> s;

    int a = 0, b = 0;
    for(int i = 0; i < (int)s.size(); ++i){
        char ch = s[i];
        if(ch == '0'){
            a++;
        }else{
            b++;
        }
    }
    cout << min(a, b) * 2;
}
// void print_v(vector<int> v){
//     for(int i = 0; i < (int)v.size(); ++i){
//         cout << v[i] << " ";
//     }
//     cout << endl;
// }

// int main(void){
//     string s;
//     cin >> s;

//     vector<int> v((int)s.size());
//     for(int i = 0; i < (int)s.size(); ++i){
//         char ch = s[i];
//         v[i] = atoi(&ch);
//     }

//     int count = 0;
//     int update;
//     do{
//         update = 0;
//         int prev_id = 0;
//         bool init_flag = false;
//         for(int i = 0; i < (int)s.size(); ++i){
//             if(v[i] == 100){
//                 continue;
//             }
//             if(init_flag == false){
//                 prev_id = i;
//                 init_flag = true;
//             }else{
//                 if(v[prev_id] != v[i]){
//                     v[i] = v[prev_id] = 100;
//                     count += 2;
//                     update = 1;
//                     break;
//                 }else{
//                     prev_id = i;
//                 }
//             }
//         }
//         // print_v(v);
//     }while(update == 1);

//     cout << count;
// }

// // int main(void){
// //     string s;
// //     cin >> s;

// //     vector<int> v((int)s.size());
// //     for(int i = 0; i < (int)s.size(); ++i){
// //         char ch = s[i];
// //         v[i] = atoi(&ch);
// //     }

// //     int count = 0;
// //     int update;
// //     int prev = -1;
// //     do{
// //         update = 0;
// //         for(auto itr = v.begin(); itr != v.end(); ++itr) {
// //             if(prev == -1){
// //                 prev = *itr;
// //                 update = 1;
// //             }else{
// //                 if(prev != *itr){
// //                     std::vector<int>::iterator _itr = itr;
// //                     _itr -= 1;
// //                     v.erase(_itr, itr);
// //                     count += 2;
// //                     update = 1;
// //                     break;
// //                 }
// //             }
// //             cout << *itr << endl;
// //         }
// //         prev = -1;
// //     }while(update == 1);

// //     cout << count;
// // }