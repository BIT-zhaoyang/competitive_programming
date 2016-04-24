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

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);

using namespace std;

int main(){ _
    int TC; cin >> TC;
    set<int> ans;
    while(TC--){
        int P, N;   cin >> P >> N;
        vector<int> symbols(N, 0);
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < P; ++j){
                int val;    cin >> val;
                if(val) symbols[i] = symbols[i] | (1 << j);
            }
        }

        int result = P;
        for(int i = 0; i < (1<<P); ++i){
            ans.clear();

            for(int j = 0; j < N; ++j){
                ans.insert(symbols[j] & i);
            }

            if(ans.size() < N)    continue;
            else{
                int sum = 0;
                for(int j = 0; j < P; ++j){
                    if(i & (1<<j))  sum += 1;
                }
                result = min(sum, result);
            }
        }

        cout << result << endl;
    }
    return 0;
}
