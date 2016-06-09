#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

/* Hint: if #1 == 2*#0, then arrange in sequence of 101 101 101...
If #1 > 2*#0, arrage all 1 first until #1 == 2*#0. Namely: 101 101 101 ... 101 11111111.
When doing: ans |= 1 << i, ans is a long long type, 1 is a int type as default. Then the 1 << i may bring overflow problem. To overcome this problem, use 1LL << i instead.*/

int main(){ _
    int TC; cin >> TC;
    while(TC--){
        long long ans = 0;
        int P, Q;   cin >> P >> Q;

        int idx = 0;
        while(P > 2*Q){
            ans |= 1LL << idx;
            ++idx;
            --P;
        }

        for(int i = idx; i < 52; ++i){
            if(P == 0)  break;
            else if(Q == 0){
                ans |= 1LL << i;
                --P;
            } else {
                switch((i-idx)%3){
                    case 0: case 2:
                        ans |= 1LL << i;
                        --P;
                        break;

                    default:
                        --Q;
                        break;
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}
