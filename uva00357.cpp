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

#define nCoins 5
#define maxValue 30000

/* Easy problem: complete pack problem. */

int main(){ _
    int coins[nCoins] = {1, 5, 10, 25, 50};
    vector<long long> table(maxValue+1, 0);
    table[0] = 1;
    for(int i = 0; i < nCoins; ++i){
        for(int v = coins[i]; v <= maxValue; ++v){
            table[v] = table[v] + table[v-coins[i]];
        }
    }

    int n;
    while(cin >> n){
        if(table[n] == 1)
            cout << "There is only 1 way to produce " << n << " cents change." << endl;
        else
            cout << "There are " << table[n] << " ways to produce " << n << " cents change." << endl;
    }

    return 0;
}
