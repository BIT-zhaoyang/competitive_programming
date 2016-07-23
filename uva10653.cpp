#include <algorithm>
#include <bitset>
#include <cstring>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <sstream>
#include <vector>

#define UNVISITED -1
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
vector< vector<bool> > mines;
vector< vector<int> > dist;
queue< ii > Q;
int R, C;

const int dr[] = {1, -1, 0, 0};
const int dc[] = {0, 0, -1, 1};

void bfs(int sx, int sy){
    Q.push(ii(sx, sy)); dist[sx][sy] = 0;
    ii p, q;    int nx, ny;
    while(!Q.empty()){
        p = Q.front();  Q.pop();
        for(int i = 0; i < 4; ++i){
            nx = p.first + dr[i];
            ny = p.second + dc[i];
            if(nx >= 0 && nx < R && ny >= 0 && ny < C && !mines[nx][ny] && dist[nx][ny] == UNVISITED){
                dist[nx][ny] = dist[p.first][p.second] + 1;
                Q.push(ii(nx, ny));
            }
        }
    }
}

int main(){ _

    while(cin >> R >> C){
        if(R == 0 && C == 0)    break;
        mines.assign(R, vector<bool> (C, false));
        dist.assign(R, vector<int> (C, UNVISITED));
        int n, m, r, c;
        cin >> n;
        for(int i = 0; i < n; ++i){
            cin >> r >> m;
            for(int j = 0; j < m; ++j){
                cin >> c;
                mines[r][c] = true;
            }
        }

        int sx, sy, tx, ty;
        cin >> sx >> sy >> tx >> ty;
        bfs(sx, sy);
        cout << dist[tx][ty] << endl;
    }
    return 0;
}
