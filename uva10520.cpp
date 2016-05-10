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

long long a[20][20];

int main(){ _
    int n, val;
    while(cin >> n >> val){
        a[n][1] = val;
        for(int i = n; i > 0; --i){
            for(int j = 1; j <=n; ++j){
                if(i == n && j == 1)    continue;
                if(i < j){
                    long long v = INT_MIN;
                    for(int k = i; k < j; ++k)  v = max(a[i][k] + a[k+1][j], v);
                    a[i][j] = v;
                } else{ // i >= j
                    long long jPart = 0;
                    for(int k = 1; k < j; ++k)  jPart = max(jPart, a[i][k]+a[n][k]);

                    long long iPart = 0;
                    for(int k = i+1; k <= n; ++k)    iPart = max(iPart, a[k][1] + a[k][j]);

                    a[i][j] = iPart + jPart;
                }
            }
        }
        cout << a[1][n] << endl;
    }
    return 0;
}
