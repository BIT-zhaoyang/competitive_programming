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
        vector<int> ans(n);
        int least = INT_MAX;

        cin.ignore();
        string str;
        int neib, count = 0;
        for(int i = 0; i < n; ++i){
            getline(cin, str);
            stringstream ss;
            ss << str;
            while(ss >> neib){
                ++count;
            }
            least = min(least, count);
            ans[i] = count;
            count = 0;
        }

        bool notFirst = false;
        for(int i = 0; i < n; ++i){
            if(ans[i] == least){
                if(notFirst)    cout << " ";
                else    notFirst = true;
                cout << i+1;
            }
        }
        cout << endl;

    }
    return 0;
}
