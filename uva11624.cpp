#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int R, C;
int Jcurr, Jnext, Fcurr, Fnext;
vector< vector<char> > maze;
vector< vector<int> > dist;

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int bfs(queue< ii > *J, queue< ii > *F){
    int r1, c1, r2, c2;
    while(!J[Jcurr].empty() || !F[Fcurr].empty()){
        // first move Joe
        while(!J[Jcurr].empty()){
            r1 = J[Jcurr].front().first;
            c1 = J[Jcurr].front().second;
            J[Jcurr].pop();

            if(maze[r1][c1] == 'F') continue;

            for(int i = 0; i < 4; ++i){
                r2 = r1 + dr[i],    c2 = c1 + dc[i];
                if(r2 < 0 || r2 >= R || c2 < 0 || c2 >= C)  return dist[r1][c1] + 1;
                if(maze[r2][c2] != '.') continue;
                if(dist[r2][c2] != UNVISITED)   continue;

                dist[r2][c2] = dist[r1][c1] + 1;
                J[Jnext].push(ii(r2, c2));
            }
        }
        Jcurr = 1 - Jcurr,  Jnext = 1 - Jnext;

        // then speard fire
        while(!F[Fcurr].empty()){
            r1 = F[Fcurr].front().first;
            c1 = F[Fcurr].front().second;
            F[Fcurr].pop();

            for(int i = 0; i < 4; ++i){
                r2 = r1 + dr[i],    c2 = c1 + dc[i];
                if(r2 < 0 || r2 >= R || c2 < 0 || c2 >= C)  continue;
                if(maze[r2][c2] != '.') continue;

                maze[r2][c2] = 'F';
                F[Fnext].push(ii(r2, c2));
            }
        }
        Fcurr = 1 - Fcurr,  Fnext = 1 - Fnext;
    }

    return -1;
}

int main(){ _
    int tc; cin >> tc;
    while(tc--){
        cin >> R >> C;
        maze.assign(R, vector<char> (C, ' '));
        dist.assign(R, vector<int> (C, UNVISITED));
        queue< ii > J[2], F[2];
        Jcurr = 0, Jnext = 1, Fcurr = 0, Fnext = 1;
        for(int i = 0; i < R; ++i){
            for(int j = 0; j < C; ++j){
                cin >> maze[i][j];
                if(maze[i][j] == 'J'){
                    J[Jcurr].push(ii(i, j));
                    dist[i][j] = 0;
                }
                if(maze[i][j] == 'F'){
                    F[Fcurr].push(ii(i, j));
                }
            }
        }

        int ans = bfs(J, F);
        if(ans == -1)   cout << "IMPOSSIBLE" << endl;
        else    cout << ans << endl;
    }
    return 0;
}
