#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int n, m;
vector< vector<int> > AdjMat;
vector<int> vertice, visited;

int main(){ _
    while(cin >> n){
        AdjMat.assign(n+1, vector<int> (n+1, BIGINT));

        cin.ignore();
        for(int u = 1; u <= n; ++u){
            string line;
            getline(cin, line);
            stringstream ss;
            ss << line;
            int v;
            while(ss >> v)  AdjMat[u][v] = AdjMat[v][u] = 1;
        }

        for(int k = 1; k <= n; ++k)
            for(int i = 1; i <= n; ++i)
                for(int j = 1; j <= n; ++j)
                        AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);

        cin >> m;
        cin.ignore();
        for(int q = 0; q < m; ++q){
            string line;
            getline(cin, line);
            stringstream ss;
            ss << line;
            vertice.assign(n+1, false);
            visited.assign(n+1, false);
            int v;
            while(ss >> v)  vertice[v] = visited[v] = true;

            /* The idea is that, through each pair (i, j) of vertice from the selected vertices, iterate through every non-selected vertex k. If AdjMat[i][k] + AdjMat[k][j] == AdjMat[i][j], then it means there could be a shortest path from i to j through k. */

            for(int i = 0; i < vertice.size(); ++i){
                if(!vertice[i]) continue;   // if if(!vertice[i]), then i is no selected, continue
                for(int j = i + 1; j < vertice.size(); ++j){
                    if(!vertice[j]) continue; // if j is not selected, continue
                    for(int k = 1; k <= n; ++k){
                        if(vertice[k])  continue; // if k IS selected, continue
                        if(AdjMat[i][k] + AdjMat[k][j] == AdjMat[i][j]) visited[k] = true;
                    }
                }
            }

            bool ans = true;
            for(int i = 1; i <= n; ++i)
                ans = ans & visited[i];
            cout << (ans ? "yes" : "no") << endl;
        }
    }
    return 0;
}
