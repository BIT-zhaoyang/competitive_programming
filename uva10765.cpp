#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
using namespace std;

typedef long long int64;

int n, m, a, b, root, numChild, dfsCounter;
vector<int> dfs_num, dfs_low, parent;
vector<bool> articulation;
vector< vector<int> > edges;
vector< pair<int, int> > ans;

void findArticulation(int p){
    dfs_num[p] = dfs_low[p] = dfsCounter++;

    int q;
    for(int i = 0; i < edges[p].size(); ++i){
        q = edges[p][i];
        if(dfs_num[q] == UNVISITED){
            parent[q] = p;
            if(p == root)   ++numChild;

            findArticulation(q);

            if(dfs_low[q] >= dfs_num[p]){
                articulation[p] = true;
                ans[p].first += 1;
            }

            dfs_low[p] = min(dfs_low[p], dfs_low[q]);
        } else if(q != parent[p]){
            dfs_low[p] = min(dfs_low[p], dfs_num[q]);
        }
    }
    ans[p].second = p;
}

bool mycomp(pair<int, int> &a, pair<int, int> &b){
    if(a.first > b.first)   return true;
    if(a.first == b.first)  return a.second < b.second;
    return false;
}

int main(){ _
    while(cin >> n >> m){
        if(n + m == 0)  break;

        dfs_num.assign(n, UNVISITED);
        dfs_low.assign(n, UNVISITED);
        parent.assign(n, UNVISITED);
        articulation.assign(n, false);
        ans.assign(n, make_pair(1, 0));
        edges.assign(n, vector<int> (0));

        while(cin >> a >> b){
            if(a + b == -2) break;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }

        dfsCounter = 0;
        for(int i = 0; i < n; ++i){
            if(dfs_num[i] == UNVISITED){
                root = i, numChild = 0;
                findArticulation(root);
                if(numChild < 2){
                    articulation[root] = false;
                    ans[root].first = 1;
                }
            }
        }

        sort(ans.begin(), ans.end(), mycomp);
        for(int i = 0; i < m; ++i){
            cout << ans[i].second << " " << ans[i].first << endl;
        }
        cout << endl;
    }
    return 0;
}
