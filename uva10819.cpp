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

/* The difference between this problem and previous problems I solved is that this one asks us to fill the bag with exact the volume rather than leaving empty space.

So the optimal substructure is: "Spend !!exact!! money b(udget), what's the maximal favor we can get?" rather than "Spend !!within!! money b(duget), what's the maximal favor we can get?".

Consider this example input:
1999
1998 4
2000 3
2 2
The optimal choice is 3(2000) + 2(2) = 5.
*/

int helper(int _m, int n, vector<int> &v, vector<int> &f){
    int m = _m;
    m += 200;
    vector<int> favor(m+1, -1); favor[0] = 0;
    for(int i = 0; i < n; ++i){
        for(int b = m; b >= v[i]; --b){
            if(favor[b - v[i]] != -1){
                favor[b] = max(favor[b], favor[b - v[i]] + f[i]);
            }
        }
    }

    int maxFavor = 0;
    for(int i = m; i > 2000; --i)   maxFavor = max(maxFavor, favor[i]);
    for(int i = _m; i > 0; --i) maxFavor = max(maxFavor, favor[i]);
    return maxFavor;
}

int main(){ _
    int m, n;
    while(cin >> m >> n){
        vector<int> v(n, 0), f(n, 0);
        for(int i = 0; i < n; ++i)  cin >> v[i] >> f[i];
        int ans = helper(m, n, v, f);
        cout << ans << endl;
    }
    return 0;
}
