#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
    int tc; cin >> tc;
    while(tc--){
        int n, m;   cin >> n >> m;
        vector< vector< ii > > AdjMat(n+1, vector< ii > (n+1, ii(BIGINT, BIGINT)));

        int u, v, d, t;
        for(int i = 0; i < m; ++i){
            cin >> u >> v >> t >> d;
            if(t < AdjMat[u][v].first)
                AdjMat[u][v] = AdjMat[v][u] = ii(t, d);
            else if(t == AdjMat[u][v].first)
                AdjMat[u][v].second = AdjMat[v][u].second = min(AdjMat[u][v].second, d);
        }

        for(int i = 0; i <= n; ++i)
            AdjMat[i][i] = ii(0, 0);


        for(int k = 1; k <= n; ++k)
            for(int i = 1; i <= n; ++i)
                for(int j = 1; j <= n; ++j){
                    if(AdjMat[i][k].first + AdjMat[k][j].first < AdjMat[i][j].first){
                        AdjMat[i][j].first = AdjMat[i][k].first + AdjMat[k][j].first;
                        AdjMat[i][j].second = AdjMat[i][k].second + AdjMat[k][j].second;
                    } else if(AdjMat[i][k].first + AdjMat[k][j].first == AdjMat[i][j].first){
                        AdjMat[i][j].second = min(AdjMat[i][j].second,
                                                AdjMat[i][k].second + AdjMat[k][j].second);
                    }
                }

        int q;  cin >> q;
        for(int i = 0; i < q; ++i){
            cin >> u >> v;
            if(AdjMat[u][v].first != BIGINT)
                cout << "Distance and time to reach destination is " << AdjMat[u][v].second
                     << " & " << AdjMat[u][v].first << "." << endl;
            else
                cout << "No Path." << endl;
        }

        if(tc)  cout << endl;
    }
    return 0;
}
