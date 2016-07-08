#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
using namespace std;

typedef long long int64;

int n, m, from, to, dfsCounter, ans;
vector<int> dfs_num, tps;
vector<bool> visited;
vector< vector<int> > AdjList;

void init(int n){
    dfs_num.assign(n, UNVISITED);
    tps.clear();
    AdjList.assign(n, vector<int> (0));
    dfsCounter = ans = 0;
}

void dfs2(int p){
    dfs_num[p] = dfsCounter++;
    int q;
    for(int i = 0; i < AdjList[p].size(); ++i){
        q = AdjList[p][i];
        if(dfs_num[q] == UNVISITED) dfs2(q);
    }

    tps.push_back(p);
}

void dfs(int p){
    dfs_num[p] = dfsCounter++;
    int q;
    for(int i = 0; i < AdjList[p].size(); ++i){
        q = AdjList[p][i];
        if(dfs_num[q] == UNVISITED) dfs2(q);
    }
}

int main(){ _
    int TC; cin >> TC;
    for(int tc = 1; tc <= TC; ++tc){
        cout << "Case " << tc << ": ";
        cin >> n >> m;

        init(n);

        for(int i = 0; i < m; ++i){
            cin >> from >> to;
            --from, --to;
            AdjList[from].push_back(to);
        }

        for(int i = 0; i < n; ++i){
            if(dfs_num[i] == UNVISITED) dfs2(i);
        }

        dfs_num.assign(n, UNVISITED);
        dfsCounter = 0;
        int p;
        for(int i = n-1; i >= 0; --i){
            p = tps[i];
            if(dfs_num[p] == UNVISITED){
                ++ans;
                dfs(p);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
