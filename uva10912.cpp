#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

/* lesson learned: decrease the state space by cutting. Don't use the max value provided by the problem directly. */

int table[30][355][27]; // since the string is in ascending order, its length is of 26 at longest. I used 30 as a looser bound. And based on this observation, its sum is 351 at maximum.

int rec(int L, int S, int ch){
    if(S <= 0 || ch == 0)  return 0;
    if(L == 1){
        if(S <= ch) return 1;
        else    return 0;
    }

    if(table[L][S][ch] != -1)   return table[L][S][ch];
    int sum = 0;
    for(int i = 1; i <= ch; ++i){
        sum += rec(L-1, S - i, i-1);
    }
    table[L][S][ch] = sum;
    return sum;
}

int main(){ _
    memset(table, -1, sizeof table);
    int L, S, count = 0;
    while(cin >> L >> S){
        if(L+S == 0)    break;
        cout << "Case " << ++count << ": ";
        if(L > 26 || S > 351)  cout << 0 << endl;
        else cout << rec(L, S, 26) << endl;
    }
    return 0;
}
