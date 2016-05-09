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

#define BIG_VALUE 1<<28

/*  Hint: 2D complete pack problem. */

int main(){ _
    int TC; cin >> TC;
    while(TC--){
        int n, s;   cin >> n >> s;
        vector< vector<int> > table(s+1, vector<int> (s+1, BIG_VALUE));
        table[0][0] = 0;
        vector< pair<int, int> > coins(n);
        for(int i = 0; i < n; ++i)  cin >> coins[i].first >> coins[i].second;

        for(int i = 0; i < n; ++i){
            for(int x = coins[i].first; x <= s; ++x){
                for(int y = coins[i].second; y <= s; ++y){
                    table[x][y] = min(table[x][y], table[x-coins[i].first][y-coins[i].second] + 1);
                }
            }
        }

        int mini = BIG_VALUE, s2 = s*s;
        for(int x = 0; x <= s; ++x){
            for(int y = 0; y <= s; ++y){
                if(table[x][y] != BIG_VALUE && (x*x + y*y) == s2)
                    mini = min(mini, table[x][y]);
            }
        }
        if(mini == BIG_VALUE)   cout << "not possible" << endl;
        else    cout << mini << endl;

    }
    return 0;
}
