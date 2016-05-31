#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

bool mycomp(int a, int b){
    return a > b;
}

int main(){ _
    int TC; cin >> TC;
    while(TC--){
        int n;  cin >> n;
        vector<int> vi(n, 0);
        for(int i = 0; i < n; ++i)  cin >> vi[i];
        sort(vi.begin(), vi.end(), mycomp);

        int ans = 0;
        for(int i = 2; i < n; i += 3){
            ans += vi[i];
        }

        cout << ans << endl;
    }
    return 0;
}
