#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);

using namespace std;
const int mod = 1e6;
int table[110][110];

// int add(int n, int k){
//     if(table[n][k]) return table[n][k];
//     if(k == 1)  return 1;
//
//     int sum = 0;
//     for(int i = 0; i <= n; ++i){
//         sum += add(n-i, k-1);
//         sum %= mod;
//     }
//     table[n][k] = sum;
//     return sum;
// }
//
// int main(){ _
//     int n, k;
//     memset(table, 0, sizeof table);
//     while(cin >> n >> k){
//         if(k == 0 && n == 0)  break;
//         cout << add(n, k) << endl;
//     }
//     return 0;
// }

int main(){ _
    int n, k;
    memset(table, 0, sizeof table);

    // base case
    for(int n = 0; n <= 100; ++n)   table[1][n] = 1;
    for(int k = 1; k <= 100; ++k)   table[k][0] = 1;

    for(int k = 1; k <= 100; ++k){
        for(int n = 1; n <= 100; ++n){
            for(int split = 0; split <= n; ++split){
                table[k][n] = (table[k][n] + table[k-1][n-split]) % mod;
            }
        }
    }

    while(cin >> n >> k){
        if(n == 0 && k == 0)    break;
        cout << table[k][n] << endl;
    }
    return 0;
}
