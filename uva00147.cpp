#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(2);
using namespace std;

const int maxVal = 6010;
const int nCoins = 11;
int coins[nCoins] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};
long long change[maxVal];

void preprocess(){
    long long table[2][maxVal];
    int pre = 0, cur = 1;

    // if we only use coin 1
    for(int val = 0; val < maxVal; ++val)   table[pre][val] = 1;


    for(int i = 1; i < nCoins; ++i){
        // memset(table[cur], 0, sizeof table[cur]);
        for(int val = 0; val < maxVal; ++val){
            if(val >= coins[i])
                table[cur][val] = table[pre][val] + table[cur][val - coins[i]];
            else
                table[cur][val] = table[pre][val];
        }
        pre = cur;
        cur ^= 1;
    }

    for(int val = 0; val < maxVal; ++val)
        change[val] = table[pre][val];
}

int main(){ _
    preprocess();
    double temp;    int val;
    while(cin >> temp){
        if(temp == 0)   break;

        val = int(temp * 20);
        cout << fixed << right << setw(6) << temp;
        cout << right << setw(17) << change[val] << endl;
    }
    return 0;
}
