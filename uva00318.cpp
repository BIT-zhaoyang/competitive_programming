#include <algorithm>
#include <bitset>
#include <cstring>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <sstream>
#include <vector>

#define UNVISITED -1
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(1);
using namespace std;

typedef long long int64;
typedef pair<int, double> ii;

vector< vector< ii > > AdjList;
priority_queue< ii, vector< ii >, greater< ii > > pq;
vector<int> dist;

int dijkstra(int source){
    dist[source] = 0;
    pq.push(ii(dist[source], source));

    ii p, q;
    int last;
    int u, v, d1, d2;
    while(!pq.empty()){
        p = pq.top();   pq.pop();
        u = p.second, d1 = p.first;
        if(dist[u] < d1)    continue;

        last = u;
        for(int i = 0; i < AdjList[u].size(); ++i){
            q = AdjList[u][i];
            v = q.first, d2 = q.second;
            if(dist[u] + d2 < dist[v]){
                dist[v] = dist[u] + d2;
                pq.push(ii(dist[v], v));
            }
        }

    }
    return last;
}

int main(){ _
    int tc = 0, n, m, u, v, w;
    while(cin >> n >> m){
        if(n == 0 && m == 0)    break;
        cout << "System #" << ++tc << endl;
        if(n == 1){
            cout << "The last domino falls after 0.0 seconds, at key domino 1." << endl << endl;
            continue;
        }

        AdjList.assign(n+1, vector<ii> (0));
        dist.assign(n+1, INT_MAX);

        for(int i = 0; i < m; ++i){
            cin >> u >> v >> w;
            AdjList[u].push_back(ii(v, w));
            AdjList[v].push_back(ii(u, w));
        }

        int last = dijkstra(1);

        // Check all bridges connected to the last domino. The last fallen one may be on any such bridge
        int prior = -1, slast = -1;  double t = 0.0, maxT = double(dist[last]);
        for(int i = 0; i < AdjList[last].size(); ++i){
            prior = AdjList[last][i].first;
            w = AdjList[last][i].second;
            if(dist[prior] + w > dist[last]){
                t = dist[last] + (w - (dist[last] - dist[prior])) / 2.0;
            }

            if(t > maxT){
                maxT = t;
                slast = prior;
            }
        }

        if(slast == -1){
            cout << "The last domino falls after " << fixed << maxT << " seconds, at key domino " << last << "." <<endl;
            cout << endl;
        } else {
            cout << "The last domino falls after " << fixed << maxT << " seconds, between key dominoes " << slast << " and " << last << "." <<endl;
            cout << endl;
        }

    }
    return 0;
}
