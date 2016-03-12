#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <climits>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);

using namespace std;

int main(){ _
    int n, q, counter = 1;
    while(cin >> n, n != 0){
        vector<int> vi1(n, 0);
        for(int i = 0; i < n; ++i)  cin >> vi1[i];
        sort(vi1.begin(), vi1.end());

        cin >> q;
        vector<int> vi2(q, 0);
        for(int i = 0; i < q; ++i) cin >> vi2[i];

        cout << "Case " << counter++ << ":" << endl;
        for(int i = 0; i < q; ++i){
            cout << "Closest sum to " << vi2[i] << " is ";
            int best_sum = 0, best_abs = INT_MAX, s = 0, e = n-1, query = vi2[i];
            int sum = 0;
            while(s < e){
                sum = vi1[s] + vi1[e];
                if(abs(sum - query) < best_abs){
                    best_abs = abs(sum - query);
                    best_sum = sum;
                }

                if(sum > query) --e;
                else if(sum < query) ++s;
                else if(sum == query) break;
            }
            cout << best_sum << "." << endl;
        }
    }

    return 0;
}
