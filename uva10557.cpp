#include <bits/stdc++.h>
#define UNVISITED -1
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

/* A really really good problem. Bellman-Ford and Faster SSSP can only detect if a negative/positive cycle exists. Bellman-Ford may make it easier to find the points on these circles.

However, in this problem, knowing there is a negative/positive cycle is not enough. A cycle exists doesn't mean the shortes distance to the destination is well defined. There may be no path to the destination point, or the destination is not connected to the cycle. Only in these two situations, the shortest distance to the destination makes sense!
*/

int n;
vector<int> energy, remain;
vector< vector<int> > AdjList;
vector<bool> visited;

void bfs(queue<int> &Q){
    int u, v;
    while(!Q.empty()){
        u = Q.front();  Q.pop();
        visited[u] = true;
        for(int i = 0; i < AdjList[u].size(); ++i){
            v = AdjList[u][i];
            if(!visited[v]) Q.push(v);
        }
    }
}


int main(){ _
    while(cin >> n){
        if(n == -1) break;
        energy.assign(n+1, 0);
        remain.assign(n+1, INT_MIN);
        AdjList.assign(n+1, vector<int> (0));

        int m, v;
        for(int i = 1; i <= n; ++i){
            cin >> energy[i] >> m;
            for(int j = 0; j < m; ++j){
                cin >> v;
                AdjList[i].push_back(v);
            }
        }

        remain[1] = 100;
        for(int i = 0; i < n - 1; ++i){
            for(int u = 1; u <= n; ++u){
                if(remain[u] <= 0)  continue;
                for(int j = 0; j < AdjList[u].size(); ++j){
                    v = AdjList[u][j];
                    remain[v] = max(remain[v], remain[u] + energy[v]);
                }
            }
        }

        if(remain[n] >= 0){
            cout << "winnable" << endl;
            continue;
        }

        // find points on the positive circle
        queue<int> circle;
        for(int u = 1; u <= n; ++u){
            if(remain[u] <= 0)  continue;
            for(int j = 0; j < AdjList[u].size(); ++j){
                v = AdjList[u][j];
                if(remain[u] + energy[v] > remain[v]){
                    circle.push(v);
                    remain[v] = remain[u] + energy[v];
                }
            }
        }

        // These circles are reachable from the start point, next we have to
        // check if the finish point is reachable starting from these circles
        visited.assign(n+1, false);
        bfs(circle);
        if(visited[n])  cout << "winnable" << endl;
        else    cout << "hopeless" << endl;
    }
    return 0;
}
