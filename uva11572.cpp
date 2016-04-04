#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <climits>
#include <cmath>
#include <set>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);

using namespace std;

int main(){ _
    int T; cin >> T;
    while(T--){
        int N;  cin >> N;
        int longest = 0;

        int tail = 0;     // tail -> head
        map<int, int> mii;
        map<int, int>::iterator it;
        int num;
        for(int i = 0; i < N; ++i){     // i functions as head pointer
            cin >> num;
            it = mii.find(num);

            // if we have found a duplicate num, then tail should be set to the next element of
            // the duplicate num. What's more, the duplicate num should be ahead of current tail
            // that's why we need max(mii[num] + 1, tail);
            if(it != mii.end())    tail = max(mii[num] + 1, tail);

            // if we found duplicate num, we update it
            // if not found, we insert it.
            // no matter we found or not, we can use the same expression to make the action
            mii[num] = i;

            // get new longest if exists
            longest = max(longest, i-tail+1);
        }
        cout << longest << endl;
    }
    return 0;
}
