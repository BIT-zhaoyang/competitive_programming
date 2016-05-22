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

/* spectial interval cover problem.
   For a length n field, there are n+2 places to put the scarecrow, from -1 to n+1.
   Each scarecrow has the cover range of 3.

   According to the interval cover idiom, for a cell at i, the scarecrow can be placed at i-1, i, i+1. Choose the i+1 one since it has the rightmost right border.
*/

int main(){ _
    int TC; cin >> TC;
    for(int c = 1; c <= TC; ++c){
        cout << "Case " << c << ": ";
        int n;  cin >> n;
        string str; cin >> str;
        int count = 0;
        for(int i = 0; i < n; ++i){
            if(str[i] == '.'){
                ++count;
                i += 2;
            }
        }

        cout << count << endl;
    }
    return 0;
}
