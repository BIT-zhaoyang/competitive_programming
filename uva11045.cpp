#include <bits/stdc++.h>
#define UNVISITED -1
#define BIGINT 1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int n, s, t, f, mf;
vector< vector<int> > res;
vector<int> parent;

void augment(int v, int minEdge){
    if(v == s){f = minEdge; return;}
    else if(parent[v] != -1){
        augment(parent[v], min(minEdge, res[parent[v]][v]));
        res[parent[v]][v] -= f; res[v][parent[v]] += f;
    }
}

void EdmondKarp(){
    f = mf = 0;
    while(true){
        queue<int> Q;   Q.push(s);
        parent.assign(n, -1);
        while(!Q.empty()){
            int u = Q.front();  Q.pop();
            if(u == t)  break;
            for(int v = 0; v < n; ++v)
                if(res[u][v] > 0 && parent[v] == -1)
                    parent[v] = u,  Q.push(v);
        }

        f = 0;
        augment(t, BIGINT);
        mf += f;

        if(f == 0)  break;
    }
}

int main(){ _
    int tc; cin >> tc;
    map<string, int> s2i;
    s2i["XXL"] = 1; s2i["XL"] = 2; s2i["L"] = 3;
    s2i["M"] = 4; s2i["S"] = 5; s2i["XS"] = 6   ;
    while(tc--){
        int N, M;   cin >> N >> M;
        n = 6 + M + 2;
        s = 0, t = n - 1;
        res.assign(n, vector<int> (n, 0));
        for(int i = 1; i <= 6; ++i) res[s][i] = N / 6;

        string shirt;
        for(int i = 7; i < t; ++i){
            res[i][t] = 1;
            cin >> shirt;   res[s2i[shirt]][i] = 1;
            cin >> shirt;   res[s2i[shirt]][i] = 1;
        }

        EdmondKarp();

        if(mf == M) cout << "YES" << endl;
        else    cout << "NO" << endl;
    }
    return 0;
}
