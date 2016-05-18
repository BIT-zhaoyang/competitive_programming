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
    vector<int> vi(10010, INT_MAX);
    vi[0] = 0; vi[1] = 1;  vi[2] = 2;
    for(int i = 3; i < vi.size(); ++i){
        for(int j = 1; j <= int(sqrt(i)); ++j){
            vi[i] = min(vi[i], 1 + vi[i- j*j]);
        }
    }

    int t, input;  cin >> t;
    while(t--){
        cin >> input;
        cout << vi[input] << endl;
    }
    return 0;
}
