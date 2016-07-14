#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

vector< tuple<int, int, int> > edges;
vector< vector< ii > > AdjList;
vector<int> parent, pathW, dfs_num;

class DSU{
public:
    DSU(int n){
        p.assign(n, 0); r.assign(n, 0);
        for(int i = 0; i < n; ++i)  p[i] = i;
    }
    int findParent(int u){return (u == p[u]) ? u : (p[u] = findParent(p[u]));}
    bool isSameSet(int u, int v){return findParent(u) == findParent(v);}
    void link(int u, int v){
        int x = findParent(u), y = findParent(v);
        if(x != y){
            if(r[x] > r[y]) p[y] = x;
            else{
                p[x] = y;
                if(r[x] == r[y])    ++r[y];
            }
        }
    }
private:
    vector<int> r, p;
};

bool mysort(tuple<int, int, int> &A, tuple<int, int, int> &B){
    return get<2>(A) < get<2>(B);
}

void dfs(int p){
    dfs_num[p] = 1;
    int q;
    for(int i = 0; i < AdjList[p].size(); ++i){
        q = AdjList[p][i].first;
        if(dfs_num[q] == UNVISITED){
            parent[q] = p, pathW[q] = AdjList[p][i].second;
            dfs(q);
        }
    }
}

void backtrack(int q, int &ans){
    int p = parent[q];
    if(p != UNVISITED){
        ans = max(ans, pathW[q]);
        backtrack(p, ans);
    }
}

int main(){ _
    int n, m, s, u, v, w, tc = 0;
    while(cin >> n >> m >> s){
        if(n == 0)  break;
        if(tc)  cout << endl;
        cout << "Case #" << ++tc << endl;

        AdjList.assign(n+1, vector< ii > (0));
        edges.assign(m, make_tuple(0, 0, 0));
        for(int i = 0; i < m; ++i){
            cin >> u >> v >> w;
            edges[i] = make_tuple(u, v, w);
        }

        sort(edges.begin(), edges.end(), mysort);
        DSU dsu(n+1);
        for(int i = 0; i < edges.size(); ++i){
            tie(u, v, w) = edges[i];
            if(!dsu.isSameSet(u, v)){
                dsu.link(u, v);
                AdjList[u].push_back(ii(v, w));
                AdjList[v].push_back(ii(u, w));
            }
        }

        int ans = 0;
        for(int i = 0; i < s; ++i){
            cin >> u >> v;
            if(!dsu.isSameSet(u, v)){
                cout << "no path" << endl;
                continue;
            }

            ans = 0;
            dfs_num.assign(n+1, UNVISITED);
            parent.assign(n+1, UNVISITED);
            pathW.assign(n+1, UNVISITED);
            dfs(u);
            backtrack(v, ans);
            cout << ans << endl;
        }
    }
    return 0;
}
