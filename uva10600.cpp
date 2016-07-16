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

#define UNVISITED -1
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef pair<int, int> ii;

/* I used UAlberta method since it's easier to implement. See my WaysToFind2ndMST for reference. */

class DSU{
public:
    DSU(int n){
        p.assign(n, 0); r.assign(n, 0);
        for(int i = 0; i < n; ++i)  p[i] = i;}
    int findParent(int u){return (u == p[u]) ? u : (p[u] = findParent(p[u]));}
    bool isSameSet(int u, int v){return findParent(u) == findParent(v);}
    void link(int u, int v){
        int x = findParent(u), y = findParent(v);
        if(x != y){
            if(r[x] > r[y]) p[y] = x;
            else{
                p[x] = y;
                if(r[x] == r[y])    ++r[y];}}}
private:
    vector<int> r, p;};

vector< tuple<int, int, int> > edges;
vector< tuple<int, int, int> > RestEdges;
vector< vector< ii > > AdjList;
vector< vector<int> > allPath;

bool mysort(tuple<int, int, int> &A, tuple<int, int, int> &B){
    return get<2>(A) < get<2>(B);
}

void dfs(int root, int p, int longest){
    allPath[root][p] = longest;
    int q, w;
    for(int i = 0; i < AdjList[p].size(); ++i){
        q = AdjList[p][i].first, w = AdjList[p][i].second;
        if(allPath[root][q] == UNVISITED){
            dfs(root, q, max(longest, w));
        }
    }
}

int main(){ _
    int tc; cin >> tc;
    while(tc--){
        int n, m, u, v, w;   cin >> n >> m;
        AdjList.assign(n+1, vector< ii > (0));
        edges.assign(m, make_tuple(0, 0, 0));
        RestEdges.clear();

        for(int i = 0; i < m; ++i){
            cin >> u >> v >> w;
            edges[i] = make_tuple(u, v, w);
        }
        sort(edges.begin(), edges.end(), mysort);
        DSU dsu(n+1);
        int best = 0;
        for(int i = 0; i < edges.size(); ++i){
            tie(u, v, w) = edges[i];
            if(!dsu.isSameSet(u, v)){
                dsu.link(u, v); best += w;
                AdjList[u].push_back(ii(v, w));
                AdjList[v].push_back(ii(u, w));
            } else {
                RestEdges.push_back(edges[i]);
            }
        }
        cout << best << " ";

        // compute maxEdge on each path between every pair p, q
        allPath.assign(n+1, vector<int> (n+1, UNVISITED));
        for(int i = 1; i <= n; ++i){
            dfs(i, i, 0);
        }
        // compute second MST
        int second = INT_MAX;
        for(int i = 0; i < RestEdges.size(); ++i){
            tie(u, v, w) = RestEdges[i];
            second = min(second, w - allPath[u][v]);
        }
        cout << best + second << endl;
    }
    return 0;
}
