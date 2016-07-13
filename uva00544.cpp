#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

class DSU{
public:
    DSU(int n){
        p.assign(n, 0);
        for(int i = 0; i < n; ++i)  p[i] = i;
        r.assign(n, 0);
    }

    int findParent(int u){
        return(u == p[u]) ? u : findParent(p[u]);
    }

    bool isSameSet(int u, int v){
        return findParent(u) == findParent(v);
    }

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

vector< tuple<int, int, int> > edges;
map<string, int> s2i;
vector<int> dfs_num, parent, pathW;
vector< vector< ii > > AdjList;

void init(int n, int m){
    edges.assign(m, make_tuple(0, 0, 0));
    s2i.clear();
    dfs_num.assign(n, UNVISITED);
    parent.assign(n, UNVISITED);
    pathW.assign(n, UNVISITED);
    AdjList.assign(n, vector< ii > (0));
}

bool mysort(tuple<int, int, int> &A, tuple<int, int, int> &B){
    return get<2>(A) > get<2>(B);
}

void dfs(int p, int &dfsCounter){
    dfs_num[p] = dfsCounter++;

    int q, w;
    for(int i = 0; i < AdjList[p].size(); ++i){
        tie(q, w) = AdjList[p][i];
        if(dfs_num[q] == UNVISITED){
            parent[q] = p;
            pathW[q] = w;
            dfs(q, dfsCounter);
        }
    }
}

void backtrack(int q, int &ans){
    int p = parent[q];
    if(p != UNVISITED){
        ans = min(ans, pathW[q]);
        backtrack(p, ans);
    }
}

int main(){ _
    int n, m, u, v, w, count, start, end, ans, tc = 1;   string str1, str2;
    while(cin >> n >> m){
        if(n == 0)  break;

        count = 0;
        init(n, m);
        for(int i = 0; i < m; ++i){
            cin >> str1 >> str2 >> w;
            if(s2i.count(str1)) u = s2i[str1];
            else{
                u = count;
                s2i[str1] = count++;
            }
            if(s2i.count(str2)) v = s2i[str2];
            else{
                v = count;
                s2i[str2] = count++;
            }
            edges[i] = make_tuple(u, v, w);
        }

        sort(edges.begin(), edges.end(), mysort);

        DSU dsu(n);
        for(int i = 0; i < edges.size(); ++i){
            tie(u, v, w) = edges[i];
            if(!dsu.isSameSet(u, v)){
                AdjList[u].push_back(ii(v, w));
                AdjList[v].push_back(ii(u, w));
                dsu.link(u, v);
            }
        }

        cin >> str1 >> str2;
        start = s2i[str1], end = s2i[str2], count = 0;  // count also functions as dfsCounter
        ans = INT_MAX;
        dfs(start, count);
        backtrack(end, ans);

        cout << "Scenario #" << tc++ << endl;
        cout << ans << " tons" << endl << endl;
    }
    return 0;
}
