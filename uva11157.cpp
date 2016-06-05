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

/* Solving pattern: start from a small example, draw a graph. You will find the optimal choice is to use the small stones alternatively. For example, B1 -> S1 -> S3 -> B2 -> S2 -> B1 or B1 -> S2 -> S4 -> B2 -> S3 -> S1 -> B1.
*/

int betweenBig(int a, int b, vector<int> &vi){
    // a: index of the left big stone
    // b: index of the right big stone
    if(b - a == 1 || b - a == 2)    return vi[b] - vi[a];

    int ans = 0;
    // count B1 -> S2 -> S4 -> ... Sn/B2
    for(int i = a; i + 2 <= b; i += 2){
        ans = max(ans, vi[i+2] - vi[i]);
    }
    // count S1->S3-> ... -> S_2n-1/B2
    for(int i = a+1; i + 2 <= b; i += 2){
        ans = max(ans, vi[i+2] - vi[i]);
    }

    return ans;
}

int main(){ _
    int TC; cin >> TC;
    for(int tc = 1; tc <= TC; ++tc){
        cout << "Case " << tc << ": ";

        int n, d;  cin >> n >> d;
        vector<int> vi(n+2, 0);
        vi[0] = 0;  vi.back() = d;

        char type, hypen;
        int val;
        vector<int> big(1, 0);  // count the left river bank as a big stone
        for(int i = 1; i <= n; ++i){
            cin >> type >> hypen >> val;
            vi[i] = val;
            if(type == 'B') big.push_back(i);
        }
        big.push_back(n+1); // count the right river bank as a big stone

        int ans = 0;
        for(int i = 0; i < big.size() - 1; ++i){
            ans = max(ans, betweenBig(big[i], big[i+1], vi));
        }
        cout << ans << endl;

    }
    return 0;
}
