#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
    int C, L;
    while(cin >> C >> L, C){
        vector< vector<int> > AdjList(C + 1, vector<int> (0));
        for(int i = 0; i < L; ++i){
            int u, v;   cin >> u >> v;
            AdjList[u].push_back(v);
            AdjList[v].push_back(u);
        }

        int S, E, D;    cin >> S >> E >> D;
        int pre = 0, cur = 1;
        vector<bool> visited[2];
        visited[pre].assign(C + 1, false);
        visited[pre][S] = true;
        for(int day = 0; day < D; ++day){
            visited[cur].assign(C + 1, false);
            for(int u = 1; u <= C; ++u){
                if(!visited[pre][u])    continue;
                for(int i = 0; i < AdjList[u].size(); ++i){
                    int v = AdjList[u][i];
                    visited[cur][v] = true;
                }
            }
            pre = 1 - pre,  cur = 1 - cur;
        }

        if(visited[pre][E]) cout << "Yes, Teobaldo can travel." << endl;
        else    cout << "No, Teobaldo can not travel." << endl;
    }
    return 0;
}
