#include <bits/stdc++.h>
#define UNVISITED -1
#define BIGINT 1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

stack<int> si;
vector<int> weight, dist;
vector< vector<int> > AdjList;

void topoSort(int u){
    dist[u] = weight[u];
    for(int i = 0; i < AdjList[u].size(); ++i){
        int v = AdjList[u][i];
        if(dist[v] == -1)
            topoSort(v);
    }
    si.push(u);
}

int main(){ _
    int tc; cin >> tc;  cin.ignore();
    string line;   getline(cin, line);
    while(tc--){
        weight.assign(26, -1);
        dist.assign(26, -1);
        AdjList.assign(26, vector<int> (0));
        while(getline(cin, line)){
            if(line == "")  break;
            stringstream ss(line);
            char node, parent;
            ss >> node;
            ss >> weight[node - 'A'];
            while(ss >> parent)
                AdjList[parent - 'A'].push_back(node - 'A');
        }

        // topo sort
        for(int i = 0; i < 26; ++i)
            if(weight[i] != -1 && dist[i] == -1)
                topoSort(i);

        // update according to topo sort
        while(!si.empty()){
            int u = si.top();
            si.pop();
            for(int i = 0; i < AdjList[u].size(); ++i){
                int v = AdjList[u][i];
                dist[v] = max(dist[v], dist[u] + weight[v]);
            }
        }
        int ans = 0;
        for(int i = 0; i < 26; ++i) ans = max(ans, dist[i]);
        cout << ans << endl;
        if(tc)  cout << endl;
    }
    return 0;
}
