#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

/* As said in CP3, the difficulty in this problem is that to recognize it's an MST problem. */

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
    return get<2>(A) > get<2>(B);
}

int main(){ _
    int tc; cin >> tc;
    while(tc--){
        int n, m, u, v, w, ans = 0;
        cin >> n >> m;
        vector< tuple<int, int, int> > edges(m, make_tuple(0, 0, 0));
        for(int i = 0; i < m; ++i){
            cin >> u >> v >> w;
            edges[i] = make_tuple(u, v, w);
        }

        sort(edges.begin(), edges.end(), mysort);

        DSU dsu(n+1);
        for(int i = 0; i < edges.size(); ++i){
            tie(u, v, w) = edges[i];
            if(dsu.isSameSet(u, v)) ans += w;
            else    dsu.link(u, v);
        }

        cout << ans << endl;
    }
    return 0;
}
