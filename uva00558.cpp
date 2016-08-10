#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int n, m;
vector< vector< ii > > AdjList;

bool sssp(int source){
    queue<int> Q;    Q.push(source);
    vector<int> dist(n, INT_MAX);   dist[source] = 0;
    vector<int> times(n, 0);    times[source] += 1;
    vector<bool> in(n, false);  in[source] = true;

    int u, v, d1, d2;
    while(!Q.empty()){
        u = Q.front();  Q.pop();  in[u] = false;
        d1 = dist[u];
        for(int i = 0; i < AdjList[u].size(); ++i){
            v = AdjList[u][i].first,    d2 = AdjList[u][i].second;
            if(d1 + d2 < dist[v]){
                dist[v] = d1 + d2;
                if(!in[v]){
                    Q.push(v);
                    times[v] += 1;
                    in[v] = true;
                    if(times[v] >= n)   return true;
                }
            }
        }
    }
    return false;
}

int main(){ _
    int tc; cin >> tc;
    while(tc--){
        cin >> n >> m;
        AdjList.assign(n, vector< ii > (0));

        int x, y, t;
        for(int i = 0; i < m; ++i){
            cin >> x >> y >> t;
            AdjList[x].push_back(ii(y, t));
        }

        bool cycle = sssp(0);
        if(cycle)   cout << "possible" << endl;
        else    cout << "not possible" << endl;
    }
    return 0;
}
