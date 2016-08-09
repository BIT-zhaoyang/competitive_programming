#include <bits/stdc++.h>
#define UNVISITED -1
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

/* The problem description is shit. Correct statement:
You receive a directed, weighted graph. Two nodes are defined as source (s) and sink (t), and you also receive a number p which denotes a “cost limit”. You have to find the heaviest edge inside any valid path between the source and the sink; a path is valid if its total cost doesn’t exceed p.
ref: http://lbv-pc.blogspot.fi/2012/10/highest-paid-toll.html
*/
#define BIG_VALUE 10000000
vector<int> dist0, dist1;
vector< vector< ii > > G, R;
priority_queue<ii, vector< ii >, greater< ii > > pq;

void dijkstra(int source, vector<int> &dist, vector< vector< ii > > &AdjList){
    dist[source] = 0;
    pq.push(ii(dist[source], source));

    int u, v, d1, d2;
    while(!pq.empty()){
        u = pq.top().second;    d1 = pq.top().first;
        pq.pop();
        if(d1 > dist[u])    continue;
        for(int i = 0; i < AdjList[u].size(); ++i){
            v = AdjList[u][i].first;    d2 = AdjList[u][i].second;
            if(d1 + d2 < dist[v]){
                dist[v] = d1 + d2;
                pq.push(ii(dist[v], v));
            }
        }
    }
}

int main(){ _
    int tc; cin >> tc;
    while(tc--){
        int N, M, s, t, p;
        cin >> N >> M >> s >> t >> p;

        G.assign(N+1, vector< ii > (0));
        R.assign(N+1, vector< ii > (0));
        dist0.assign(N + 1, BIG_VALUE);
        dist1.assign(N + 1, BIG_VALUE);

        int u, v, w;
        for(int i = 0; i < M; ++i){
            cin >> u >> v >> w;
            G[u].push_back(ii(v, w));
            R[v].push_back(ii(u, w));
        }

        dijkstra(s, dist0, G);
        dijkstra(t, dist1, R);

        int ans = -1;
        for(int u = 1; u <= N; ++u){
            for(int i = 0; i < G[u].size(); ++i){
                v = G[u][i].first;    w = G[u][i].second;
                if(dist0[u] + w + dist1[v] <= p)
                    ans = max(ans, w);
            }
        }

        cout << ans << endl;

    }
    return 0;
}
