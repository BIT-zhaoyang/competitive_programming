#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
vector< vector<int> > dist;
vector< vector<bool> > block;
queue< ii > Q;
int R, C;

const int dr[] = {1, -1, 0, 0};
const int dc[] = {0, 0, -1, 1};

void bfs(int r1, int c1){
    Q.push(ii(r1, c1)); dist[r1][c1] = 0;
    ii p, q;    int r2, c2;
    while(!Q.empty()){
        p = Q.front();  Q.pop();
        r1 = p.first,   c1 = p.second;
        for(int i = 0; i < 4; ++i){
            r2 = r1 + dr[i],    c2 = c1 + dc[i];
            if(r2 == 0 || r2 > R || c2 == 0 || c2 > C)   continue;
            if(block[r2][c2])   continue;
            if(dist[r2][c2] != UNVISITED)   continue;

            dist[r2][c2] = dist[r1][c1] + 1;
            Q.push(ii(r2, c2));
        }
    }
}

int main(){ _
    int nb, nJ, L, r, c;
    while(cin >> R >> C){
        if(R == 0)  break;

        block.assign(R+1, vector<bool> (C+1, false));
        dist.assign(R+1, vector<int> (C+1, UNVISITED));

        cin >> nb;
        for(int i = 0; i < nb; ++i){
            cin >> r >> c;
            block[r][c] = true;
        }

        cin >> nJ;
        int dx, dy;
        for(int k = 0; k < nJ; ++k){
            cin >> r >> c >> L;     L *= L;
            for(int i = 1; i <= R; ++i){
                for(int j = 1; j <= C; ++j){
                    dx = i - r, dy = j - c;
                    if(dx*dx + dy*dy <= L)  block[i][j] = true;
                }
            }
        }

        bfs(1, 1);
        if(dist[R][C] == UNVISITED) cout << "Impossible." << endl;
        else    cout << dist[R][C] << endl;
    }
    return 0;
}
