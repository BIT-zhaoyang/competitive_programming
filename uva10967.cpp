#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

int n, m;
char maze[101][101];
int T[101][101];
vector< ii > doorLoc;
vector< vector<int> > dist;
priority_queue< iii, vector< iii >, greater< iii > > pq;

const int dx[] = {-1, 0, 1, 0}; // N, E, S, W
const int dy[] = {0, 1, 0, -1};
const char oppOri[] = {'S', 'W', 'N', 'E'}; // opposite orientation corresponding to above direcs

void dijkstra(int x1, int y1){
    int x2, y2, d1, d2;
    d1 = 0;
    dist[x1][y1] = d1;
    pq.push(iii(d1, x1, y1));

    int extra = 0, currOri;
    while(!pq.empty()){
        tie(d1, x1, y1) = pq.top();
        pq.pop();
        if(d1 > dist[x1][y1])   continue;
        for(int i = 0; i < 4; ++i){
            x2 = x1 + dx[i],    y2 = y1 + dy[i];
            if(x2 < 0 || x2 >= n || y2 < 0 || y2 >= m)  continue;
            if(maze[x2][y2] == '#')    continue;
            if(maze[x2][y2] != '.' && maze[x2][y2] != oppOri[i])    continue;

            switch(maze[x1][y1]){   // current orientation
                case 'N': currOri = 0;  break;
                case 'E': currOri = 1;  break;
                case 'S': currOri = 2;  break;
                case 'W': currOri = 3;  break;
                case '.': currOri = i;  break;
            }

            extra = abs(currOri - i);
            extra = min(extra, 4 - extra);
            extra *= T[x1][y1];

            d2 = d1 + 1 + extra;
            if(d2 < dist[x2][y2]){
                dist[x2][y2] = d2;
                pq.push(iii(d2, x2, y2));
            }
        }
    }
}

int main(){ _
    memset(T, -1, sizeof T);
    int tc; cin >> tc;
    while(tc--){
        cin >> n >> m;
        doorLoc.clear();
        dist.assign(n, vector<int> (m, INT_MAX));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cin >> maze[i][j];
                if(maze[i][j] != '.' && maze[i][j] != '#')  doorLoc.push_back(ii(i, j));
            }
        }
        for(int i = 0; i < doorLoc.size(); ++i){
            int x = doorLoc[i].first,   y = doorLoc[i].second;
            cin >> T[x][y];
        }

        dijkstra(n-1, 0);

        if(dist[0][m-1] == INT_MAX) cout << "Poor Kianoosh" << endl;
        else    cout << dist[0][m-1] << endl;
    }
    return 0;
}
