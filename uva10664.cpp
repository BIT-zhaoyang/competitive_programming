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

bool solve(vector<int> &vi, int sum){
    if(sum % 2) return false;
    else    sum /= 2;

    bool table[2][sum+1];
    int pre = 0, cur = 1;
    memset(table, 0, sizeof table);
    table[pre][0] = true;

    for(int i = 0; i < vi.size(); ++i){
        memset(table[cur], 0, sizeof table[cur]);
        for(int j = 0; j < sum+1; ++j){
            if(j >= vi[i])  table[cur][j] = table[pre][j] | table[pre][j-vi[i]];
            else    table[cur][j] = table[pre][j];
        }
        pre = cur;
        cur ^= 1;
    }

    return table[pre][sum];
}

int main(){ _
    int TC; cin >> TC;
    cin.ignore();
    while(TC--){
        stringstream ss;
        string str;
        getline(cin, str);
        ss << str;
        int num, sum = 0;
        vector<int> vi;
        while(ss >> num){
            vi.push_back(num);
            sum += num;
        }

        if(solve(vi, sum))  cout << "YES" << endl;
        else    cout << "NO" << endl;

    }
    return 0;
}
