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
/*
Page 77, CP3 Book.
   Tips for complete search are not limited to complete search. For exampl,e Tip 2: Prune Infeasible Search Space has been used in uva10912.
   In this problem, I used tip 5: Try Solving the Problem Backwards. Instead of thinking placing radar to cover islands, think about what the range is if the radar is placed on the island. In another way, what's the range to place a radar if this radar wants to cover a specific island. Then find unique ranges.
*/

int main(){ _
    int n, d, count = 0;
    while(cin >> n >> d){
        if(n == 0 && d == 0) break;
        cout << "Case " << ++count << ": ";

        vector< pair<int, int> > vii(n);
        for(int i = 0; i < n; ++i)  cin >> vii[i].first >> vii[i].second;
        sort(vii.begin(), vii.end());

        bool impossible = false, touch = false;
        vector< pair<double, double> > vdd;
        double left, right, delta;
        for(int i = 0; i < n; ++i){
            if(vii[i].second > d){
                impossible = true;
                break;
            }

            delta = sqrt(d*d - vii[i].second * vii[i].second);
            left = vii[i].first - delta;
            right = vii[i].first + delta;
            touch = false;
            for(int j = 0; j < vdd.size(); ++j){
                if(vdd[j].first > right || vdd[j].second < left)    continue;
                touch = true;
                vdd[j].first = max(vdd[j].first, left);
                vdd[j].second = min(vdd[j].second, right);
            }
            if(!touch)  vdd.push_back(make_pair(left, right));
        }

        if(impossible)  cout << -1 << endl;
        else cout << vdd.size() << endl;
    }
    return 0;
}
