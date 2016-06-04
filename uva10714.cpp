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

/* When I saw the explanation at:
http://www.algorithmist.com/index.php/UVa_10714
I chuckled. Feel I've been fooled in a clever way.
*/

int main(){ _
    int TC; cin >> TC;
    while(TC--){
        int L, N;   cin >> L >> N;
        int mi = 0, ma = 0, val;
        for(int i = 0; i < N; ++i){
            cin >> val;
            mi = max(min(val, L-val), mi);
            ma = max(max(val, L-val), ma);
        }

        cout << mi << " " << ma << endl;
    }
    return 0;
}
