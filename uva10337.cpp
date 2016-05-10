#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

#define BIG_VALUE 1<<28
int table[10][1001];
int ans[10][1001];

int main(){ _
    int TC; cin >> TC;
    for(int i = 1; i < 10; ++i) ans[i][0] = BIG_VALUE;
    while(TC--){
        int n;  cin >> n;   n /= 100;
        for(int ro = 9; ro >= 0; --ro){
            for(int col = 1; col <= n; ++col){
                cin >> table[ro][col];
            }
        }

        for(int col = 1; col <= n; ++col){
            for(int ro = 0; ro < 10; ++ro){
                int cost = BIG_VALUE;
                if(ro-1 >= 0)   cost = min(ans[ro-1][col-1] + 60 - table[ro-1][col], cost);
                cost = min(ans[ro][col-1] + 30 - table[ro][col], cost);
                if(ro+1 < 10)    cost = min(ans[ro+1][col-1] + 20 - table[ro+1][col], cost);
                ans[ro][col] = cost;
            }
        }

        cout << ans[0][n] << endl;
        cout << endl;
    }
    return 0;
}
