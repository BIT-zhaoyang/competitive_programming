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
    int n;
    vector<int> vi(5, 0);
    while(cin >> n){
        if(n == 0)  break;
        map<string, int> conformity;

        int mostPopular = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < 5; ++j)  cin >> vi[j];
            sort(vi.begin(), vi.end());

            string str("");
            for(int j = 0; j < 5; ++j)  str += to_string(vi[j]);
            conformity[str] += 1;
            mostPopular = max(mostPopular, conformity[str]);
        }

        int ans = 0;
        for(map<string, int>::iterator it = conformity.begin(); it != conformity.end(); ++it){
            if(it->second == mostPopular)   ans += mostPopular;
        }
        cout << ans << endl;
    }
    return 0;
}
