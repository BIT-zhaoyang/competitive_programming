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
    string s, t;
    while(cin >> s >> t){
        int i = 0, j = 0;
        while(i < s.size() && j < t.size()){
            if(s[i] == t[j]){
                ++i, ++j;
            } else {
                ++j;
            }
        }

        if(i == s.size())   cout << "Yes" << endl;
        else    cout << "No" << endl;
    }
    return 0;
}
