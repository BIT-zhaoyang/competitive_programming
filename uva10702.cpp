#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
    int C, S, E, T;
    while(cin >> C >> S >> E >> T, C){
        vector< vector<int> > AdjList(C + 1, vector<int> (C + 1, 0));
        for(int i = 1; i <= C; ++i)
            for(int j = 1; j <= C; ++j)
                cin >> AdjList[i][j];

        vector<int> ends(E, 0);
        for(int i = 0; i < E; ++i)
            cin >> ends[i];

        int pre = 0, cur = 1;
        vector<int> profit[2];
        profit[pre] = AdjList[S];
        for(int t = 1; t < T; ++t){
            profit[cur].assign(C + 1, 0);

            for(int i = 0; i < C + 1; ++i)
                for(int j = 0; j < C + 1; ++j)
                    profit[cur][j] = max(profit[cur][j],
                            profit[pre][i] + AdjList[i][j]);

            pre = 1 - pre,  cur = 1 - cur;
        }

        int ans = 0;
        for(int i = 0; i < E; ++i)
            ans = max(ans, profit[pre][ends[i]]);
        cout << ans << endl;
    }
    return 0;
}
