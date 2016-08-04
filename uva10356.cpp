#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

#define walk 0
#define ride 1

int n, r;
vector< vector<int> > dist;
vector< vector< ii > > AdjList;
priority_queue< iii, vector< iii >, greater< iii > > pq;

void dijkstra(){
    int u, v, d1, d2, currStatus;
    u = 0,  d1 = 0, currStatus = walk;
    dist[currStatus][0] = 0;
    pq.push(iii(dist[currStatus][0], 0, currStatus));

    while(!pq.empty()){
        tie(d1, u, currStatus) = pq.top();   pq.pop();
        if(d1 > dist[currStatus][u])    continue;
        for(int i = 0; i < AdjList[u].size(); ++i){
            v = AdjList[u][i].first,    d2 = AdjList[u][i].second;
            if(d1 + d2 < dist[1 - currStatus][v]){
                dist[1 - currStatus][v] = d1 + d2;
                pq.push(iii(dist[1 - currStatus][v], v, 1 - currStatus));
            }
        }
    }
}

int main(){ _
    int tc = 0;
    while(cin >> n >> r){
        dist.assign(2, vector<int> (n, INT_MAX));
        AdjList.assign(n, vector< ii > (0));
        int u, v, w;
        for(int i = 0; i < r; ++i){
            cin >> u >> v >> w;
            AdjList[u].push_back(ii(v, w));
            AdjList[v].push_back(ii(u, w));
        }

        dijkstra();

        cout << "Set #" << ++tc << endl;
        if(dist[walk][n-1] == INT_MAX)  cout << "?" << endl;
        else    cout << dist[walk][n-1] << endl;
    }
    return 0;
}
