#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;

class UnionFind{
public:
    UnionFind(int n){
        parent.assign(n+1, 0);
        rank.assign(n+1, 0);
        size.assign(n+1, 1);
        for(int i = 0; i < parent.size(); ++i)  parent[i] = i;
        maxSize = 0;
    }

    void link(int p, int q){
        int pp = findParent(p), pq = findParent(q);
        if(pp == pq)    return;

        if(rank[pp] > rank[pq]){
            parent[pq] = pp;
            size[pp] += size[pq];
            maxSize = max(maxSize, size[pp]);
        } else {
            parent[pp] = pq;
            size[pq] += size[pp];
            if(rank[pp] == rank[pq])    rank[pq] += 1;
            maxSize = max(maxSize, size[pq]);
        }
    }

    int findParent(int p){
        return (p == parent[p]) ? p: (parent[p] = findParent(parent[p]));
    }

    int getMaxSize(){
        return maxSize;
    }

private:
    vector<int> parent;
    vector<int> size;
    vector<int> rank;
    int maxSize;
};

int main(){ _
    int n, m;
    while(cin >> n >> m){
        if(n + m == 0)  break;
        UnionFind uf(n);

        vector< tuple<int, int, int> > edges(m);
        int p, q, v, maxV = INT_MIN;
        for(int i = 0; i < m; ++i){
            cin >> p >> q >> v;
            maxV = max(v, maxV);
            edges[i] = make_tuple(p, q, v);
        }

        for(int i = 0; i < m; ++i){
            if(get<2>(edges[i]) == maxV)    uf.link(get<0>(edges[i]), get<1>(edges[i]));
        }

        cout << uf.getMaxSize() << endl;
    }
    return 0;
}
