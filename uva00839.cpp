#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

bool process(int64& wl, int64 dl, int64& wr, int64 dr){
    cin >> wl >> dl >> wr >> dr;
    bool valid = true;
    if(wl == 0){
        int64 wll, wlr;
        valid = process(wll, 0, wlr, 0) && valid;
        wl = wll + wlr;
    }

    if(wr == 0){
        int64 wrl, wrr;
        valid = process(wrl, 0, wrr, 0) && valid;
        wr = wrl + wrr;
    }

    valid = (wl * dl == wr * dr) && valid;
    return valid;
}

int main(){ _
    int tc; cin >> tc;
    while(tc--){
        int64 dummy1, dummy2;
        bool valid = process(dummy1, 0, dummy2, 0);
        if(valid)   cout << "YES" << endl;
        else    cout << "NO" << endl;
        if(tc)  cout << endl;
    }
    return 0;
}
