#include <bits/stdc++.h>
#define UNVISITED -1
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
vector< vector< ii > > AdjList;
vector<int> dist;
priority_queue<ii, vector< ii >, greater< ii > > pq;

void dijkstra(int source){
    dist[source] = 0;
    pq.push(ii(dist[source], source));

    int u, v, d1, d2;
    while(!pq.empty()){
        u = pq.top().second;    d1 = pq.top().first;
        pq.pop();
        if(d1 > dist[u])    continue;
        for(int i = 0; i < AdjList[u].size(); ++i){
            v= AdjList[u][i].first;     d2 = AdjList[u][i].second;
            if(d1 + d2 < dist[v]){
                dist[v] = d1 + d2;
                pq.push(ii(dist[v], v));
            }
        }
    }
}

int main(){ _
    int N, M, C, K;
    while(cin >> N >> M >> C >> K){
        if(N == 0)  break;
        AdjList.assign(N, vector< ii > (0));

        int u, v, w;
        for(int i = 0; i < M; ++i){
            cin >> u >> v >> w;
            if(u < C && v < C){
                if(abs(u-v) > 1)    continue;
                AdjList[min(u, v)].push_back(ii(max(u, v), w));
            } else if(u >= C && v >= C){
                AdjList[u].push_back(ii(v, w));
                AdjList[v].push_back(ii(u, w));
            } else {
                AdjList[max(u, v)].push_back(ii(min(u, v), w));
            }
        }

        dist.assign(N, INT_MAX);
        dijkstra(K);
        cout << dist[C-1] << endl;
    }
    return 0;
}
