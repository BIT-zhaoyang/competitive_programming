#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

int maxCap;
vector<int> price;
vector< vector< ii > > AdjList;
vector< vector<int> > cost;

void dijkstra(int source, int target){
    priority_queue< iii, vector< iii >, greater< iii > > pq;
    cost[source][0] = 0;
    pq.push(iii(cost[source][0], source, 0));

    int kost1, kost2, d, u, v, cap, extra, remain;
    while(!pq.empty()){
        tie(kost1, u, cap) = pq.top();    pq.pop();
        if(kost1 > cost[u][cap]) continue;
        if(u == target) return;
        for(int i = 0; i < AdjList[u].size(); ++i){
            v = AdjList[u][i].first;
            d = AdjList[u][i].second;
            for(int j = 0; cap + j <= maxCap; ++j){
                if(cap + j < d) continue;

                extra = j * price[u];
                remain = cap + j - d;
                kost2 = kost1 + extra;
                if(kost2 < cost[v][remain]){
                    cost[v][remain] = kost2;
                    pq.push(iii(kost2, v, remain));
                }
            }
        }
    }
}

int main(){ _
    int n, m;
    while(cin >> n >> m){
        price.assign(n, 0);
        AdjList.assign(n, vector< ii > (0));
        for(int i = 0; i < n; ++i)  cin >> price[i];

        int u, v, w;
        for(int i = 0; i < m; ++i){
            cin >> u >> v >> w;
            AdjList[u].push_back(ii(v, w));
            AdjList[v].push_back(ii(u, w));
        }

        int q;  cin >> q;
        for(int i = 0; i < q; ++i){
            cin >> maxCap >> u >> v;
            cost.assign(n, vector<int> (maxCap+1, INT_MAX));
            dijkstra(u, v);
            if(cost[v][0] == INT_MAX)   cout << "impossible" << endl;
            else    cout << cost[v][0] << endl;
        }
    }
    return 0;
}
