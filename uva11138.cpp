#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;


vector<bool> visited;
vector<int> match;
vector< vector<int> > AdjList;

int aug_path(int u){
    if(visited[u])  return 0;
    visited[u] = true;
    for(auto v : AdjList[u])
        if(match[v] == -1 || aug_path(match[v])){
            match[v] = u;
            return 1;
        }
    return 0;
}

int main(){ _
    int TC; cin >> TC;
    for(int tc = 1; tc <= TC; ++tc){
        int n, m;
        cin >> n >> m;
        AdjList.assign(n, vector<int> (0));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j){
                int num;    cin >> num;
                if(num) AdjList[i].push_back(j);
            }

        match.assign(m, -1);
        int MCBM = 0;
        for(int i = 0; i < n; ++i){
            visited.assign(n, false);
            MCBM += aug_path(i);
        }
        cout << "Case " << tc << ": a maximum of " << MCBM
             << " nuts and bolts can be fitted together" << endl;
    }
    return 0;
}
