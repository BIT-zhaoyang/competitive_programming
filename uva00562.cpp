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

int n, coins[101];
int table[2][50010];
int knapsack(int sum){
    memset(table, 0, sizeof table);

    int pre = 0, cur = 1;
    for(int i = 0; i < n; ++i){
        memset(table[cur], 0, sizeof table[cur]);
        for(int j = 0; j <= sum; ++j){
            if(j >= coins[i])   table[cur][j] = max(table[pre][j], table[pre][j-coins[i]]+coins[i]);
            else    table[cur][j] = table[pre][j];
        }
        pre = cur;
        cur ^= 1;
    }
    return table[pre][sum];
}

int main(){ _
    int TC; cin >> TC;
    while (TC--) {
        cin >> n;
        int sum = 0;
        for(int i = 0; i < n; ++i){
            cin >> coins[i];
            sum += coins[i];
        }

        int half = knapsack(sum>>1);
        cout <<  abs(half*2 - sum)<< endl;
    }
    return 0;
}
