#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

int table[55][55];

// recursive solution
// int solve(int i, int j, vector<int> &v){
//     if(i+1 == j)    return 0;
//     if(table[i][j]) return table[i][j];
//
//     int ans = INT_MAX;
//     for(int k = i+1; k < j; ++k){
//         ans = min(ans, solve(i, k, v) + solve(k, j, v));
//     }
//     ans += v[j] - v[i];
//     table[i][j] = ans;
//     return ans;
// }


// bottom up solution
int main(){ _
    int l;
    while(cin >> l){
        if(l == 0) break;

        memset(table, 0, sizeof table);
        int n;  cin >> n;
        vector<int> v(n+2, 0);
        for(int i = 1; i <= n; ++i)  cin >> v[i];
        v[n+1] = l;

        for(int len = 2; len < n+2; ++len){
            for(int i = 0; i < n+2-len; ++i){
                int j = i + len, ans = INT_MAX;
                for(int k = i+1; k < j; ++k){
                    ans = min(ans, table[i][k] + table[k][j]);
                }
                table[i][j] = ans + v[j]-v[i];
            }
        }

        cout << "The minimum cutting is " << table[0][n+1] << "." << endl;
    }
    return 0;
}
