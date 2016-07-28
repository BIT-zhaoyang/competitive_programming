#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

vector< vector< ii > > AdjList;
priority_queue< ii, vector< ii >, greater< ii > > pq;
vector<int> dist;

void dijkstra(int source){
    pq.push(ii(0, source));
    dist[source] = 0;

    while(!pq.empty()){
        ii p = pq.top();  pq.pop();
        int u = p.second, d1 = p.first;
        if(d1 > dist[u]) continue;

        for(int i = 0; i < AdjList[u].size(); ++i){
            ii q = AdjList[u][i];
            int v = q.first, d2 = q.second;
            if(dist[u] + d2 < dist[v]){
                dist[v] = dist[u] + d2;
                pq.push(ii(dist[v], v));
            }
        }
    }
}

int main(){ _
    int tc; cin >> tc;
    while(tc--){
        int n, e, m, t;    cin >> n >> e >> t >> m;
        AdjList.assign(n+1, vector<ii> (0));
        dist.assign(n+1, INT_MAX);

        int u, v, w;
        for(int i = 0; i < m; ++i){
            cin >> u >> v >> w;
            AdjList[v].push_back(ii(u, w));
        }

        dijkstra(e);

        int ans = 0;
        for(int i = 1; i <= n; ++i){
            if(dist[i] <= t) ++ans;
        }
        cout << ans << endl;

        if(tc)  cout << endl;
    }
    return 0;
}
