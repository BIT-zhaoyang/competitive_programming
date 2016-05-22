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
        int n;  cin >> n;
        vector<int> vi(n+1, 0);   vi[n] = INT_MAX;
        vector< int > val(n);  // what's the smallest number using as many kinds of coins as possbile of only the first k coins? Don't have to use all these coins.
        for(int i = 0; i < n; ++i)  cin >> vi[i];

        int ans = 1;
        val[0] = 1;
        for(int i = 1; i < n; ++i){
            if(val[i-1] < vi[i] && val[i-1] + vi[i] < vi[i+1]){
                val[i] = val[i-1] + vi[i];
                ++ans;
            } else{
                val[i] = val[i-1];
            }
        }
        cout << ans << endl;
    }

    // // DP solution. Won't pass the test since DP is not efficient enough
    // int TC; cin >> TC;
    // while(TC--){
    //     int n;  cin >> n;
    //     vector<int> vi(n, 0);
    //     for(int i = 0; i < n; ++i)  cin >> vi[i];
    //     vector<int> val(vi.back(), 1<<28);
    //     val[0] = 0;
    //     int ans = 0;
    //     for(int i = 0, j = 1; i < vi.size()-1; ++i){
    //         while(j < vi[i+1] && j < val.size()){
    //             val[j] = val[j - j/vi[i]*vi[i]] + 1;
    //             ans = max(ans, val[j]);
    //             ++j;
    //         }
    //     }
    //     cout << ans+1 << endl;
    // }
    return 0;
}
