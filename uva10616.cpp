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

/* Lesson learned:

1.  process negative number module in c++
 a < 0, b > 0
 a % b = ((a % b) + b) % b;

2. how to write recursive DP
Identify base case first, look up table second.
Considering two possibilities:
    1). This base case have already been computed and stored.
    2). This base case have not been computed(This base case may contain illegal state to the table)

In the first case, even if we look up the table first, we will need O(1) time to return this value.
In the second case, if we look up the table first, we may look up an illegal state in the table thus leads to an error. But if we check up the base case first, we simple return it which takes O(1) time and we don't have to store it.

Thus, in general, it's safer to check base case first and there is no necessity to save the base case in the table. After checking base case, we are sure current state will be a legal state and then we look up the table next.
 */

#define maxN 210
#define maxM 12
#define maxD 22
int table[maxN][maxD][maxM];
int a[maxN];

int recurse(int i, int j, int k, const int d){
    if(k == 0){
        if(j == 0)  return 1;
        else return 0;
    }
    if(i < 0){ return 0; }
    if(table[i][j][k] != -1)    return table[i][j][k];

    int next = ((j + a[i])%d + d) % d;
    table[i][j][k] = recurse(i-1, j, k, d) + recurse(i-1, next, k-1, d);
    return table[i][j][k];
}


int main(){ _
    int N, Q, count = 0;
    while(cin >> N >> Q){
        if(N == 0 && Q == 0)    break;

        cout << "SET " << ++count << ":" << endl;
        for(int i = 0; i < N; ++i)  cin >> a[i];

        int D, M, ans;
        for(int i = 0; i < Q; ++i){
            cin >> D >> M;
            memset(table, -1, sizeof table);
            ans = recurse(N-1, 0, M, D);
            cout << "QUERY " << i+1 << ": " << ans << endl;
        }
    }
    return 0;
}
