#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <climits>
#include <cmath>
#include <set>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <queue>
#include <stack>
#include <tuple>

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

int dr[] = {1,1,0,-1,-1,-1, 0, 1};
int dc[] = {0,1,1, 1, 0,-1,-1,-1};
const int SIZE = 100;

int M, N;
char maze[SIZE][SIZE];
bool visited[SIZE][SIZE];

void dfs(int row, int col){
    visited[row][col] = true;

    int nr, nc;
    for(int i = 0; i < sizeof(dr)/sizeof(int); ++i){
        nr = row + dr[i];
        nc = col + dc[i];

        if(nr < 0 || nr >= M ||
           nc < 0 || nc >= N ||
           visited[nr][nc]   ||
           maze[nr][nc] == '*')    continue;

        dfs(nr, nc);
    }
}

int main(){ _
    while(cin >> M >> N){
        if(M + N == 0)  break;
        memset(visited, false, sizeof visited);

        for(int i = 0; i < M; ++i){
            for(int j = 0; j < N; ++j){
                cin >> maze[i][j];
            }
        }

        int nComponent = 0;
        for(int i = 0; i < M; ++i){
            for(int j = 0; j < N; ++j){
                if(!visited[i][j] && maze[i][j] == '@'){
                    dfs(i, j);
                    ++nComponent;
                }
            }
        }

        cout << nComponent << endl;
    }
    return 0;
}
