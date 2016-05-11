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
    int n, m, t;
    while(cin >> n >> m >> t){
        vector<int> table(t+1, INT_MIN);
        table[0] = 0;
        for(int i = n; i <= t; ++i) table[i] = max(table[i], table[i-n] + 1);
        for(int i = m; i <= t; ++i) table[i] = max(table[i], table[i-m] + 1);

        if(table[t] > 0) cout << table[t] << endl;
        else{
            bool found = false;
            for(int i = t; i >= 0; --i){
                if(table[i] > 0){
                    cout << table[i] << " " << t-i << endl;
                    found = true;
                    break;
                }
            }
            if(!found)  cout << 0 << " " << t << endl;
        }

    }
    return 0;
}
