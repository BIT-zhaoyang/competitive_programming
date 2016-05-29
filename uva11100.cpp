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

// 19:24
/*  Let's say size A luggage appeared B times which is the luggage appeared most times. Then, there will be at least B outmost luggages since size A can't contain size A.

After knowing how many outmost luggages we must carry, the rest is super easy. We just assign luggages to these B columns as evenly as possible. We consider luggages in increasing order so the later one will always be capable of containing the earlier one. (Since no luggage of a size has more than B times, thus there won't form a loop when we iterate.) This will be the optimal plan.
*/

int main(){ _
    int n;
    while(cin >> n){
        if(n == 0)  break;
        vector<int> vi(n, 0);
        for(int i = 0; i < n; ++i)  cin >> vi[i];

        sort(vi.begin(), vi.end());

        int last = -1, len = 0, longest = 0;
        for(int i = 0; i < n; ++i){
            if(vi[i] == last){
                ++len;
            } else {
                longest = max(longest, len);
                len = 1;
                last = vi[i];
            }
        }
        longest = max(longest, len);

        vector< vector<int> > ans(longest);
        for(int i = 0, j = 0; i < n; ++i, ++j){
            ans[j%longest].push_back(vi[i]);
        }

        cout << longest << endl;
        for(int i = 0; i < longest; ++i){
            for(int j = 0; j < ans[i].size(); ++j){
                if(j)   cout << " ";
                cout << ans[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
