#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int maxDist, furthest;
map<int, vector< ii > > AdjList;
vector<bool> visited;

void dfs(int node, int dist){
    visited[node] = true;
    if(dist > maxDist){
        maxDist = dist;
        furthest = node;
    }

    for(int i = 0; i < AdjList[node].size(); ++i){
        int v = AdjList[node][i].first, w = AdjList[node][i].second;
        if(!visited[v]) dfs(v, dist + w);
    }
}

void process(){
    visited.assign(AdjList.size() + 1, false);  // node index starts from 1
    int root = 1;
    maxDist = 0, furthest = 0;
    dfs(root, 0);

    visited.assign(AdjList.size() + 1, false);
    root = furthest;
    maxDist = 0, furthest = 0;
    dfs(root, 0);

    cout << maxDist << endl;
    AdjList.clear();
}

int main(){ _
    string line;
    while(getline(cin, line)){
        if(line != ""){
            stringstream ss(line);
            int u, v, w;    ss >> u >> v >> w;
            AdjList[u].push_back(ii(v, w));
            AdjList[v].push_back(ii(u, w));
        } else {
            process();
        }
    }
    process();
    return 0;
}
