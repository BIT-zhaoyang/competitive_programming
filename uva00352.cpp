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

int N;
char maze[25][25];
bool visited[25][25];

void dfs(int row, int col){
    visited[row][col] = true;

    int nr, nc;
    for(int i = 0; i < sizeof(dr)/sizeof(int); ++i){
        nr = row + dr[i];
        nc = col + dc[i];

        if(nr < 0 || nr >= N ||
           nc < 0 || nc >= N ||
           visited[nr][nc]   ||
           maze[nr][nc] == '0')    continue;

        dfs(nr, nc);
    }
}

int main(){ _
    int count = 0;
    while(cin >> N){
        cout << "Image number " << ++count << " contains ";
        memset(visited, false, sizeof visited);

        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                cin >> maze[i][j];
            }
        }

        int nComponent = 0;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(!visited[i][j] && maze[i][j] == '1'){
                    dfs(i, j);
                    ++nComponent;
                }
            }
        }

        cout << nComponent << " war eagles." << endl;
    }
    return 0;
}
