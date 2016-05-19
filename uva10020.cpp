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

int main(){ _
    int TC; cin >> TC;
    while(TC--){
        int m, left, right;
        cin >> m;

        vector< pair<int, int> > vii;
        while(cin >> left >> right){
            if(left == 0 && right == 0) break;
            if(right <= 0)   continue;
            vii.push_back(make_pair(left, right));
        }
        vii.push_back(make_pair(1<<25, 1<<25));
        sort(vii.begin(), vii.end());

        int count = 0, tail = 0;
        vector< pair<int, int> > ans;
        pair<int, int> choose(0, 0);
        for(int i = 0; i < vii.size(); ++i){
            if(tail >= m)   break;
            if(vii[i].first <= tail){
                if(vii[i].second > choose.second) choose = vii[i];
            }
            else{
                ++count;
                tail = choose.second;
                ans.push_back(choose);

                if(vii[i].first <= tail && vii[i].second > choose.second)   choose = vii[i];
            }
        }

        if(ans.back().second < m){
            cout << 0 << endl;
        } else {
            cout << count << endl;
            for(int i = 0; i < ans.size(); ++i)
                cout << ans[i].first << " " << ans[i].second << endl;
        }

        if(TC)  cout << endl;
    }
    return 0;
}
