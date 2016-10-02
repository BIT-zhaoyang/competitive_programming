#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

stack<int> si;
vector<int> value, dist;
vector< vector<int> > AdjList;

void topoSort(int u){
    dist[u] = value[u];
    for(int i = 0; i < AdjList[u].size(); ++i){
        int v = AdjList[u][i];
        if(dist[v] == UNVISITED)
            topoSort(v);
    }
    si.push(u);
}

void dijkstra(int u){
    dist[u] = value[u];
    priority_queue< ii > pq;
    pq.push(ii(dist[u], u));

    while(!pq.empty()){
        int u = pq.top().second, d1 = pq.top().first;
        pq.pop();
        if(d1 < dist[u])    continue;
        for(int i = 0; i < AdjList[u].size(); ++i){
            int v = AdjList[u][i], d2 = value[v];
            if(dist[u] + d2 > dist[v]){
                dist[v] = dist[u] + d2;
                pq.push(ii(dist[v], v));
            }
        }
    }
}

int main(){ _
    int tc; cin >> tc;
    while(tc--){
        int n, k;   cin >> n >> k;
        value.assign(n * n, 0);
        dist.assign(n * n, UNVISITED);
        AdjList.assign(n * n, vector<int> (0));

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                cin >> value[i*n + j];

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j){
                for(int r = max(0, i - k); r < min(n, i + k + 1); ++r)
                    if(value[i*n + j] < value[r*n + j])
                        AdjList[i*n + j].push_back(r*n + j);

                for(int c = max(0, j - k); c < min(n, j + k + 1); ++c)
                    if(value[i*n + j] < value[i*n + c])
                        AdjList[i*n + j].push_back(i*n + c);
            }

        // topoSort
        topoSort(0);

        int ans = 0;
        while(!si.empty()){
            int u = si.top();   si.pop();
            ans = max(ans, dist[u]);
            for(int i = 0; i < AdjList[u].size(); ++i){
                int v = AdjList[u][i];
                dist[v] = max(dist[v], dist[u] + value[v]);
            }
        }

        cout << ans << endl;
        if(tc)  cout << endl;

        // we can also use dijkstra since the starting point is only at (0, 0)
        // dijkstra(0);
        // int ans = 0;
        // for(int i = 0; i < n * n; ++i)  ans = max(ans, dist[i]);
        // cout << ans << endl;
        // if(tc)  cout << endl;
    }
    return 0;
}
