#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
    int n, m, k;
    while(cin >> n >> m >> k){
        if(n == 0)  break;
        vector< vector<int> > AdjList(n, vector<int> (0));
        for(int i = 0; i < m; ++i){
            int u, v;   cin >> u >> v;
            AdjList[u].push_back(v);
        }

        int pre = 0, cur = 1;
        vector<bool> visit[2] = {vector<bool> (n, false), vector<bool> (n, false)};
        visit[pre][0] = true;
        int day = 2;
        while (true) {
            visit[cur].assign(n, false);
            for(int u = 0; u < n; ++u){
                if(!visit[pre][u])  continue;
                for(int i = 0; i < AdjList[u].size(); ++i){
                    int v = AdjList[u][i];
                    visit[cur][v] = true;
                }
            }
            if(visit[cur][n-1] && day >= k)  break;
            if(day > 20) break;
            ++day;

            pre = 1 - pre, cur = 1 - cur;
        }
        if(day > 20) cout << "LOSER" << endl;
        else    cout << day << endl;
    }
    return 0;
}
