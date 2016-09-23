#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int s, t, f, mf, nk, np, n, total;
vector< vector<int> > res;
vector<int> parent;

void augment(int v, int minEdge){
    if(v == s){ f = minEdge;    return; }
    else if(parent[v] != -1){
        augment(parent[v], min(minEdge, res[parent[v]][v]));
        res[parent[v]][v] -= f;
        res[v][parent[v]] += f;
    }
}

void EdmondKarp(){
    f = mf = 0;
    // iterate until no path found
    while(true){
        // BFS for finding path
        parent.assign(n+2, -1);
        queue<int> Q;   Q.push(s);

        bool toEnd = false;
        while(!Q.empty()){
            int u = Q.front();  Q.pop();
            for(int v = 0; v < n+2; ++v)
                if(res[u][v] > 0 && parent[v] == -1)
                    parent[v] = u,  Q.push(v), toEnd |= (v == t);
            if(toEnd)   break;
        }

        f = 0;
        augment(t, BIGINT);
        mf += f;

        if(f == 0)  break;
    }
}

void print(){
    if(mf != total) cout << 0 << endl;
    else{
        cout << 1 << endl;
        for(int u = np + 1; u <= n; ++u){
            for(int v = 1; v <= np; ++v){
                if(res[u][v] == 1){
                    cout << v;
                    --res[t][u];
                    if(res[t][u])   cout << " ";
                    else    break;
                }
            }
            cout << endl;
        }
    }
}

int main(){ _
    while(cin >> nk >> np){
        if(nk == 0) break;
        n = nk + np;
        res.assign(n+2, vector<int> (n+2, 0));
        s = 0, t = n+1;

        total = 0;
        for(int i = 1; i <= nk; ++i){
            cin >> res[i+np][t];
            total += res[i+np][t];
        }

        int nc, cat;
        for(int i = 1; i <= np; ++i){
            res[s][i] = 1;
            cin >> nc;
            for(int j = 0; j < nc; ++j){
                cin >> cat;
                res[i][cat + np] = 1;
            }
        }

        EdmondKarp();

        print();
    }
    return 0;
}
