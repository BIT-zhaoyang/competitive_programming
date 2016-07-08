#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
using namespace std;

int n, m, type, from, to, dfsCounter, numSCC;
vector<int> dfs_num, dfs_low, S;
vector<bool> visiting;
vector< vector<int> > AdjList;
bool flag;

void SCC(int p){
    dfs_num[p] = dfs_low[p] = dfsCounter++;
    visiting[p] = true;
    S.push_back(p);

    int q;
    for(int i = 0; i < AdjList[p].size(); ++i){
        q = AdjList[p][i];

        if(dfs_num[q] == UNVISITED) SCC(q);
        if(visiting[q]) dfs_low[p] = min(dfs_low[p], dfs_low[q]);
    }

    if(dfs_num[p] == dfs_low[p]){
        ++numSCC;
        while(true){
            q = S.back();
            S.pop_back();
            visiting[q] = false;
            if(p == q)  break;
        }
    }
}

int main(){ _
    while(cin >> n >> m){
        if(n + m == 0)  break;

        dfs_num.assign(n, UNVISITED);
        dfs_low.assign(n, UNVISITED);
        visiting.assign(n, false);
        AdjList.assign(n, vector<int> (0));
        S.clear();
        dfsCounter = numSCC = 0;

        for(int i = 0; i < m; ++i){
            cin >> from >> to >> type;
            --from, --to;
            AdjList[from].push_back(to);
            if(type == 2){
                AdjList[to].push_back(from);
            }
        }

        for(int i = 0; i < n; ++i){
            if(dfs_num[i] == UNVISITED){
                SCC(i);
            }
        }

        if(numSCC == 1)  cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}
