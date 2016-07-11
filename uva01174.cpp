#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
using namespace std;

typedef long long int64;

class DSU{
public:
    DSU(int n){
        p.assign(n, 0);
        for(int i = 0; i < n; ++i)  p[i] = i;
        rank.assign(n, 0);
    }

    bool isSameSet(int u, int v){
        return findParent(u) == findParent(v);
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

private:
    vector<int> p, rank;
};

map<string, int> s2i;
vector< tuple<string, string, int> > edges;

bool mysort(tuple<string, string, int> &A, tuple<string, string, int> &B){
    return get<2>(A) < get<2>(B);
}

int main(){ _
    int tc, N, M, u, v, w, count, ans;   cin >> tc;
    string from, to;
    while(tc--){
        cin >> N >> M;

        s2i.clear();
        edges.assign(M, make_tuple("", "", 0));
        count = ans = 0;
        DSU dsu(N);

        for(int i = 0; i < M; ++i){
            cin >> from >> to >> w;
            if(s2i.count(from) == 0)    s2i[from] = count++;
            if(s2i.count(to) == 0)  s2i[to] = count++;
            edges[i] = make_tuple(from, to, w);
        }

        sort(edges.begin(), edges.end(), mysort);

        for(int i = 0; i < M; ++i){
            tie(from, to, w) = edges[i];
            u = s2i[from], v = s2i[to];
            if(dsu.isSameSet(u, v)) continue;
            else{
                dsu.link(u, v);
                ans += w;
            }
        }

        cout << ans << endl;
        if(tc)  cout << endl;
    }
    return 0;
}
