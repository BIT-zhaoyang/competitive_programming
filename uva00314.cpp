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

/* This is really an interesting problem! Lot of corner cases... Clever representation of the problem state.

The most important lesson I learned is how to use BFS to compute SSSP. It will be very intuitive if the states have physical relation meaning but it's not necessary. To use BFS to compute SSSP, especially on problems without explicit graph structure, we need to find problem states having exactly 1 unit cost!

In other words, if a problem is to compute nStep or something related to this, and each action takes 1 unit time.(The action may be of different, for example, move & turn direction.) Then, probably this problem is solvable by BFS.
*/

const int dx[] = {-1, 0, 1, 0}; // direction {north, west, south, east}
const int dy[] = {0, -1, 0, 1};

queue< tuple<int, int, int> > Q;

int M, N, num;
bool board[51][51];
int state[51][51][4];

void bfs(tuple<int, int, int> source){
    int x1, y1, dir1, x2, y2, dir2;
    Q.push(source);
    tie(x1, y1, dir1) = source;
    state[x1][y1][dir1] = 0;

    while(!Q.empty()){
        tie(x1, y1, dir1) = Q.front();  Q.pop();
        for(int i = 1; i <= 3; ++i){    // go along this direction, takes 1 minute
            x2 = x1 + dx[dir1] * i, y2 = y1 + dy[dir1] * i;
            dir2 = dir1;
            if(x2 <= 0 || x2 >= M || y2 <= 0 || y2 >= N)    continue;
            if(board[x2][y2])   break;
            if(state[x2][y2][dir2]== UNVISITED){
                state[x2][y2][dir2] = state[x1][y1][dir1] + 1;
                Q.push(make_tuple(x2, y2, dir2));
            }
        }

        // turn left & right, takes 1 minute
        x2 = x1,    y2 = y1;
        dir2 = (dir1 + 1) % 4;
        if(state[x2][y2][dir2] == UNVISITED){
            state[x2][y2][dir2] = state[x1][y1][dir1] + 1;
            Q.push(make_tuple(x2, y2, dir2));
        }
        dir2 = (dir1 + 4 - 1) % 4;
        if(state[x2][y2][dir2] == UNVISITED){
            state[x2][y2][dir2] = state[x1][y1][dir1] + 1;
            Q.push(make_tuple(x2, y2, dir2));
        }
    }
}

int main(){ _
    while(cin >> M >> N){
        if(M == 0 && N == 0)    break;
        memset(state, UNVISITED, sizeof state);
        memset(board, false, sizeof board);
        for(int i = 0; i < M; ++i){
            for(int j = 0; j < N; ++j){
                cin >> num;
                if(num == 1) board[i][j] = board[i][j+1] = board[i+1][j] = board[i+1][j+1] = true;
            }
        }

        // cout << "get here?" << endl;
        int sx, sy, tx, ty, dir; cin >> sx >> sy >> tx >> ty;
        string str; cin >> str;
        if(str == "south")  dir = 2;
        else if(str == "north") dir = 0;
        else if(str == "east")  dir = 3;
        else    dir = 1;

        bfs(make_tuple(sx, sy, dir));
        int ans = INT_MAX;
        for(int i = 0; i < 4; ++i)
            if(state[tx][ty][i] != UNVISITED)
                ans = min(ans, state[tx][ty][i]);

        if(ans == INT_MAX)  cout << -1 << endl;
        else    cout << ans << endl;
    }
    return 0;
}
