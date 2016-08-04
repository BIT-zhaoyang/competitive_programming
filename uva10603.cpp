#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
typedef tuple<int, int, int, int> iiii;

#define maxCap 201

int full[3], curr[3], nextValue[3], ans[maxCap];
int dist[maxCap][maxCap][maxCap];
priority_queue< iiii, vector< iiii >, greater< iiii > > pq;

void dijkstra(){
    dist[curr[0]][curr[1]][curr[2]] = 0;
    pq.push(iiii(0, curr[0], curr[1], curr[2]));
    for(int i = 0; i < 3; ++i)  ans[curr[i]] = min(ans[curr[i]], 0);

    int d1, d2, p;
    while(!pq.empty()){
        tie(d1, curr[0], curr[1], curr[2]) = pq.top();  pq.pop();
        if(d1 > dist[curr[0]][curr[1]][curr[2]])    continue;
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                if(i == j)  continue;
                nextValue[0] = curr[0], nextValue[1] = curr[1], nextValue[2] = curr[2];

                p = min(curr[i], full[j] - curr[j]);
                nextValue[i] = curr[i] - p,  nextValue[j] = curr[j] + p, d2 = p;
                if(d1 + d2 < dist[nextValue[0]][nextValue[1]][nextValue[2]]){
                    pq.push(iiii(d1 + d2, nextValue[0], nextValue[1], nextValue[2]));
                    dist[nextValue[0]][nextValue[1]][nextValue[2]] = d1 + d2;
                    for(int i = 0; i < 3; ++i)  // this state compression is great
                        ans[nextValue[i]] = min(ans[nextValue[i]], d1 + d2);
                }
            }
        }
    }
}

int main(){ _
    int tc; cin >> tc;
    while(tc--){
        int target;
        for(int i = 0; i < 3; ++i)  cin >> full[i];     cin >> target;

        fill(ans, ans + maxCap, INT_MAX);
        for(int i = 0; i <= full[0]; ++i)
            for(int j = 0; j <= full[1]; ++j)
                for(int k = 0; k <= full[2]; ++k)
                    dist[i][j][k] = INT_MAX;

        curr[0] = 0, curr[1] = 0, curr[2] = full[2];
        dijkstra();
        if(ans[target] == INT_MAX){
            for(int i = target - 1; i >= 0; --i){
                if(ans[i] != INT_MAX){
                    cout << ans[i] << " " << i << endl;
                    break;
                }
            }
        } else {
            cout << ans[target] << " " << target << endl;
        }

    }
    return 0;
}
