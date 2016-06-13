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

int binarySearch(vector<int> &vi, int target){
    int lo = 0, hi = vi.size()-1, mid;
    while(lo < hi){
        mid = (lo + hi) / 2;
        if(vi[mid] < target){
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }

    if(vi[lo] == target)    return lo;
    else    return -1;
}

int main(){ _
    int N, Q, tc = 0;
    while(cin >> N >> Q){
        if(N + Q == 0)  break;

        cout << "CASE# " << ++tc << ":" << endl;
        vector<int> vi(N, 0);
        for(int i = 0; i < N; ++i){
            cin >> vi[i];
        }
        sort(vi.begin(), vi.end());

        int target, idx;
        for(int i = 0; i < Q; ++i){
            cin >> target;
            idx = binarySearch(vi, target);
            if(idx == -1)   cout << target << " not found" << endl;
            else  cout << target << " found at " << ++idx << endl;
        }
    }

    // cout <<"get here" << endl;
    return 0;
}
