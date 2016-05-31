#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

int main(){ _
    int TC; cin >> TC;
    for(int tc = 1; tc <= TC; ++tc){
        int N, P, Q;    cin >> N >> P >> Q;

        int total_weight = 0, weight = 0, ans = 0;
        for(int i = 0; i < N; ++i){
            cin >> weight;
            if(i < P && total_weight + weight <= Q){
                total_weight += weight;
                ans = i + 1;
            }
        }

        cout << "Case " << tc << ": " << ans << endl;
    }
    return 0;
}
