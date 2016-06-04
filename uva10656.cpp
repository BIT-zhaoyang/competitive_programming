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
#include <queue>
#include <stack>

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

/* What a dummy.... silly.... boring.... problem..... */

int main(){ _
    int n;
    while(cin >> n){
        if(n == 0)  break;

        vector<int> vi;
        int val;
        for(int i = 0; i < n; ++i){
            cin >> val;
            if(val > 0) vi.push_back(val);
        }

        if(vi.empty())  cout << 0 << endl;
        else{
            for(int i = 0; i < vi.size(); ++i){
                if(i)   cout << " ";
                cout << vi[i];
            }
            cout << endl;
        }
    }
    return 0;
}
