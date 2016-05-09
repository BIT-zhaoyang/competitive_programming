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

#define maxAmount 10001
#define BIG_VALUE 1<<28

/* zero-one exact pack problem */

int main(){ _
    int TC; cin >> TC;
    while(TC--){
        int M;  cin >> M;
        vector<int> table(maxAmount+1, BIG_VALUE);    table[0] = 0;
        int N;  cin >> N;
        vector<int> coins(N, 0);
        for(int i = 0; i < N; ++i)  cin >> coins[i];


        for(int i = 0; i < N; ++i){
            for(int v = maxAmount; v >= coins[i]; --v){
                table[v] = min(table[v], table[v - coins[i]] + 1);
            }
        }

        for(int i = M; i < maxAmount; ++i){
            if(table[i] != BIG_VALUE){
                cout << i << " " << table[i] << endl;
                break;
            }
        }
    }
    return 0;
}
