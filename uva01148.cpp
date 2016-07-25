#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

vector< vector<int> > AdjList;
vector<int> bfs_num;
queue<int> Q;

void bfs(int source){
    Q.push(source); bfs_num[source] = 0;
    int p, q;
    while(!Q.empty()){
        p = Q.front();  Q.pop();
        for(int i = 0; i < AdjList[p].size(); ++i){
            q = AdjList[p][i];
            if(bfs_num[q] == UNVISITED){
                bfs_num[q] = bfs_num[p] + 1;
                Q.push(q);
            }
        }
    }
}

int main(){ _
    int tc; cin >> tc;
    while(tc--){
        int n, m, u, v;  cin >> n;
        AdjList.assign(n, vector<int> (0));
        for(int i = 0; i < n; ++i){
            cin >> u >> m;
            for(int j = 0; j < m; ++j){
                cin >> v;
                AdjList[u].push_back(v);
            }
        }

        int source, target; cin >> source >> target;
        bfs_num.assign(n, UNVISITED);
        bfs(source);
        cout << source << " " << target << " " << bfs_num[target] - 1<< endl;
        if(tc)  cout << endl;
    }
    return 0;
}
