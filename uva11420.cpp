#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

#define LOCKED 1
#define UNLOCKED 0

unsigned long long table[2][66][66];
unsigned long long rec(int pre, int n, int s){
    if(s < 0)   return 0;
    if(n == 0)  return s == 0;
    if(table[pre][n][s] != -1)  return table[pre][n][s];

    unsigned long long ans = 0;
    ans = rec(UNLOCKED, n-1, s - (pre & UNLOCKED)) + rec(LOCKED, n-1, s - (pre & LOCKED));
    table[pre][n][s] = ans;
    return ans;
}

int main(){ _
    memset(table, -1, sizeof table);
    int n, s;
    while(cin >> n >> s){
        if(n < 0 && s < 0) break;
        cout << rec(LOCKED, n, s) << endl;
    }
    return 0;
}
