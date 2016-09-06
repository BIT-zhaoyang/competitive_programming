#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
    int TC; cin >> TC;
    for(int tc = 1; tc <= TC; ++tc){
        int n, m;   cin >> n >> m;
        vector< vector<int> > AdjMat(n, vector<int> (n, BIGINT));
        for(int i = 0; i < n; ++i)  AdjMat[i][i] = 0;

        int u, v;
        for(int i = 0; i < m; ++i){
            cin >> u >> v;
            AdjMat[u][v] = AdjMat[v][u] = 1;
        }

        for(int k = 0; k < n; ++k)
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);

        cin >> u >> v;
        int ans = 0;
        for(int i = 0; i < n; ++i)
            ans = max(ans, AdjMat[u][i] + AdjMat[v][i]);
        cout << "Case " << tc <<": " << ans << endl;
    }
    return 0;
}
