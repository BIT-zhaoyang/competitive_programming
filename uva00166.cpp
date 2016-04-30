#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

// double coins[6] = {0.05, 0.1, 0.2, 0.5, 1, 2};
int coins[6] = {1, 2, 4, 10, 20, 40};
int cashier[110];
int customer[110];
int nums[6];

int main(){ _
    // optimal change returned by cashier if we pay more than we should
    for(int i = 0; i < 110; ++i)    cashier[i] = 1000;
    cashier[0] = 0;
    for(int i = 1; i < 110; ++i)
        for(int j = 0; j < 6; ++j)
            if(i >= coins[j])
                cashier[i] = min(cashier[i], cashier[i-coins[j]]+1);


    while(true){
        bool terminate = false;
        for(int i = 0; i < 6; ++i){
            cin >> nums[i];
            if(nums[i]) terminate = true;
        }
        if(!terminate)  break;

        double temp;
        int change;
        cin >> temp;
        change = int(temp * 20);

        // optimal #coins the customer will pay
        // initialize table
        int table[2][110];
        int pre = 0, cur = 1;
        for(int val = 0; val < 110; ++val)    table[pre][val] = 500;
        table[pre][0] = 0;

        for(int i = 0; i < 6; ++i){
            for(int j = 0; j < nums[i]; ++j){   // This loop counts the number of current coin used
                memset(table[cur], 0, sizeof table[cur]);
                for(int val = 0; val < 110; ++val){
                    if(val >= coins[i])
                        table[cur][val] = min(table[pre][val], 1+table[pre][val - coins[i]]);
                        // if number of coins is not limited, this line will be
                        // table[cur][val] = min(table[pre][val], 1+table[cur][val - coins[i]]);
                        // and the 2nd loop will be removed
                    else
                        table[cur][val] = table[pre][val];
                }
                pre = cur;
                cur ^= 1;
            }
        }
        for(int val = 0; val < 110; ++val)    customer[val] = table[pre][val];

        int ans = INT_MAX;
        for(int val = change; val < 101; ++val)
            ans = min(ans, customer[val] + cashier[val-change]);
        cout << right << setw(3) << ans << endl;
    }
    return 0;
}
