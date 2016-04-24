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
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);

using namespace std;

/*
    =================== CONVERT BINARY TO GRAY ==========================
        BINARY                  GRAY
        0 0 0                  0 0 0
        0 0 1                  0 0 1
         -----
        0 1 0                  0 1 1
        0 1 1    ========>     0 1 0
    ----------------------------------
        1 0 0                  1 1 0
        1 0 1                  1 1 1
        1 1 0                  1 0 1
        1 1 1                  1 0 0

    In binary code, the patterns are repeated in exactly the same way. For example, in the last bit, it's always 0 1 0 1 0 1, but in gray code, the pattern is inverted in reverse way, namely, 0 1 1 0 0 1 1 0. When does the repeation happen? When the next significant bit is set to 1. So, the only difference between binary and gray is how they repeat the patterns. Thus, to convert binary to gray, the only thing we need to do is to flip the bit (in binary code) next to the turned on more significant bit. For example, (1 0)_2, the 1 is turned on, then we flip 0, -> (1 1)_gray. (1 1)_2, the first 1 is turned on, we filp the second 1, -> (1 0)_gray. This pattern can be summarized by the operation n^(n >> 1).
*/


int main(){ _
    int T;  cin >> T;
    // vector<int> results(1, 0);
    // results.reserve(1<<30);
    int n, k, currN;
    while(T--){
        cin >> n >> k;
        // currN = log2(results.size());
        // for(int i = currN; i < n; ++i){
        //     int currSize = results.size();
        //     for(int j = currSize - 1; j >= 0; --j){
        //         results.push_back(results[j] + (1<<i));
        //     }
        // }
        // cout << results[k] << endl;
        cout << (k^(k>>1)) << endl;
    }
    return 0;
}
