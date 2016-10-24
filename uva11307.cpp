#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

const int MAX_COLOR = 6;
vector< vector<int> > AdjList, table;

int solve(int u, int color){
    if(table[u][color] != UNVISITED)    return table[u][color];

    int cost = color + 1;   // our index of color starts from 0, but the value starts from 1
    for(int i = 0; i < AdjList[u].size(); ++i){
        int v = AdjList[u][i], fromSubTree = INT_MAX;
        for(int j = 0; j < MAX_COLOR; ++j){
            if(j == color)  continue;
            fromSubTree = min(fromSubTree, solve(v, j));
        }
        cost += fromSubTree;
    }
    return table[u][color] = cost;
}

int main(){ _
    int n;
    while(cin >> n, n){
        cin.ignore();
        vector<bool> isRoot(n, true);
        AdjList.assign(n, vector<int> (0));
        table.assign(n, vector<int> (MAX_COLOR, UNVISITED));

        for(int i = 0; i < n; ++i){
            string line;
            getline(cin, line);
            int u, v;   char colon;
            stringstream ss(line);
            ss >> u >> colon;
            while(ss >> v){
                AdjList[u].push_back(v);
                isRoot[v] = false;
            }
        }

        int root = -1;
        for(int i = 0; i < isRoot.size(); ++i)
            if(isRoot[i])   root = i;

        int ans = INT_MAX;
        for(int i = 0; i < MAX_COLOR; ++i)
            ans = min(ans, solve(root, i));

        cout << ans << endl;
    }
    return 0;
}
