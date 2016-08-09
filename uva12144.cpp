#include <bits/stdc++.h>
#define UNVISITED -1
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
/* The discussion in the forum is really nice! For the optimal shortest pathes, if there are many, they don't have to be unintersected. For example, there may be one SP 0-1-2-4, and another one 0-2-4. When we remove these SPs, we need to remove both of them. We can't remove only one, then re-run SSSP to find another one, then remove the new one. If we process in this way, we won't be able to find 0-2-4 in the above example since 2-4 has been removed.

To be more specific, draw this example:
5 6
0 4
0 1 1
0 2 2
1 2 1
2 3 1
3 4 1
2 4 1
0 0

ref: https://uva.onlinejudge.org/board/viewtopic.php?f=56&t=208410&p=374466&hilit=12144#p374466
*/

vector<int> dist;
set< ii > forbid;
vector< vector<int> > parent;
vector< vector< ii > > AdjList;
priority_queue< ii, vector< ii >, greater< ii > > pq;

void dijkstra(int source){
    dist[source] = 0;
    pq.push(ii(dist[source], source));

    int u, v, d1, d2;
    while(!pq.empty()){
        u = pq.top().second;    d1 = pq.top().first;
        pq.pop();
        if(d1 > dist[u])    continue;
        for(int i = 0; i < AdjList[u].size(); ++i){
            v = AdjList[u][i].first;  d2 = AdjList[u][i].second;
            if(forbid.count(ii(u, v)))  continue;
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
    int N, M, S, D;
    while(cin >> N >> M){
        if(N == 0)  break;
        AdjList.assign(N, vector< ii > (0));
        forbid.clear();

        cin >> S >> D;
        int u, v, w;
        for(int i = 0; i < M; ++i){
            cin >> u >> v >> w;
            AdjList[u].push_back(ii(v, w));
        }

        parent.assign(N, vector<int> (0));
        dist.assign(N, INT_MAX);
        dijkstra(S);
        int best = dist[D];
        if(best == INT_MAX){
            cout << -1 << endl;
            continue;
        }

        int subOpt = best;
        while(subOpt == best){
            // remove edges in shortest path
            queue<int> Q;
            Q.push(D);
            while(!Q.empty()){
                v = Q.front();  Q.pop();
                for(int i = 0; i < parent[v].size(); ++i){
                    u = parent[v][i];
                    forbid.insert(ii(u, v));
                    Q.push(u);
                }
            }
            // rerun SSSP
            parent.assign(N, vector<int> (0));
            dist.assign(N, INT_MAX);
            dijkstra(S);
            subOpt = dist[D];
        }

        if(subOpt == INT_MAX)   cout << -1 << endl;
        else    cout << subOpt << endl;
    }
    return 0;
}
