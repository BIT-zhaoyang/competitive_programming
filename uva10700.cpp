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
    int TC;  cin >> TC;
    while(TC--){
        string formula; cin >> formula;

        stringstream ss;
        ss << formula;

        long long val, last;
        vector<long long> maxi, mini;
        ss >> val;
        maxi.push_back(val);
        mini.push_back(val);

        char ch;
        while(ss >> ch >> val){
            if(ch == '+'){
                maxi.back() += val;
                mini.push_back(val);
            } else {
                maxi.push_back(val);
                mini.back() *= val;
            }
        }

        long long ma = 1, mi = 0;
        for(int i = 0; i < maxi.size(); ++i)    ma *= maxi[i];
        for(int i = 0; i < mini.size(); ++i)    mi += mini[i];

        cout << "The maximum and minimum are " << ma << " and " << mi << "." << endl;
    }


    return 0;
}
