#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 25
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
    int n, k, tc = 0;
    while(cin >> n >> k){
        if(n == 0)  break;
        vector<int> tickets[n][n];

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j){
                if(j == i)  continue;

                int period; cin >> period;
                for(int k = 0; k < period; ++k){
                    int price;  cin >> price;
                    if(price == 0)  price = BIGINT;
                    tickets[i][j].push_back(price);
                }
            }

        vector<int> cost[2] = {vector<int> (n, BIGINT), vector<int> (n, BIGINT)};
        int pre = 0, cur = 1;
        cost[pre][0] = 0;
        for(int day = 0; day < k; ++day){
            cost[cur].assign(n, BIGINT);
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < n; ++j){
                    if(j == i)  continue;
                    int period = tickets[i][j].size();
                    cost[cur][j] = min(cost[cur][j],
                                       cost[pre][i] + tickets[i][j][day % period]);
                }
            }
            cur = 1 - cur, pre = 1 - pre;
        }

        cout << "Scenario #" << ++tc << endl;
        if(cost[pre][n-1] == BIGINT)    cout << "No flight possible.\n\n";
        else    cout << "The best flight costs " << cost[pre][n-1] << ".\n\n";
    }
    return 0;
}
