#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

#define maxN 71
#define maxT 71
int table[maxN][maxT];

/* Can be seen as maxN coins to sum up to maxT value. Each coin has the value between p and upper.
upper = t - (n-1)*p;
*/

int main(){ _
    int tc; cin >> tc;
    while(tc--){
        memset(table, 0, sizeof table);
        table[0][0] = 1;

        int n, t, p;    cin >> n >> t >> p;
        int upper = t - (n-1)*p;
        for(int i = 1; i <= n; ++i){
            for(int j = p; j <= upper; ++j){
                for(int k = j; k <= t; ++k){
                    table[i][k] += table[i-1][k-j];
                }
            }
        }
        cout << table[n][t] << endl;
    }
    return 0;
}
