#include <bits/stdc++.h>
#define UNVISITED -1
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

vector<int> busy, cost;
vector< vector<int> > AdjList;
vector<bool> visited;

void bfs(queue<int> &circle){
    int u, v;
    while(!circle.empty()){
        u = circle.front();  circle.pop();
        visited[u] = true;
        for(int i = 0; i < AdjList[u].size(); ++i){
            v = AdjList[u][i];
            if(!visited[v])     circle.push(v);
        }
    }
}

int main(){ _
    int n, tc = 0;
    while(cin >> n){
        busy.assign(n+1, 0);
        cost.assign(n+1, INT_MAX);
        AdjList.assign(n+1, vector<int> (0));
        for(int i = 1; i <= n; ++i) cin >> busy[i];

        int m, u, v;  cin >> m;
        for(int i = 0; i < m; ++i){
            cin >> u >> v;
            AdjList[u].push_back(v);
        }

        cost[1] = 0;
        for(int iter = 0; iter < n - 1; ++iter){
            for(int u = 1; u <= n; ++u){
                if(cost[u] == INT_MAX)  continue;
                for(int i = 0; i < AdjList[u].size(); ++i){
                    v = AdjList[u][i];
                    cost[v] = min(cost[v], cost[u] + (int)pow(busy[v] - busy[u], 3));
                }
            }
        }

        queue<int> circle;
        for(int u = 1; u <= n; ++u){
            if(cost[u] == INT_MAX)  continue;
            for(int i = 0; i < AdjList[u].size(); ++i){
                v = AdjList[u][i];
                if(cost[u] + (int)pow(busy[v] - busy[u], 3) < cost[v]){
                    circle.push(v);
                }
            }
        }

        visited.assign(n+1, false);
        bfs(circle);

        cout << "Set #" << ++tc << endl;
        int nq, q; cin >> nq;
        for(int i = 0; i < nq; ++i){
            cin >> q;
            if(visited[q] || cost[q] < 3 || cost[q] == INT_MAX)   cout << "?" << endl;
            else    cout << cost[q] << endl;
        }
    }
    return 0;
}
