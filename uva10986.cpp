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
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

vector<int> dist;
vector< vector< ii > > AdjList;
priority_queue< ii, vector< ii >, greater< ii > > pq;

void dijkstra(int source){
    dist[source] = 0;
    pq.push(ii(dist[source], source));

    ii p, q;
    int u, v, d1, d2;
    while(!pq.empty()){
        p = pq.top();   pq.pop();
        u = p.second,   d1 = p.first;
        if(dist[u] < d1)    continue;

        for(int i = 0; i < AdjList[u].size(); ++i){
            q = AdjList[u][i];
            v = q.first,    d2 = q.second;
            if(dist[u] + d2 < dist[v]){
                dist[v] = dist[u] + d2;
                pq.push(ii(dist[v], v));
            }
        }
    }
}

int main(){ _
    int TC; cin >> TC;
    for(int tc = 1; tc <= TC; ++tc){
        cout << "Case #" << tc <<": ";
        int n, m, s, t;     cin >> n >> m >> s >> t;
        AdjList.assign(n, vector< ii > (0));
        dist.assign(n, INT_MAX);

        int u, v, w;
        for(int i = 0; i < m; ++i){
            cin >> u >> v >> w;
            AdjList[u].push_back(ii(v, w));
            AdjList[v].push_back(ii(u, w));
        }

        dijkstra(s);
        if(dist[t] == INT_MAX)  cout << "unreachable" << endl;
        else    cout << dist[t] << endl;
    }
    return 0;
}
