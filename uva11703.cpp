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
    vector<int> vi(1000001, 0);
    vi[0] = 1;
    for(int i = 1; i < vi.size(); ++i){
        vi[i] = vi[int(i - sqrt(i))] + vi[int(i*sin(i)*sin(i))] + vi[int(log(i))];
        vi[i] %= 1000000;
    }

    int i;
    while(cin >> i){
        if(i == -1) break;
        cout << vi[i] << endl;
    }
    return 0;
}
