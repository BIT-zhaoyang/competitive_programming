#include <bits/stdc++.h>
#define UNVISITED -1
#define BIGINT 1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
    int n, tc = 0;
    while(cin >> n, n){
        vector<string> names(n, "");
        map<string, int> s2i;
        vector< vector<double> > change(n, vector<double> (n, 0.0));

        string stru, strv;
        int u, v;
        double ratio;
        for(int i = 0; i < n; ++i){
            cin >> names[i];
            s2i[names[i]] = i;
        }

        int m;  cin >> m;
        for(int i = 0; i < m; ++i){
            cin >> stru >> ratio >> strv;
            u = s2i[stru], v = s2i[strv];
            change[u][v] = ratio;
        }

        for(int k = 0; k < n; ++k)
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    change[i][j] = max(change[i][j], change[i][k] * change[k][j]);

        bool ans = false;
        for(int i = 0; i < n; ++i)
            ans = ans | (change[i][i] > 1.0);

        cout << "Case " << ++tc << ": " << (ans ? "Yes" : "No") << endl;
    }
    return 0;
}
