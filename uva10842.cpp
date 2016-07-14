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
bool mysort(tuple<int, int, int> &A, tuple<int, int, int> &B){
    return get<2>(A) > get<2>(B);
}
int main(){ _
    int TC, n, m, u, v, w, ans; cin >> TC;
    for(int tc = 1; tc <= TC; ++tc){
        cout << "Case #" << tc << ": ";
        cin >> n >> m;
        DSU dsu(n);
        edges.assign(m, make_tuple(0, 0, 0));
        for(int i = 0; i < m; ++i){
            cin >> u >> v >> w;
            edges[i] = make_tuple(u, v, w);
        }
        sort(edges.begin(), edges.end(), mysort);
        for(int i = 0; i < edges.size(); ++i){
            tie(u, v, w) = edges[i];
            if(!dsu.isSameSet(u, v)){
                dsu.link(u, v);
                ans = w;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
