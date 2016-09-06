#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
    int N, M, tc = 0;
    while (cin >> N >> M) {
        if(N == 0)  break;
        vector<string> names(N, "");
        for(int i = 0; i < N; ++i)  cin >> names[i];

        int u, v, d;
        vector< vector<int> > AdjMat(N, vector<int> (N, BIGINT));
        for(int i = 0; i < N; ++i)  AdjMat[i][i] = 0;
        for(int i = 0; i < M; ++i){
            cin >> u >> v >> d;
            --u, --v;
            AdjMat[v][u] = AdjMat[u][v] = min(AdjMat[u][v], d);
        }

        for(int k = 0; k < N; ++k)
            for(int i = 0; i < N; ++i)
                for(int j = 0; j < N; ++j)
                    AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);

        int best = BIGINT, dist = 0, ans = -1;
        for(int i = 0; i < N; ++i){
            dist = 0;
            for(int j = 0; j < N; ++j)
                dist += AdjMat[i][j];
            if(dist < best){
                best = dist;
                ans = i;
            }
        }

        cout << "Case #" << ++tc << " : " << names[ans] << endl;
    }
    return 0;
}
