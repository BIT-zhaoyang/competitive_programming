#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define POS_INF 1 << 28
#define NEG_INF -1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
    int tc; cin >> tc;
    while(tc--){
        int n = 10, m;
        string line;    cin >> line;
        m = line.size() - 2;
        vector<int> vi(m, 0);
        for(int i = 0; i < 8; ++i){
            char ch;    cin >> ch;
            for(int j = 0; j < m; ++j){
                cin >> ch;
                if(ch == '\\')
                    vi[j] += (1 << i);
            }
            cin >> ch;
        }
        cin >> line;
        for(int i = 0; i < m; ++i)
            cout << char(vi[i]);
        cout << endl;
    }
    return 0;
}
