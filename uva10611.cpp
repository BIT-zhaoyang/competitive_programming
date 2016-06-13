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

typedef long long int64;

int64 lower_bound(vector<int> &vi, int height){
    if(height > vi.back())  return vi.size();

    int64 lo = 0, hi = vi.size() - 1, mid;
    while(lo < hi){
        mid = (lo + hi) / 2;
        if(vi[mid] < height)    lo = mid + 1;
        else    hi = mid;
    }
    return lo;
}

int64 upper_bound(vector<int> &vi, int height){
    if(height > vi.back())  return -1;

    int64 lo = 0, hi = vi.size() - 1, mid;
    while(lo < hi){
        mid = (lo + hi) / 2;
        if(vi[mid] <= height)   lo = mid+1;
        else    hi = mid;
    }
    return lo;
}

int main(){ _
    int N;  cin >> N;
    vector<int> vi(N, 0);
    for(int i = 0; i < N; ++i)  cin >> vi[i];

    int Q, h;   cin >> Q;
    int64 L, R;
    while(Q--){
        cin >> h;
        L = lower_bound(vi, h);
        R = upper_bound(vi, h);

        if(L == 0)   cout << "X ";
        else    cout << vi[L-1] << " ";

        if(R == -1) cout << "X" << endl;
        else    cout << vi[R] << endl;
    }
    return 0;
}
