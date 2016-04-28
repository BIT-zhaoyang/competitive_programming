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
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(2);
using namespace std;

int n, x;
int holder[101], table[2][5050];
int knapsack(){
    memset(table, 0, sizeof table);

    int pre = 0, cur = 1;
    for(int i = 0; i < n; ++i){
        if(i == x)  continue;

        memset(table[cur], 0, sizeof table[cur]);
        for(int j = 0; j <= 4999; ++j){
            if(j >= holder[i])
                table[cur][j] = max(table[pre][j], table[pre][j-holder[i]]+holder[i]);
            else
                table[cur][j] = table[pre][j];
        }

        pre = cur;
        cur ^= 1;
    }

    return table[pre][4999];
}


int main(){ _
    while(cin >> n >> x){
        if(n == 0 && x == 0)    break;
        --x;
        int a, b;
        for(int i = 0; i < n; ++i){
            cin >> a; cin.ignore(); cin >> b;
            holder[i] = a*100 + b;
        }
        int others = knapsack();
        double ans = (holder[x] / double(1e4 - others))*100.0;
        cout << fixed << ans << endl;
    }
    return 0;
}
