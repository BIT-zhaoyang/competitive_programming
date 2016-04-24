/*
    The difference between this problem and the schedule problem described in CLRS is that this problem wants to find the minimum subset while the schedule problem wants to find the maximum subset.

    This difference makes us to do the trick showed in line 41-49.
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);

using namespace std;

int main(){ _
    int n;
    double l, w;
    while(cin >> n, !cin.eof()){
        cin >> l >> w;
        vector<pair<double, double> > vii(n);
        double center, rad, left, right, diff;
        for(int i = 0; i < n; ++i){
            cin >> center >> rad;
            if(rad < w/2){
                left = -1e9;
                right = -1e9;
            } else {
                diff = sqrt(rad*rad - w*w/4);
                left = center - diff;
                right = center + diff;
            }
            vii[i].first = left;
            vii[i].second = right;
        }

        sort(vii.begin(), vii.end());
        // for(int i = 0; i < n; ++i){
        //     cout << vii[i].first << "\t" << vii[i].second << endl;
        // }

        double last = 0.0, longest = 0;
        int count = 0; bool possible = true;
        for(int i = 0; i < n; ++i){
            if(vii[i].first > last){
                ++count;
                last = longest;
                // one possible fail case is there is no connect between two consequtive sprinkles
                if(vii[i].first > last){
                    possible = false;
                    break;
                }
            }

            longest = max(longest, vii[i].second);

            // in corner cases, the sprinkle may be placed outside the grass but it wil reach the right end of the grass. If we don't break when we reach the right end of the grass, we have elongated the grass implicitly.
            if(longest >= l)    break;
        }

        // another fail case is the furthest covered place can't reach the right end of the grass
        if(longest < l || !possible){
            cout << "-1" << endl;
        } else {
            // When the for loop terminates, we haven't consider the sprinkle represented by the longest
            cout << count + 1 << endl;
        }

    }
    return 0;
}
