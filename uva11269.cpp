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

/*  Good problem: learned something new.
    First, this is again an arrange problem. So my previous summary is correct(see uva10026).
    Namely, assume an ordering is a_1 a_2 a_3 .... a_n a_n+1 .... a_m. If we only change a_n & a_n+1, sequence before this will not be affected. Then, what about sequence after a_n+1? The only affect is the start time of a_n+2.G will be earlier. This leads to not worse total G time.(This is a hard place to think clear in a short time).

    So, based on above observation, let's just discuss how should we arrange a_n & a_n+1. Previously, I thought there will be only a single greedy rule, and we should stick to that all the time. For example, the rule may be: always choose the one with larger G time. However, in this problem, it is not that case. There is still only one single greedy rule, but this rule may be not determined by a single variable. In this problem, when we arrange in the order of a_n, a_n+1, the cost is t1 = a1.S + max(a1.G, a2.S) + a2.G; when we arrange in the order of a_n+1, a_n, the cost is t2 = a2.S + max(a2.G, a1.S) + a1.G; We compare these two costs then decide which order we choose. We doesn't have to stick to the same order all the time.

    PS: the concise representation of t1 = a1.S + max(a1.G, a2.S) + a2.G is another technique I learned. Previously, I even want to represent this use an if-else statement based on comparing a1.G & a2.S. So, !!!sometimes!!!, make program as concise as possible is not a good thing, but not always!

    PSS: the more general greedy rule in uva10026 can be obtained in the same way. Actually that rule    used in uva10026 is already a more general rule. It's just further transformed to record other values while reading inputs.
*/

#define S first
#define G second

bool mycomp(pair<int, int> &a1, pair<int, int> &a2){
    int t1 = a1.S + max(a1.G, a2.S) + a2.G;
    int t2 = a2.S + max(a2.G, a1.S) + a1.G;


    if(t1 < t2) return true;
    else    return false;
}

int main(){ _
    int n;
    while(cin >> n){
        vector< pair<int, int> > pii(n);
        for(int i = 0; i < n; ++i)  cin >> pii[i].S;
        for(int i = 0; i < n; ++i)  cin >> pii[i].G;

        sort(pii.begin(), pii.end(), mycomp);

        int s = 0, g = 0;
        for(int i = 0; i < n; ++i){
            s += pii[i].S;
            g = max(s, g);
            g += pii[i].G;
        }

        cout << g << endl;
    }
    return 0;
}
