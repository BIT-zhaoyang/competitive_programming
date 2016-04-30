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

int solve(vector<int>& d, vector<int>& v, vector<int>& ans, int W){
    int n = d.size();
    vector< vector<int> > table(n, vector<int> (W+1, 0));
    vector< vector<bool> > choice(n, vector<bool> (W+1, 0));

    for(int i = 1; i < n; ++i){
        for(int j = 0; j <= W; ++j){
            if(j >= d[i]){
                if(table[i-1][j] >= table[i-1][j-d[i]] + v[i]){
                    table[i][j] = table[i-1][j];
                    choice[i][j] = false;
                } else {
                    table[i][j] = table[i-1][j-d[i]] + v[i];
                    choice[i][j] = true;
                }
            }
            else{
                table[i][j] = table[i-1][j];
                choice[i][j] = false;
            }
        }
    }

    for(int i = n-1, j = W; i != 0; --i){
        if(choice[i][j]){
            ans.push_back(i);
            j -= d[i];
        }
    }

    return table[n-1][W];
}

int main(){ _
    int W, c, n;
    int count = 0;
    while(cin >> W){
        if(count++)   cout << endl;

        cin >> c >> n;
        vector<int> d(n+1, 0);
        vector<int> _d(n+1, 0);
        vector<int> v(n+1, 0);
        vector<int> ans;
        for(int i = 1; i <= n; ++i){
            cin >> d[i] >> v[i];
            _d[i] = d[i] * 3 * c;
        }

         cout << solve(_d, v, ans, W) << endl;
         cout << ans.size() << endl;
         for(int i = ans.size()-1; i >= 0; --i){
             cout << d[ans[i]] << " " << v[ans[i]] << endl;
         }
    }
    return 0;
}
