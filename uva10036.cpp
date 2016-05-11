#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

bool table[2][100];

/* Lesson Learned:
    Use module to decrese state space size.
    But when you do this, be extremely careful since the module will make the state space choas.
    For example, in this problem, we want to set state[6] and state[11]. We used module 5 here, so both state[6] and state[11] will refer to the same cell -- state[1]. Be careful about this!
    Also refer to uva10616. In fact uva10616 can also be solved using bottom up method.

    This could also happen when we use dimension saving trick to record choices in each state. Using dimension saving trick in computing doesn't matter as long as we take the correct updating order. But in recording choices, new value will cover older value and when we backtrack, we can't recover those old value thus leads to error!
    Refer to uva10086.
*/


int main(){ _
    int TC; cin >> TC;
    while(TC--){
        int n, m;   cin >> n >> m;
        memset(table, 0, sizeof table);

        int prev = 0, curr = 1, val;
        cin >> val;
        table[prev][(val%m + m)%m] = true;
        for(int i = 1; i < n; ++i){
            cin >> val;
            memset(table[curr], 0, sizeof table[curr]);
            for(int v = 0; v < m; ++v){
                int col = ((v+val)%m + m)% m;
                table[curr][col] |= table[prev][v];

                col = ((v-val)%m + m)% m;
                table[curr][col] |= table[prev][v];
            }
            prev = curr;
            curr ^= 1;
        }

        if(table[prev][0])  cout << "Divisible" << endl;
        else    cout << "Not divisible" << endl;
    }
    return 0;
}
