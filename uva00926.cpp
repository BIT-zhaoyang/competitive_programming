#include <bits/stdc++.h>
#define UNVISITED -1
#define BIGINT 1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
    vector<int64> npath[2];
    bool block[31][31][2];
    int tc; cin >> tc;
    while(tc--){
        int n;  cin >> n;
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        int nblock; cin >> nblock;

        memset(block, 0, sizeof block);
        for(int i = 0; i < nblock; ++i){
            int x, y;   char dir;
            cin >> x >> y >> dir;

            if(dir == 'W')  block[y][x][0] = true;
            else if(dir == 'S') block[y][x][1] = true;
            else if(dir == 'E') block[y][x+1][0] = true;
            else if(dir == 'N') block[y+1][x][1] = true;
        }

        int pre = 0, cur = 1;
        npath[pre].assign(n + 1, 0);
        for(int i = sy; i <= ey; ++i){
            npath[cur].assign(n + 1, 0);
            for(int j = sx; j <= ex; ++j){
                if(i == sy && j == sx){
                    npath[cur][j] = 1;
                    continue;
                }

                if(!block[i][j][0]) npath[cur][j] += npath[cur][j-1];
                if(!block[i][j][1]) npath[cur][j] += npath[pre][j];
            }
            pre = 1 - pre, cur = 1 - cur;
        }

        cout << npath[pre][ex] << endl;
    }
    return 0;
}
