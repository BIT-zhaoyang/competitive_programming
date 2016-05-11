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

long long table[61][61];

unsigned long long rec(int n, int back){
    if(n <= 1)  return 1;
    if(table[n][back] != -1)    return table[n][back];

    unsigned long long sum = 1;
    for(int i = 1; i<= back; ++i)
        sum += rec(n-i, back);
    table[n][back] = sum;
    return sum;
}

int main(){ _
    int n, back, count = 0;
    memset(table, -1, sizeof table);
    while(cin >> n >> back){
        if(n > 60)  break;
        ++count;
        cout << "Case " << count << ": ";
        cout << rec(n, back) << endl;
    }
    return 0;
}
