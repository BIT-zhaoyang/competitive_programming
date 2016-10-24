#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
    int n;
    while(cin >> n, n){
        int l = 1, r = 1, lCost = 0, rCost = 0;
        for(int i = 0; i < n; ++i){
            int L, R;   cin >> L >> R;
            int LCost = BIGINT, RCost = BIGINT;
            // from last left to current L
            if(l <= R) LCost = min(LCost, R - L + R - l + lCost);
            else    LCost = min(LCost, l - L + lCost);
            // from last right to current L
            if(r <= R) LCost = min(LCost, R - L + R - r + rCost);
            else    LCost = min(LCost, r - L + rCost);

            // from last left to current R
            if(l >= L)  RCost = min(RCost, R - L + l - L + lCost);
            else    RCost = min(RCost, R - l + lCost);
            // from last right to current R
            if(r >= L)  RCost = min(RCost, R - L + r - L + rCost);
            else    RCost = min(RCost, R - r + rCost);

            l = L, r = R;
            lCost = LCost, rCost = RCost;
        }
        cout << min(n - l + lCost, n - r + rCost) + (n - 1) << endl;
    }
    return 0;
}
