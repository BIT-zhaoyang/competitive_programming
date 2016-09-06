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
        int L, D;   cin >> L >> D;
        vector< vector<int> > AdjMat(L+1, vector<int> (L+1, BIGINT));
        for(int i = 0; i <= L; ++i) AdjMat[i][i] = 0;

        int U, V, C;
        for(int i = 0; i < D; ++i){
            cin >> U >> V >> C;
            AdjMat[U][V] = AdjMat[V][U] = min(AdjMat[U][V], C);
        }

        // floyd-warshall
        for(int k = 1; k <= L; ++k)
            for(int i = 1; i <= L; ++i)
                for(int j = 1; j <= L; ++j)
                    AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);

        // find the rally point
        vector<int> rally;
        for(int i = 1; i <= L; ++i){
            bool success = true;
            for(int j = 1; j <=4; ++j)
                if(AdjMat[i][j] != AdjMat[i][j+1] || AdjMat[i][j] == BIGINT)
                    success = false;
            if(success)
                rally.push_back(i);
        }

        int ans = -1, dist = BIGINT;
        for(int i = 0; i < rally.size(); ++i){
            int u = rally[i], d = 0;
            for(int v = 1; v <= L; ++v)
                d = max(d, AdjMat[u][v]);
            if(d < dist){
                dist = d;
                ans = u;
            }
        }

        cout << "Map " << tc << ": ";
        if(ans != -1)   cout << dist << endl;
        else    cout << -1 << endl;
    }
    return 0;
}
