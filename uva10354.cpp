#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

vector< vector<ii> > AdjList;
vector< vector<int> > parent, AdjMat;
vector<int> dist;
priority_queue< ii, vector< ii >, greater< ii > > pq;

void dijkstra(int source){
    dist[source] = 0;
    pq.push(ii(dist[source], source));

    int u, v, d1, d2;
    while(!pq.empty()){
        u = pq.top().second,    d1 = pq.top().first;
        pq.pop();
        if(d1 > dist[u])    continue;
        for(int i = 0; i < AdjList[u].size(); ++i){
            v = AdjList[u][i].first;
            d2 = AdjList[u][i].second;
            if(d1 + d2 < dist[v]){
                parent[v].clear();
                parent[v].push_back(u);
                dist[v] = d1 + d2;
                pq.push(ii(dist[v], v));
            } else if(d1 + d2 == dist[v]){
                parent[v].push_back(u);
            }
        }
    }
}


int main(){ _
    int P, R, BH, OF, YH, M;
    while(cin >> P >> R >> BH >> OF >> YH >> M){
        AdjList.assign(P+1, vector<ii> (0));
        AdjMat.assign(P+1, vector<int> (P+1, BIGINT));
        parent.assign(P+1, vector<int> (0));
        dist.assign(P+1, BIGINT);

        // read input
        int u, v, d;
        for(int i = 0; i < R; ++i){
            cin >> u >> v >> d;
            AdjList[u].push_back(ii(v, d));
            AdjList[v].push_back(ii(u, d));
            AdjMat[u][v] = AdjMat[v][u] = d;
        }

        // find all vertices on potential paths selected by the boss
        // set all paths connected to these vertices as BIGINT which implies
        // they are disconnected from the rest points.
        dijkstra(BH);
        queue<int> visited;
        visited.push(OF);
        set<int> vertices;
        while(true){
            v = visited.front();
            visited.pop();
            vertices.insert(v);
            for(int i = 0; i <= P; ++i)
                AdjMat[i][v] = AdjMat[v][i] = BIGINT;

            if(v == BH) break;
            for(int i = 0; i < parent[v].size(); ++i){
                u = parent[v][i];
                visited.push(u);
            }
        }

        // floyd-warshall
        for(int i = 0; i <= P; ++i)
            AdjMat[i][i] = 0;

        for(int k = 1; k <= P; ++k)
            for(int i = 1; i <= P; ++i)
                for(int j = 1; j <= P; ++j)
                    AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);

        // check if the YH or M is a point on the path of a potential path for the boss
        if(vertices.count(YH) || vertices.count(M) || AdjMat[YH][M] == BIGINT)
            cout << "MISSION IMPOSSIBLE." << endl;
        else
            cout << AdjMat[YH][M] << endl;
    }
    return 0;
}
