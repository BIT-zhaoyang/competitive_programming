#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

int main(){ _
    int tc; cin >> tc;
    while(tc--){
        int D, I;   cin >> D >> I;

        // same idea but runs slow
        // find the path consisting of the status of the nodes that the ball visited in the last traverse
        // vector<int> path(D, 0);
        // for(int i = 0; i < D; ++i){
        //     int nRound = (I + pow(2, i)-1) / pow(2, i);
        //     int val = nRound % 2;
        //     path[i] = val;
        // }
        //
        // based on this path we can determine the path of the ball
        // int curr, origin = 0, at = 1;
        // for(int i = 0; i < path.size()-1; ++i){ // don't have to consider the last statu
        //     curr = path[i], origin = 1 - curr;
        //     if(origin == 0) at = 2*at;
        //     else    at = 2*at + 1;
        // }

        // faster solution
        // 'I' has a special correspondence to the path status
        // 'I' is like a reverse binary representation of the path.
        // In normal binary representation, 0 is 00000, but here, 0 is 11111. Then 1 is 00001 but here, 1 is 11110, etc
        --I;
        int at = 1;
        for(int i = 0; i < D-1; ++i){
            if(I & (1 << i))    at = 2*at + 1;
            else    at *= 2;
        }

        cout << at << endl;
    }

    cin >> tc;  // read the -1
    return 0;
}
