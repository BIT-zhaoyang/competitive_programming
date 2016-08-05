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

vector<bool> has;
vector<int> dist;
vector< vector<int> > AdjList;
priority_queue< ii, vector< ii >, greater< ii > > pq;

void dijkstra(int source){
    if(has[source]) dist[source] = 0;
    else    dist[source] = 1;
    pq.push(ii(dist[source], source));

    int u, v, d1, d2;
    while(!pq.empty()){
        d1 = pq.top().first;    u = pq.top().second;
        pq.pop();
        if(d1 > dist[u])    continue;
        for(int i = 0; i < AdjList[u].size(); ++i){
            v = AdjList[u][i];
            if(has[v])  d2 = 0;
            else    d2 = 1;

            if(d1 + d2 < dist[v]){
                dist[v] = d1 + d2;
                pq.push(ii(dist[v], v));
            }
        }
    }
}

int main(){ _
    int TC; cin >> TC;
    for(int tc = 1; tc <= TC; ++tc){
        cout << "Case " << tc << ":" << endl;
        int N, M, K;
        cin >> N >> M >> K;
        has.assign(N+1, false);
        AdjList.assign(N+1, vector<int> (0));

        int loc;
        for(int i = 0; i < K; ++i){
            cin >> loc;
            has[loc] = true;
        }

        int u, v;
        for(int i = 0; i < M; ++i){
            cin >> u >> v;
            AdjList[u].push_back(v);
            AdjList[v].push_back(u);
        }

        int Q;  cin >> Q;
        for(int i = 0; i < Q; ++i){
            cin >> u >> v;
            if(u == v){
                cout << 0 << endl;
                continue;
            }

            dist.assign(N+1, INT_MAX);
            dijkstra(u);
            if(dist[v] == INT_MAX)  cout << -1 << endl;
            else    cout << dist[v] << endl;
        }
        cout << endl;
    }
    return 0;
}
