#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

int n, m;
vector< vector<int> > maze, dist;
priority_queue< iii, vector< iii >, greater< iii > > pq;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

void dijkstra(int sx, int sy, int sd){
    pq.push(iii(sd, sx, sy));
    dist[sx][sy] = sd;

    int x1, y1, d1, x2, y2, d2;
    while(!pq.empty()){
        tie(d1, x1, y1) = pq.top();
        pq.pop();
        if(dist[x1][y1] < d1)   continue;
        for(int i = 0; i < 4; ++i){
            x2 = x1 + dx[i];
            y2 = y1 + dy[i];
            if(x2 < 0 || x2 >= n || y2 < 0 || y2 >= m)  continue;
            d2 = maze[x2][y2];

            if(d1 + d2 < dist[x2][y2]){
                dist[x2][y2] = d1 + d2;
                pq.push(iii(dist[x2][y2], x2, y2));
            }
        }
    }
}

int main(){ _
    int tc; cin >> tc;
    while(tc--){
        cin >> n >> m;
        maze.assign(n, vector<int> (m, 0));
        dist.assign(n, vector<int> (m, INT_MAX));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                cin >> maze[i][j];

        dijkstra(0, 0, maze[0][0]);

        cout << dist[n-1][m-1] << endl;
    }
    return 0;
}
