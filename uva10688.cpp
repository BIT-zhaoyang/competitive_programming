#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <climits>
#include <cmath>
#include <set>
#include <bitset>
#include <sstream>
#include <iomanip>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

int main(){ _
    int TC; cin >> TC;
    for(int t = 1; t <= TC; ++t){
        int n, s;   cin >> n >> s;
        vector<int> vi(n, 0);
        for(int i = 0; i < n; ++i) vi[i] = i+1 + s;

        vector< vector<int> > dp(n, vector<int> (n, 0));
        for(int len = 1; len < n; ++len){
            for(int i = 0; i < n - len; ++i){
                int j = i + len, ans = INT_MAX;
                for(int k = i; k <= j; ++k){
                    ans = min(ans,    dp[i][max(i, k-1)]
                                    + dp[min(k+1, j)][j]
                                    + (j-i+1)*vi[k]);
                }
                dp[i][j] = ans;
            }
        }
        cout << "Case " << t << ": " << dp[0][n-1] << endl;
    }
    return 0;
}
