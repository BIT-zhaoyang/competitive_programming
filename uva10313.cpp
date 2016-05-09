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

#define nCoins 300
#define maxK 1000
#define maxV 1000
long long table[maxK+1][maxV+1];

/* Lesson Learned:
    This is a 2D complete pack problem.
    The order of updating the dynamic table !!only!! depends on if this problem is complete pack or zero-one pack. Even the problem has been expanded to 2D problem, it won't affect the order of updating the dynamic table.
*/


void preprocess(){
    memset(table, 0, sizeof table);
    table[0][0] = 1;
    for(int coin = 1; coin <= nCoins; ++coin){
        for(int k = 1; k <= maxK; ++k){
            for(int v = coin; v <= maxV; ++v){
                table[k][v] += table[k-1][v-coin];
            }
        }
    }

    // sum up the table for constant query time
    for(int k = 1; k <= maxK; ++k){
        for(int v = 0; v <= maxV; ++v){
            table[k][v] += table[k-1][v];
        }
    }
}

int main(){ _
    preprocess();
    string str;
    while(getline(cin, str)){
        stringstream ss;
        ss << str;
        int a = -1, b = -1, c = -1;
        ss >> a >> b >> c;

        if(c == -1){
            if(a == 0)  cout << 1 << endl;  // special cases
            else if(b == -1) cout << table[maxK][a] << endl;
            else cout << table[b][a] << endl;
        } else {
            if(a == 0 && b == 0)    cout << 1 << endl;
            else if(a == 0 && b != 0)   cout << 0 << endl;
            else cout << table[c][a] - table[max(b-1, 0)][a] << endl;
        }
    }
    return 0;
}
