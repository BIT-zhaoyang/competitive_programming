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

/* Previously, I observed that A != B. We can always let A be the smaller value. Then, I put pair(A, B) in a set. If I see it again in the input, I remove it from the set. This works fine for the case 1,2 and 2,1. However, it fails 1,2 and 1,2.

In this program, I read the input and store it in vector<pii> origin, then I exchange A B and store it in vector<pii> reverse. Then sort both vector. If they are same, then it's correct.
*/

int main(){ _
    int n;
    while(cin >> n){
        if(n == 0)  break;

        int a, b;
        pair<int, int> input;
        vector< pair<int, int> > origin(n), reverse(n);

        for(int i = 0; i < n; ++i){
            cin >> a >> b;
            input.first = a, input.second = b;
            origin[i] = input;

            input.second = a, input.first = b;
            reverse[i] = input;
        }

        sort(origin.begin(), origin.end());
        sort(reverse.begin(), reverse.end());
        if(origin == reverse)   cout << "YES" << endl;
        else    cout << "NO" << endl;

    }
    return 0;
}
