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

/* Ah....Took me a long time to come up with the proof. Again, there are solutions on the internet but no proof available.

Again, I don't know what lesson I learned from the problem. Maybe... solving problem backwards is really a good heuristic. (This problem can be easily solved with DP since the scale is not big.)
Proof:
Let's think about what's the best possible result for this problem in terms of time? The answer is obvious, we cross the river once the last arrived. Then the answer if T_m + t. So, why not assume this case is possible and go backwards to see what happens?

So let's focus on the last ferry. One question is, how many cars shall we load? The choices can be categoritzed into two possibilities: we load N cars and we load less than N cars. However, when we want to load the last batch, the question is: is the ferry available? Namely, is the ferry back from last crossing? This question can be answered by max(T_(M-N)+2t, T_M)+t. The first element in the max() funciton is the returning time of last crossing. T_M is the arriving time of the Mth car. If the returning time of last ferry is later than the arrival of the Mth car, then it's T_(M-N)+2t + t. Similiarly, if we load less then N cars, then the answer is max(T_(M-N+k)+2t, T_M)+t. Namely, we loaded N-k cars last time.

If T_M is larger in both case, then the answer is the same. If not, we notice that T_(M-N) < T_(M-N+k) so that the plan 1 is not worse than plan 2. So we can stick to plan 1. Thus, in terms of time, plan 1 is definetly better.

Then let's discuss the times to cross the river. Since plan 1 always load no less number of cars than plan 2, thus plan 1 has no more times to cross the river than plan 2.

In conclusion, plan 1 is the optimal plan.

Psudo code:
1. if(m % n)   load the remainder first.
2. load cars in batches of n cars.
*/

int main(){ _
    int TC; cin >> TC;
    while(TC--){
        int n, t, m;    cin >> n >> t >> m;

        vector<int> vi(m+1, 0);
        for(int i = 1; i <= m; ++i)  cin >> vi[i];

        int rem = m % n, ans = 0, pointer = 0, count = 0;
        if(rem){
            pointer = rem;
            ans = vi[pointer] + 2*t;
            ++count;
        }
        while(pointer < m){
            pointer += n;
            ans = max(ans, vi[pointer]) + 2*t;
            ++count;
        }

        cout << ans - t << " " << count << endl;    // we counted double 2 for the last ferry so
    }                                               // minus t when output.
    return 0;
}
