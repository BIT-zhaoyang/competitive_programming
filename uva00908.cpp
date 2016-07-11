#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
using namespace std;

typedef long long int64;
/*  This problem can only be solved using all M+K lines. It can't be solved by treating the original connection as a spanning tree and update it if a better one exsits, namely by finding a second MST. The reason is that, the original one is not a best MST...
*/

class DSU{
public:
    DSU(int n){
        parent.assign(n, 0);
        rank.assign(n, 0);
        for(int i = 0; i < n; ++i)  parent[i] = i;
    }

    void link(int u, int v){
        int x = findParent(u), y = findParent(v);
        if(x != y){
            if(rank[x] > rank[y]){
                parent[y] = x;
            } else {
                parent[x] = y;
                if(rank[x] == rank[y])  rank[y] += 1;
            }
        }
    }

    bool isSameSet(int u, int v){
        return findParent(u) == findParent(v);
    }

    int findParent(int u){
        return (u == parent[u]) ? u : (parent[u] = findParent(parent[u]));
    }

private:
    vector<int> parent, rank;
};

bool mysort(tuple<int, int, int> &A, tuple<int, int, int> &B){
    return get<2>(A) <= get<2>(B);
}

int main(){ _
    int N, K, M, from, to, w, originW, newW, tc = 0;
    vector< tuple<int, int, int> > edge;
    while(cin >> N){
        // initialize
        if(tc++)    cout << endl;
        edge.assign(N-1, make_tuple(0, 0, 0));
        originW = newW = 0;

        // read N-1 linkage
        for(int i = 0; i < N-1; ++i){
            cin >> from >> to >> w;
            edge[i] = make_tuple(from, to, w);
            originW += w;
        }
        cout << originW << endl;

        // read new K linkage
        cin >> K;
        for(int i = 0; i < K; ++i){
            cin >> from >> to >> w;
            edge.push_back(make_tuple(from, to, w));
        }

        // read original left M linlkage
        cin >> M;
        for(int i = 0; i < M; ++i){
            cin >> from >> to >> w;
            edge.push_back(make_tuple(from, to, w));
        }

        // do MST
        // first sort edges in increasing order
        sort(edge.begin(), edge.end(), mysort);

        // start MST
        DSU dsu(N + 1); // edge index starts from 1
        for(int i = 0; i < edge.size(); ++i){
            tie(from, to, w) = edge[i];
            if(dsu.isSameSet(from, to)) continue;
            else{
                dsu.link(from, to);
                newW += w;
            }
        }

        cout << newW << endl;
    }
    return 0;
}
