#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
    int N, K;
    vector<int> dist, plan;
    while(cin >> N >> K){
        dist.assign(N + 2, 0);
        for(int i = 1; i <= N + 1; ++i){
            cin >> dist[i];
            dist[i] += dist[i-1];
        }

        plan.assign(N + 2, BIGINT);
        plan[0] = 0;
        for(int day = 0; day < K + 1; ++day)
            for(int camp = N + 1; camp > 0; --camp){
                plan[camp] = BIGINT;
                for(int last = camp; last >= 0; --last)
                    plan[camp] = min(plan[camp],
                                     max(plan[last], dist[camp] - dist[last]));
            }

        cout << plan[N + 1] << endl;
    }
    return 0;
}
