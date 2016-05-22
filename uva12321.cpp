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
    int L, G;
    while(cin >> L >> G){
        if(L + G == 0)  break;

        vector< pair<int, int> > vii(G);
        int x, r;
        for(int i = 0; i < G; ++i){
            cin >> x >> r;
            vii[i].first = x-r;
            vii[i].second = x + r;
        }
        sort(vii.begin(), vii.end());

        int tail = 0, rightmost = 0, count = 0;
        for(int i = 0; i < G; ++i){
            if(vii[i].first <= tail)    rightmost = max(rightmost, vii[i].second);
            else{
                tail = rightmost;
                ++count;
                if(vii[i].first <= tail)    rightmost = max(rightmost, vii[i].second);
                else    break;
            }
            if(rightmost >= L){
                cout << G - count - 1 << endl;
                break;
            }
        }

        if(rightmost < L)   cout << -1 << endl;
    }
    return 0;
}
