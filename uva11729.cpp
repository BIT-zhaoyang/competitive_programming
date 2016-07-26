#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

#define B first
#define J second

bool mycomp(pair<int, int> &x, pair<int, int> &y){
    int c1 = max(x.B + x.J, x.B + y.B + y.J);
    int c2 = max(y.B + y.J, y.B + x.B + x.J);

    if(c1 < c2) return true;
    else    return false;
}

int main(){ _
    int n, count = 0;
    while(cin >> n){
        if(n == 0)  break;
        cout << "Case " << ++count << ": ";

        vector< pair<int, int> > pii(n);
        for(int i = 0; i < n; ++i)  cin >> pii[i].first >> pii[i].second;

        sort(pii.begin(), pii.end(), mycomp);

        int ans = 0, tB = 0;
        for(int i = 0; i < n; ++i){
            tB += pii[i].B;
            ans = max(tB + pii[i].J, ans);
        }

        cout << ans << endl;
    }
    return 0;
}
