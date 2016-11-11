#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

map<int, bool> nodes;
map<int, vector<int> > AdjList;

bool process(){
    if(nodes.size() == 0)   return true;

    int root = -1;
    for(auto it = nodes.begin(); it != nodes.end(); ++it)
        if(it->second){
            root = it->first;
            break;
        }
    if(root == -1){
        // cout << "no root" << endl;
        return false;
    }

    queue<int> Q;
    Q.push(root);
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        // "nodes.count(u) == 0" means 'u' has already been visited
        if(nodes.count(u) == 0){
            // cout << "loop happens when visiting node " << u <<endl;
            return false;
        } else {
            nodes.erase(u);
        }
        for(int i = 0; i < AdjList[u].size(); ++i){
            int v = AdjList[u][i];
            Q.push(v);
        }
    }

    return (nodes.size() == 0);
}

void init(){
    nodes.clear();
    AdjList.clear();
}

int main(){ _
    int u, v, tc = 0;
    init();
    while(cin >> u >> v){
        if(u < 0 && v < 0)  break;
        if(u == 0 && v == 0){
            bool valid = process();
            if(valid)   cout << "Case " << ++tc << " is a tree." << endl;
            else    cout << "Case " << ++tc << " is not a tree." << endl;
            init();
        } else {
            AdjList[u].push_back(v);
            if(nodes.count(u) == 0) nodes[u] = true;
            nodes[v] = false;
        }
    }
    return 0;
}
