#include <bits/stdc++.h>
#define UNVISITED -1
#define BIGINT 1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

vector<int> topo, ans;
vector<bool> visited;
vector< vector<int> > AdjList;

void dfs(int u){
    // modified dfs for topological sort
    visited[u] = true;
    for(int i = 0; i < AdjList[u].size(); ++i){
        int v = AdjList[u][i];
        if(!visited[v])
            dfs(v);
    }
    topo.push_back(u);
}

int main(){ _
    int n;
    while(cin >> n){
        if(n == 0)  break;
        topo.clear();
        ans.assign(n + 1, 0);
        visited.assign(n + 1, false);
        AdjList.assign(n + 1, vector<int> (0));
        for(int i = 1; i <= n; ++i){
            int m;  cin >> m;
            for(int j = 0; j < m; ++j){
                int depend; cin >> depend;
                AdjList[i].push_back(depend);
            }
        }

        for(int i = 1; i <= n; ++i){
            if(!visited[i])
                dfs(i);
        }

        for(int i = 0; i < topo.size(); ++i){
            int u = topo[i];
            for(int j = 0; j < AdjList[u].size(); ++j){
                int v = AdjList[u][j];
                ans[u] = max(ans[u], 1 + ans[v]);
            }
        }

        int maxDepend = 0, id = -1;
        for(int i = 1; i <= n; ++i){
            if(ans[i] > maxDepend){
                maxDepend = ans[i];
                id = i;
            }
        }

        cout << id << endl;
    }
    return 0;
}
