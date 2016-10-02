#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

stack<int> si;
vector<int> dist;
vector< vector< int> > AdjList;

void topoSort(int u){
    dist[u] = 0;
    for(int i = 0; i < AdjList[u].size(); ++i){
        int v = AdjList[u][i];
        if(dist[v] == UNVISITED)
            topoSort(v);
    }
    si.push(u);
}

int main(){ _
    int n, start, tc = 0;
    while(cin >> n){
        if(n == 0)  break;
        AdjList.assign(n + 1, vector<int> (0));
        dist.assign(n+1, UNVISITED);
        cin >> start;

        int u, v;
        while(cin >> u >> v){
            if(u == 0)  break;
            AdjList[u].push_back(v);
        }

        // topo sort
        // since we know the start point and the graph is fully connected
        // we can start topoSort at only 'start'
        topoSort(start);

        while(!si.empty()){
            u = si.top();   si.pop();
            for(int i = 0; i < AdjList[u].size(); ++i){
                v = AdjList[u][i];
                dist[v] = max(dist[v], dist[u] + 1);
            }
        }

        int ans = 1;
        for(int i = 1; i <= n; ++i)
            if(dist[i] > dist[ans])
                ans = i;

        cout << "Case " << ++tc << ": The longest path from " << start << " has length ";
        cout << dist[ans] << ", finishing at " << ans << "." << endl << endl;

    }
    return 0;
}
