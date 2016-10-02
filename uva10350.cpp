#include <bits/stdc++.h>
#define UNVISITED -1
#define BIGINT 1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
/*  A highly optimized implementation.
    In this problem, we can only go from lower floor to higher floor. The input is already a DAG. Then ending point is at the highest floor. To reach the k-th floor, we can only go from the (k-1)th floor. Thus, all the unweighted shortest pathes have the same length. Thus, we can update the weighted shortest path layer by layer.
*/

int main(){ _
    string name;
    vector<int> dist[2], value;
    while(cin >> name){
        int n, m;   cin >> n >> m;
        dist[0].assign(m, 0);
        dist[1].assign(m, 0);
        value.assign(m, 0);

        int pre = 0, cur = 1;
        for(int i = 0; i + 1 < n; ++i){
            dist[cur].assign(m, BIGINT);    // update layer by layer
            for(int j = 0; j < m; ++j){     // go from the j-th hole
                for(int k = 0; k < m; ++k){ // to the k-th hole on the next layer
                    cin >> value[k];
                    dist[cur][k] = min(dist[cur][k], dist[pre][j] + value[k]);
                }
            }
            pre = 1 - pre;
            cur = 1 - cur;
        }

        int additional = (n - 1) * 2, ans = BIGINT;
        for(int i = 0; i < m; ++i)
            ans = min(ans, dist[pre][i]);

        cout << name << endl;
        cout << ans + additional << endl;

    }
    return 0;
}
