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

/* similiar to 10672 */

int main(){ _
    int n;
    while(cin >> n){
        if(n == 0)  break;
        long long sum = 0, ans = 0, val;
        for(int i = 0; i < n; ++i){
            cin >> val;
            sum += val;
            ans += abs(sum);
        }

        cout << ans << endl;
    }
    return 0;
}
