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

int chess[8][8];
bitset<8> row;
bitset<17> pos;    // positive diagnol, x+y
bitset<17> neg;    // negative diagnol, x-y+8

int maxSum;

void recurse(int col, int sum){
    if(col == 8){
        maxSum = max(maxSum, sum);
        return;
    }

    for(int ro = 0; ro < 8; ++ro){
        if(!row[ro] && !pos[col+ro] && !neg[ro-col+8]){
            row[ro] = pos[col+ro] = neg[ro-col+8] = true;
            recurse(col+1, sum + chess[ro][col]);
            row[ro] = pos[col+ro] = neg[ro-col+8] = false;
        }
    }
}

int main(){ _
    int k;  cin >> k;
    while(k--){
        maxSum = 0;
        row.reset(), pos.reset(), neg.reset();
        for(int i = 0; i < 8; ++i)
            for(int j = 0; j < 8; ++j)
                cin >> chess[i][j];

        recurse(0, 0);
        cout << setw(5) << maxSum << endl;
    }
    return 0;
}
