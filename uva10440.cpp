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

int main(){ _
    int TC; cin >> TC;
    while(TC--){
        int n, t, m;    cin >> n >> t >> m;
        int ans = 0, count = 0;

        vector<int> vi(m, 0);
        for(int i = 0; i < m; ++i)  cin >> i[i];

        for(int i = 0; i < m; ++i){
            if(i == n){
                count += 1;
                ans = vi[i] + 2*t;
            }

            while(count < n){
                
            }
        }
    }
    return 0;
}
