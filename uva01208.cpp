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
#include <vector>

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

vector< tuple<int, int, int> > ans, edge;

class DSU{
public:
    DSU(int n){
        p.assign(n, 0);
        for(int i = 0; i < n; ++i)  p[i] = i;
        rank.assign(n, 0);
    }

    void link(int u, int v){
        int x = findParent(u), y = findParent(v);
        if(x != y){
            if(rank[x] > rank[y])   p[y] = x;
            else{
                p[x] = y;
                if(rank[x] == rank[y])  rank[y] += 1;
            }
        }
    }

    int findParent(int u){
        return (p[u] == u) ? u : (p[u] = findParent(p[u]));
    }

    bool isSameSet(int u, int v){
        return findParent(u) == findParent(v);
    }
private:
    vector<int> p, rank;
};

bool mysort(tuple<int, int, int> &A, tuple<int, int, int> &B){
    int u, v, w1, x, y, w2;
    tie(u, v, w1) = A;  tie(x, y, w2) = B;
    if(w1 != w2)    return w1 < w2;
    if(u != x)  return u < x;
    return v < y;
}

int main(){ _
    char comma;
    int tc, N, from, to, w; cin >> tc;
    for(int TC = 1; TC <= tc; ++TC){
        cout << "Case " << TC << ":" << endl;

        cin >> N;
        ans.clear();
        edge.clear();
        DSU dsu(N);

        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(j)   cin >> comma;
                cin >> w;
                if(w != 0)  edge.push_back(make_tuple(min(i, j), max(i, j), w));
            }
        }

        sort(edge.begin(), edge.end(), mysort);

        for(int i = 0; i < edge.size(); ++i){
            tie(from, to, w) = edge[i];
            if(!dsu.isSameSet(from, to)){
                dsu.link(from, to);
                ans.push_back(edge[i]);
            }
        }

        for(int i = 0; i < ans.size(); ++i){
            tie(from, to, w) = ans[i];
            cout << char(from + 'A') << "-" << char(to + 'A') << " " << w << endl;
        }

    }
    return 0;
}
