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

/* Choose the one with longest common subsequences first. If the LCS is the same, choose the one with least types first.
Many problems seem to have a better/easier solution when considering them backwards. Such as this one, I started to think I should choose the one with least types first. But it turns out that, we should choose the one having LCS.
*/


int common(string &last, string &curr){
    if(curr == "0")    return -(1<<20);

    int same = 0;
    for(int i = 0; i < last.size() && i < curr.size(); ++i){
        if(last[i] == curr[i])    ++same;
        else    break;
    }

    return same;
}

int main(){ _
    int TC; cin >> TC;
    while(TC--){
        int n;  cin >> n;
        vector<string> vs(n), vans;
        for(int i = 0; i < n; ++i){
            cin >> vs[i];
        }

        string last(vs[0]);
        int ans = last.size();
        vs[0] = "0";
        vans.push_back(last);
        for(int i = 1; i < n; ++i){
            int types = INT_MAX, choose = -1, com = 0, d = INT_MAX, maxCom = 0;
            for(int j = 0; j < n; ++j){
                com = common(last, vs[j]);
                d = vs[j].size() - com;
                if(com > maxCom){
                    types = d;
                    choose = j;
                    maxCom = com;
                } else if(com == maxCom){
                    if(d < types){
                        types = d;
                        choose = j;
                        maxCom = com;
                    }
                }
            }

            ans += types;
            vans.push_back(vs[choose]);
            last = vs[choose];
            vs[choose] = "0";
        }

        cout << ans << endl;
        for(int i = 0; i < n; ++i){
            cout << vans[i] << endl;
        }
    }
    return 0;
}
