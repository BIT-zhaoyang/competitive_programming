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

#define BIG true
#define SMALL false

int main(){ _
    int TC; cin >> TC;
    while(TC--){
        int n;  cin >> n;
        vector<int> vi(n, 0);
        for(int i = 0; i < n; ++i){
            cin >> vi[i];
        }

        int ans = 1, last = vi[0];
        bool direct = SMALL;
        for(int i = 1; i < n; ++i){
            if(direct == SMALL){
                if(vi[i] < last){
                    last = vi[i];
                    direct = BIG;
                    ++ans;
                } else {
                    last = vi[i];
                }
            } else {
                if(vi[i] > last){
                    last = vi[i];
                    direct = SMALL;
                    ++ans;
                } else {
                    last = vi[i];
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}
