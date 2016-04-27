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
#include <tuple>

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

map<long long, int> table;
map<long long, bool> choice;

vector<int> cars;
int solve(int left, int right, int idx){
    if(left < 0 || right < 0)    return -1;
    if(idx == cars.size())  return 0;

    long long key = left*1e7 + right*1e2 + idx;
    // string str = to_string(left) + "," + to_string(right) + "," + to_string(idx);
    if(table[key]) return table[key];

    int goLeft = solve(left-cars[idx], right, idx+1)+1;
    int goRight = solve(left, right-cars[idx], idx+1)+1;

    if(goLeft >= goRight){
        table[key] = goLeft;
        choice[key] = true;
    } else {
        table[key] = goRight;
        choice[key] = false;
    }

    return table[key];
}

void printResult(int left, int right, int idx){
    if(left < 0 || right < 0 || idx >= cars.size())    return;
    long long key = left*1e7 + right*1e2 + idx;
    // string str = to_string(left) + "," + to_string(right) + "," + to_string(idx);
    if(table[key] != 0){
        // cout << choice[key] << endl;
        if(choice[key]){
            cout << "port" << endl;
            printResult(left-cars[idx], right, idx+1);
        }else{
            cout << "starboard" << endl;
            printResult(left, right-cars[idx], idx+1);
        }
    }
}


int main(){ _
    int TC; cin >> TC;
    while(TC--){
        table.clear(); cars.clear(); choice.clear();
        int shipLen, carLen;
        cin >> shipLen; shipLen *= 100;
        while(cin >> carLen, carLen)
            cars.push_back(carLen);

        cout << solve(shipLen, shipLen, 0) << endl;
        printResult(shipLen, shipLen, 0);
        if(TC)  cout << endl;
    }
    return 0;
}
