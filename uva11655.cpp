#include <bits/stdc++.h>
#define UNVISITED -1
#define BIGINT 1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

/*
Hmmm.... Though the problem description is a bit unclear, this is a delicate constructed problem. If I don't know it is a DAG problem, I probably won't recognize it. Even I know it's a DAG problem, it took me a day to think about the logic of the solution.

The number of paths to go through a node 'u' equals, the number of path to go from 1->L through u multiple the number of path to go from L->1 through u if edges are reversed.
*/

vector< vector<int> > onward, backward;
vector<int> topoSort;
vector<int64> nOnwardPath, nBackPath;
vector<bool> visited;
const int MOD = 100000;

void dfs(int u, vector< vector<int> > &AdjList){
    visited[u] = true;
    for(int j = 0; j < AdjList[u].size(); ++j){
        int v = AdjList[u][j];
        if(!visited[v])
            dfs(v, AdjList);
    }
    topoSort.push_back(u);
}

int main(){ _
    int TC; cin >> TC;
    for(int tc = 1; tc <= TC; ++tc){
        cout << "Case " << tc << ": ";
        int n, m;   cin >> n >> m;
        onward.assign(n + 1, vector<int> (0));
        backward.assign(n + 1, vector<int> (0));
        nOnwardPath.assign(n + 1, 0);
        nBackPath.assign(n + 1, 0);
        visited.assign(n + 1, false);
        topoSort.clear();

        for(int i = 0; i < m; ++i){
            int u, v;   cin >> u >> v;
            onward[u].push_back(v);
            backward[v].push_back(u);
        }

        // topological sort
        dfs(1, onward);

        // compute number of paths going in onward direction
        nOnwardPath[1] = 1;
        for(int i = topoSort.size() - 1; i >= 0; --i){
            int u = topoSort[i];
            for(int j = 0; j < onward[u].size(); ++j){
                int v = onward[u][j];
                nOnwardPath[v] += nOnwardPath[u];
                nOnwardPath[v] %= MOD;
            }
        }

        // compute number of paths going in backward direction
        nBackPath[n] = 1;
        for(int i = 0; i < topoSort.size(); ++i){
            int u = topoSort[i];
            for(int j = 0; j < backward[u].size(); ++j){
                int v = backward[u][j];
                nBackPath[v] += nBackPath[u];
                nBackPath[v] %= MOD;
            }
        }

        int64 total = 0;
        for(int i = 2; i <= n; ++i){
            // The following multiplication may lead to overflow of int, so we need
            // to use int64
            total += nOnwardPath[i] * nBackPath[i];
            total %= MOD;
        }
        cout << total << " " << nOnwardPath[n] << endl;
    }
    return 0;
}
