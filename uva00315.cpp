#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
#define UNVISITED -1

int N, p, q, root, numChild, dfsCounter;
vector<int> dfs_num;
vector<int> dfs_low;
vector<int> dfs_parent;
vector<bool> artiPoint;
vector< vector<int> > AdjList;

void findAriticulationPoint(int p, int &dfsCounter){
    dfs_num[p] = dfs_low[p] = dfsCounter;
    ++dfsCounter;

    int q;
    for(int i = 0; i < AdjList[p].size(); ++i){
        q = AdjList[p][i];
        if(dfs_num[q] == UNVISITED){
            dfs_parent[q] = p;
            if(p == root)   ++numChild;

            findAriticulationPoint(q, dfsCounter);

            if(dfs_low[q] >= dfs_num[p])    artiPoint[p] = true;
            dfs_low[p] = min(dfs_low[p], dfs_low[q]);
        } else if(dfs_parent[p] != q){
            dfs_low[p] = min(dfs_low[p], dfs_num[q]); //dfs_low(u) stores the lowest **dfs_num** reachable from the current DFS spanning subtree of u
        }
    }
}

int main(){ _
    string str;
    stringstream ss;
    while(cin >> N){
        if(N == 0)  break;

        //  Initialize
        dfs_num.assign(N+1, UNVISITED);
        dfs_low.assign(N+1, 0);
        dfs_parent.assign(N+1, 0);
        artiPoint.assign(N+1, false);
        AdjList.assign(N+1, vector<int> (0));

        //  Read edges
        cin.ignore();
        while(getline(cin, str)){
            if(str == "0")  break;

            ss.clear();
            ss.str("");
            ss << str;

            ss >> p;
            while(ss >> q){
                AdjList[p].push_back(q);
                AdjList[q].push_back(p);
            }
        }

        // Find articulation point
        root = 1, dfsCounter = 0, numChild = 0;
        findAriticulationPoint(root, dfsCounter); // since the graph is fully connected, we only to do this once
        artiPoint[root] = (numChild > 1);

        // output result
        int ans = 0;
        for(int i = 1; i <= N; ++i)
            if(artiPoint[i])    ++ans;
        cout << ans << endl;
    }
    return 0;
}
