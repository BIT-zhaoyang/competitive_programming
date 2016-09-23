#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int n, s, t, f, mf;
vector< vector<int> > res;
vector<int> parent;
queue<int> Q;

void initBFS(){
    parent.assign(n+1, -1);
    Q.push(s);
}

void augment(int v, int minEdge){
    if(v == s){ f = minEdge;    return;}
    else if(parent[v] != -1){
        augment(parent[v], min(minEdge, res[parent[v]][v]));
        res[parent[v]][v] -= f;
        res[v][parent[v]] += f;
    }
}

void EdmondKarp(){
    mf = f = 0;
    while(true){
        // BFS searching path
        initBFS();
        while(!Q.empty()){
            int u = Q.front();  Q.pop();
            for(int v = 1; v <= n; ++v)
                if(res[u][v] > 0 && parent[v] == -1)
                    parent[v] = u,  Q.push(v);
        }
        // augment path
        f = 0;
        augment(t, BIGINT);
        mf += f;

        if(f == 0)  break;
    }
}

void print(int tc){
    cout << "Network " << tc << endl;
    cout << "The bandwidth is " << mf << "." << endl << endl;
}

int main(){ _
    int tc = 0;
    while(cin >> n){
        if(n == 0)  break;
        res.assign(n+1, vector<int> (n+1, 0));

        int c, u, v, w;
        cin >> s >> t >> c;
        for(int i = 0; i < c; ++i){
            cin >> u >> v >> w;
            res[u][v] += w;
            res[v][u] = res[u][v];
        }

        EdmondKarp();

        print(++tc);
    }
    return 0;
}
