#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int n, furtherst;
vector< vector<int> > AdjList;
vector<int> dist;

void dfs(int u, int len){
    dist[u] = len;
    furtherst = max(furtherst, len);
    for(int i = 0; i < AdjList[u].size(); ++i){
        int v = AdjList[u][i];
        if(dist[v] == UNVISITED)    dfs(v, len + 1);
    }
}

int main(){ _
    while(cin >> n){
        AdjList.assign(n + 1, vector<int> (0));
        dist.assign(n + 1, UNVISITED);
        for(int u = 1; u <= n; ++u){
            int m, v;  cin >> m;
            for(int i = 0; i < m; ++i){
                cin >> v;
                AdjList[u].push_back(v);
            }
        }

        int root = 1;
        furtherst = 0;
        dfs(root, 0);  // find furtherst nodes from an arbitrary root, here select it to be 1

        set<int> worst;  // Find potential worst nodes. These nodes must all have the same
        for(int i = 1; i <= n; ++i) // dist to the arbitrarily selected nodes, according to the
            if(dist[i] == furtherst) // idea behind find diameter of a tree.
                worst.insert(i);

        root = *(worst.begin());
        furtherst = 0;
        dist.assign(n + 1, UNVISITED);
        dfs(root, 0);   // Use one worst nodes as new root is enough
        int end = 0;    // Then find another end using current new root.
        for(int i = 1; i <= n; ++i)
            if(dist[i] == furtherst){
                worst.insert(i);
                end = i;
            }

        vector<int> copy = dist;
        root = end;
        dist.assign(n + 1, UNVISITED);
        furtherst = 0;
        dfs(root, 0);

        // now we need to find best
        cout << "Best Roots  :";
        for(int i = 1 ; i <= n; ++i){
            if(dist[i] == 0 || copy[i] == 0)    continue;
            if(dist[i] + copy[i] == furtherst && abs(dist[i] - copy[i]) <= 1)
                cout << " " << i;
        }
        cout << endl;

        cout << "Worst Roots :";
        for(auto it = worst.begin(); it != worst.end(); ++it)
            cout << " " << *it;
        cout << endl;

    }
    return 0;
}
