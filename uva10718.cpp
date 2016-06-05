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
#include <queue>
#include <stack>

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

/* What kind of problem is this? More like understanding of binary numbers rather than a greedy problem.
References:
http://blog.csdn.net/hcbbt/article/details/11039623
http://www.cnblogs.com/staginner/archive/2012/01/01/2309477.html
*/

int main(){ _
    uint N, L, U;
    while(cin >> N >> L >> U){
        bitset<32> binN(N);

        uint candidate = 0;
        for(int i = 31; i >= 0; --i){
            if(binN[i]){ // if binN[i] is set, try to set candidate[i] as off
                // when set off, see if the possible range [candL, candU] is in [L, U]
                uint candU = candidate + ((1<<i) - 1);  // candL == candidate
                if(candU < L) // if set off and the upper band of the candidate range is less than L
                    candidate |= (1<<i);    // set this bit on
                // else set it off, which means nothing since it's intially off
            } else { // if binN[i] is off, try to set candidate[i] on
                uint candL = candidate + (1 << i);
                if(candL <= U)  candidate |= (1 << i);
                // we don't need to care about candU since candU must be larger than L, or there will be no solution which is impossible
            }
        }

        cout << candidate << endl;

    }
    return 0;
}
