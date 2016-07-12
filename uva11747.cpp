#include <algorithm>
#include <bitset>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <sstream>
#include <tuple>
#include <vector>

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

class DSU{
public:
    DSU(int n){
        p.assign(n, 0);
        for(int i = 0; i < n; ++i)  p[i] = i;
        r.assign(n, 0);
    }

    void link(int u, int v){
        int x = findParent(u), y = findParent(v);
        if(x != y){
            if(r[x] > r[y]) p[y] = x;
            else{
                p[x] = y;
                if(r[x] == r[y]) ++r[y];
            }
        }
    }

    int findParent(int u){
        return (u == p[u]) ? u : (p[u] = findParent(p[u]));
    }

    bool isSameSet(int u, int v){
        return findParent(u) == findParent(v);
    }

private:
    vector<int> p, r;
};

vector< tuple<int, int, int> > edges;

bool mysort(tuple<int, int, int> &A, tuple<int, int, int> &B){
    return get<2>(A) < get<2>(B);
}

int main(){ _
    int n, m, u, v, w, counter;
    bool forest;
    while(cin >> n >> m){
        if(n == 0)  break;

        edges.assign(m, make_tuple(0, 0, 0));
        for(int i = 0; i < m; ++i){
            cin >> u >> v >> w;
            edges[i] = make_tuple(u, v, w);
        }

        sort(edges.begin(), edges.end(), mysort);

        DSU dsu(n);
        forest = true;
        counter = 0;
        for(int i = 0; i < edges.size(); ++i){
            tie(u, v, w) = edges[i];
            if(dsu.isSameSet(u, v)){
                forest = false;
                if(counter) cout << " ";
                cout << w;
                ++counter;
            } else {
                dsu.link(u, v);
            }
        }

        if(forest)  cout << "forest" << endl;
        else    cout << endl;
    }
    return 0;
}
