#include <bits/stdc++.h>
#define UNVISITED -1
#define BIGINT 1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

vector< vector<int> > box, AdjList;
stack<int> topo;
vector<int> dist, parent;

bool inside(vector<int> &a, vector<int> &b){
    int m = a.size();
    for(int i = 0; i < m; ++i)
        if(a[i] >= b[i])
            return false;
    return true;
}

void dfs(int u){
    dist[u] = 1;    // set all distance to 1 when doing topo sort
                    // since there will be mutiple start point
    for(int i = 0; i < AdjList[u].size(); ++i){
        int v = AdjList[u][i];
        if(dist[v] == -1)
            dfs(v);
    }
    topo.push(u);
}

void dfs2(int u){
    for(int i = 0; i < AdjList[u].size(); ++i){
        int v = AdjList[u][i];
        if(dist[v] < dist[u] + 1){
            dist[v] = dist[u] + 1;
            parent[v] = u;
        }
    }
}

void print(int v){
    int u = parent[v];
    if(u != -1){
        print(u);
        cout << " " << v + 1;
    } else{
        cout << v + 1;
    }
}

int main(){ _
    int n, m;
    while(cin >> n >> m){
        box.assign(n, vector<int> (m, 0));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j)
                cin >> box[i][j];
            sort(box[i].begin(), box[i].end());
        }

        AdjList.assign(n, vector<int> (0));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if(inside(box[i], box[j]))
                    AdjList[i].push_back(j);

        // topo sort
        dist.assign(n, -1);
        for(int i = 0; i < n; ++i)
            if(dist[i] == -1)
                dfs(i);

        // update distance in topo sort order
        int tail = topo.top();
        parent.assign(n, -1);
        while(!topo.empty()){
            int u = topo.top();
            topo.pop();
            if(dist[u] > dist[tail])
                tail = u;
            dfs2(u);
        }

        cout << dist[tail] << endl;
        print(tail);
        cout << endl;
    }
    return 0;
}
