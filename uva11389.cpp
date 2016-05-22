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

int main(){ _
    int n, d, r;
    while(cin >> n >> d >> r){
        if(n + d + r == 0)  break;
        vector<int> morning(n, 0), evening(n, 0);
        for(int i = 0; i < n; ++i)
            cin >> morning[i];
        for(int i = 0; i < n; ++i)
            cin >> evening[i];

        sort(morning.begin(), morning.end());
        sort(evening.begin(), evening.end());

        int extra = 0;
        for(int i = 0; i < n; ++i){
            int j = n-1 - i;
            extra += max(0, morning[i] + evening[j] - d) * r;
        }
        cout << extra << endl;
    }
    return 0;
}
