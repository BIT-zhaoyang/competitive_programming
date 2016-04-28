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

int N;
int weight[1010], load[1010];

// top - down
// int memo[1010][6000];
// int knapsack(int idx, int remain){
//     if(remain == 0 || idx == N) return 0;
//     if(memo[idx][remain] != 0)  return memo[idx][remain];
//
//     int ans = 0;
//     // if take this item
//     if(remain >= weight[idx])    ans = knapsack(idx+1, min(remain - weight[idx], load[idx]))+1;
//     ans = max(ans, knapsack(idx+1, remain));
//     memo[idx][remain] = ans;
//
//     return ans;
// }
// int main(){ _
//     while(cin >> N, N){
//         memset(memo, 0, sizeof memo);
//         for(int i = 0; i < N; ++i)  cin >> weight[i] >> load[i];
//         int ans = knapsack(0, 6000);
//         cout << ans << endl;
//     }
//     return 0;
// }

// bottom - up
int memo[6010];
int main(){ _
    while(cin >> N, N){
        memset(memo, 0, sizeof memo);
        for(int i = 0; i < N; ++i)  cin >> weight[i] >> load[i];
        int ans = 0;
        for(int i = N-1; i >= 0; --i){
            for(int j = load[i]; j>= 0; --j){
                memo[j+weight[i]] = max(memo[j+weight[i]], memo[j]+1);
                ans = max(ans, memo[j+weight[i]]);
            }
        }

        cout << ans << endl;
    }
    return 0;
}
