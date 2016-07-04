#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
using namespace std;

typedef long long int64;

int n, m, root, numRootChild, dfsCounter;
vector<int> dfs_num, dfs_low, parent;
vector< vector<int> > AdjList;

void findBridges(int p){
    dfs_num[p] = dfs_low[p] = dfsCounter++;

    int q;
    for(int i = 0; i < AdjList[p].size(); ++i){
        q = AdjList[p][i];

        if(dfs_num[q] == UNVISITED){
            parent[q] = p;

            findBridges(q);

            if(dfs_low[q] > dfs_num[p]){
                cout << p << " " << q << endl;
                cout << q << " " << p << endl;
            } else {
                cout << p << " " << q << endl;
            }

            dfs_low[p] = min(dfs_low[p], dfs_low[q]);
        } else if(q != parent[p]){
            if(dfs_num[q] < dfs_num[p]) cout << p << " " << q << endl;
            dfs_low[p] = min(dfs_low[p], dfs_num[q]);
        }
    }
}

int main(){ _
    int tc = 0;
    while(cin >> n >> m){
        if(n + m == 0)  break;
        // output header
        cout << ++tc << endl << endl;

        // Initialize
        dfs_num.assign(n+1, UNVISITED);
        dfs_low.assign(n+1, 0);
        parent.assign(n+1, 0);
        AdjList.assign(n+1, vector<int> (0));

        // read edges
        int a, b;
        for(int i = 0; i < m; ++i){
            cin >> a >> b;
            AdjList[a].push_back(b);
            AdjList[b].push_back(a);
        }

        // find bridges
        root = 1, dfsCounter = 0, numRootChild = 0;
        findBridges(root);
        cout << "#" << endl;
    }
    return 0;
}
