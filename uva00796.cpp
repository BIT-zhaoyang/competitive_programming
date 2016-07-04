#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
using namespace std;

typedef long long int64;

int n, m, a, b, root, dfsCounter, ans;
vector<int> dfs_num, dfs_low, parent;
vector< pair<int, int> > output;
vector< vector<int> > AdjList;

void findBridge(int p){
    dfs_num[p] = dfs_low[p] = dfsCounter++;

    int q;
    for(int i = 0; i < AdjList[p].size(); ++i){
        q = AdjList[p][i];
        if(dfs_num[q] == UNVISITED){
            parent[q] = p;

            findBridge(q);

            if(dfs_low[q] > dfs_num[p]){
                ++ans;
                output.push_back(make_pair(min(p, q), max(p, q)));
                // output.push_back(p);
                // output.push_back(q);
            }

            dfs_low[p] = min(dfs_low[p], dfs_low[q]);
        } else if(q != parent[p]){
            dfs_low[p] = min(dfs_low[p], dfs_num[q]);
        }
    }
}

int main(){ _
    char ch1, ch2;
    while(cin >> n){
        dfs_num.assign(n, UNVISITED);
        dfs_low.assign(n, UNVISITED);
        parent.assign(n, UNVISITED);
        AdjList.assign(n, vector<int> (0));
        output.clear();

        for(int i = 0; i < n; ++i){
            cin >> a >> ch1 >> m >> ch2;
            for(int j = 0; j < m; ++j){
                cin >> b;
                AdjList[a].push_back(b);
                AdjList[b].push_back(a);
            }
        }

        dfsCounter = 0, ans = 0;
        for(int i = 0; i < n; ++i){
            if(dfs_num[i] == UNVISITED){
                // cout << "get here" << endl;
                root = i;
                findBridge(root);
            }
        }

        cout << ans << " critical links" << endl;
        sort(output.begin(), output.end());
        for(int i = 0; i < output.size(); ++i){
            cout << output[i].first << " - " << output[i].second << endl;
        }
        cout << endl;
    }
    return 0;
}
