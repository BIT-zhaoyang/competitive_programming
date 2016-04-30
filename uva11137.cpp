#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

int main(){ _
    vector<int> coins(21, 0);
    for(int i = 0; i < 21; ++i) coins[i] = pow(i+1, 3);

    vector< vector<long long> > table(21, vector<long long> (10000, 0));
    table[0].assign(10000, 1);
    for(int i = 1; i < 21; ++i){
        for(int j = 0; j < 10000; ++j){
            if(j >= coins[i])   table[i][j] = table[i-1][j] + table[i][j - coins[i]];
            else    table[i][j] = table[i-1][j];
        }
    }

    int N;
    while(cin >> N) cout << table[20][N] << endl;
    return 0;
}
