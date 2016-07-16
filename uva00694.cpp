#include <algorithm>
#include <bitset>
#include <cstring>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <sstream>
#include <vector>

#define UNVISITED -1
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
    int tc = 0, ans;
    int64 A, L;
    while(cin >> A >> L){
        if(A == -1 && L == -1)  break;
        cout << "Case " << ++tc << ": A = " << A << ", limit = " << L << ", number of terms = ";
        ans = 0;
        while(A != 1 && A <= L){
            ++ans;
            if(A % 2)   A = 3*A + 1;
            else    A /= 2;
        }
        if(A == 1)  ++ans;
        cout << ans << endl;
    }
    return 0;
}
