#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
    int tc; cin >> tc;
    while(tc--){
        int h, id1, id2;
        cin >> h >> id1 >> id2;
        int total = (1 << h) - 1;
        int lower = max(id1, id2);
        int layer = log2(lower);
        int diffH = h - layer;
        int overlap = ((1 << diffH) - 1) - 1;
        cout << total - overlap << endl;
    }
    return 0;
}
