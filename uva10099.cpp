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

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef pair<int, int> ii;

class DSU{
public:
    DSU(int n){
        p.assign(n, 0); r.assign(n, 0);
        for(int i = 0; i < n; ++i)  p[i] = i;
    }
    int findParent(int u){  return (p[u] == u) ? u : (p[u] = findParent(p[u]));}
    bool isSameSet(int u, int v){return findParent(u) == findParent(v);}
    void link(int u, int v){
        int x = findParent(u), y = findParent(v);
        if(x != y){
            if(r[x] > r[y]) p[y] = x;
            else{
                p[x] = y;
                if(r[x] == r[y])    ++r[y];}}}
private:
    vector<int> p, r;
};

vector< tuple<int, int, int> > edges;
vector< vector< ii > > AdjList;
vector<bool> visited;
vector<int> parent, pathW;

bool mysort(tuple<int, int, int> &A, tuple<int, int, int> &B){
    return get<2>(A) > get<2>(B);
}

void dfs(int p){
    visited[p] = true;
    int q;
    for(int i = 0; i < AdjList[p].size(); ++i){
        q = AdjList[p][i].first;
        if(!visited[q]){
            parent[q] = p;
            pathW[q] = AdjList[p][i].second;
            dfs(q);
        }
    }
}

void backtrack(int q, int &ans){
    int p = parent[q];
    if(p != 0){
        ans = min(ans, pathW[q]);
        backtrack(p, ans);
    }
}

int main(){ _
    int n, m, u, v, w, p, ans, tc = 0;
    while(cin >> n >> m){
        if(n == 0)  break;

        edges.assign(m, make_tuple(0, 0, 0));

        for(int i = 0; i < m; ++i){
            cin >> u >> v >> w;
            edges[i] = make_tuple(u, v, w);
        }

        sort(edges.begin(), edges.end(), mysort);

        DSU dsu(n+1);
        AdjList.assign(n+1, vector< ii > (0));
        for(int i = 0; i < edges.size(); ++i){
            tie(u, v, w) = edges[i];
            if(!dsu.isSameSet(u, v)){
                dsu.link(u, v);
                AdjList[u].push_back(ii(v, w));
                AdjList[v].push_back(ii(u, w));
            }
        }

        ans = INT_MAX;
        parent.assign(n+1, 0);
        pathW.assign(n+1, 0);
        visited.assign(n+1, false);
        cin >> u >> v >> p;
        dfs(u);
        backtrack(v, ans);
        ans -= 1;   // the guy himself...

        cout << "Scenario #" << ++tc << endl;
        cout << "Minimum Number of Trips = " << (p + ans - 1) / ans << endl << endl;
    }
    return 0;
}
