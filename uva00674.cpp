// #include <bits/stdc++.h>
// #define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
// using namespace std;
//
// int main(){ _
//     vector< vector<int> > table(5, vector<int> (7500, 0));
//     int coins[5] = {1, 5, 10, 25, 50};
//     table[0].assign(7500, 1);   // there is only 1 way to make changes of coins using only 1 cent
//     for(int i = 1; i < 5; ++i){
//         for(int j = 0; j < 7500; ++j){
//             if(j >= coins[i])   table[i][j] = table[i][j-coins[i]] + table[i-1][j];
//             else    table[i][j] = table[i-1][j];
//         }
//     }
//
//     int N;
//     while(cin >> N) cout << table[4][N] << endl;
//     return 0;
// }

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
#define coinN 5
#define maxVal 7500

int coins[5] = {1, 5, 10, 25, 50};
int main(){ _
    // precompute
    vector<int> vals(maxVal, 0);
    vals[0] = 1;
    for(int i = 0; i < coinN; ++i){
        for(int j = coins[i]; j < maxVal; ++j){
            vals[j] += vals[j-coins[i]];
        }
    }

    int input;
    while(cin >> input) cout << vals[input] << endl;

    return 0;
}
