#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(3);
#define UNVISITED -1
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

/* Didn't expect this problem took me so much time! Writing a good traverse part really took me a while. But now I became much better at backtraking DFS. I think the backtrack problem may even appear in an interview. It is easy but requires the interviewer to have a good understanding about DFS in a **TREE**.*/

class DSU{
public:
    DSU(int n){
        p.assign(n, 0);
        for(int i = 0; i < n; ++i)  p[i] = i;
        r.assign(n, 0);
    }

    bool isSameSet(int u, int v){
        return findParent(u) == findParent(v);
    }

    int findParent(int u){
        return (u == p[u]) ? u : (p[u] = findParent(p[u]));
    }

    void link(int u, int v){
        int x = findParent(u), y = findParent(v);
        if(x != y){
            if(r[x] > r[y]) p[y] = x;
            else {
                p[x] = y;
                if(r[x] == r[y])    ++r[y];
            }
        }
    }

private:
    vector<int> r, p;
};

vector< ii > points;
vector< tuple<int, int, double> > edges;
vector< vector< pair<int, double> > > AdjList;
vector<int> dfs_num, parent;
vector<double> pathW;

double dist(ii &A, ii &B){
    int x = A.first - B.first, y = A.second - B.second;
    return sqrt(x*x + y*y);
}

bool mysort(tuple<int, int, double> &A, tuple<int, int, double> &B){
    return get<2>(A) < get<2>(B);
}

void dfs(int p, int &dfsCounter){
    dfs_num[p] = dfsCounter++;

    int q;
    for(int i = 0; i < AdjList[p].size(); ++i){
        q = AdjList[p][i].first;
        if(dfs_num[q] == UNVISITED){
            parent[q] = p;
            pathW[q] = AdjList[p][i].second;
            dfs(q, dfsCounter);
        }
    }
}

void backtrack(int q, double &ans){
    int p = parent[q];
    if(p != UNVISITED){
        ans = max(ans, pathW[q]);
        backtrack(p, ans);
    }
}

void init(int n){
    edges.clear();
    points.assign(n, ii(0, 0));
    dfs_num.assign(n, UNVISITED);
    parent.assign(n, UNVISITED);
    pathW.assign(n, 0);
    AdjList.assign(n, vector< pair<int, double> > (0));
}

int main(){ _
    int count = 0, n, u, v, dfsCounter;
    double w, ans;

    while(cin >> n){
        if(n == 0)  break;
        cout << "Scenario #" << ++count << endl;

        init(n);
        for(int i = 0; i < n; ++i)  cin >> points[i].first >> points[i].second;

        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                edges.push_back(make_tuple(i, j, dist(points[i], points[j])));
            }
        }

        sort(edges.begin(), edges.end(), mysort);

        DSU dsu(n);
        for(int i = 0; i < edges.size(); ++i){
            tie(u, v, w) = edges[i];
            if(!dsu.isSameSet(u, v)){
                dsu.link(u, v);
                AdjList[u].push_back(pair<int, double>(v, w));
                AdjList[v].push_back(pair<int, double>(u, w));
            }
        }

        dfsCounter = 0; ans = 0.0;
        dfs(0, dfsCounter);
        backtrack(1, ans);

        cout << "Frog Distance = " << fixed << ans << endl << endl;
    }
    return 0;
}
