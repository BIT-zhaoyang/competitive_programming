#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;

int n, m;
char land;
char world[20][20];
bool visited[20][20];
const int dr[4] = {1, -1, 0, 0};
const int dc[4] = {0, 0, -1, 1};

void dfs(int r, int c, int &size){
    visited[r][c] = true;
    ++size;

    int row, col;
    for(int i = 0; i < 4; ++i){
        row = r + dr[i];
        col = (c + dc[i] + m) % m;

        if(row < 0 || row == n) continue;
        if(world[row][col] != land)  continue;
        if(visited[row][col])   continue;
        dfs(row, col, size);
    }
}

int main(){ _
    while(cin >> n >> m){
        for(int i = 0; i < n; ++i)  for(int j = 0; j < m; ++j)  cin >> world[i][j];
        memset(visited, 0, sizeof visited);
        int r, c, size = 0, ans = 0;
        cin >> r >> c;
        land = world[r][c];
        dfs(r, c, size);

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(world[i][j] == land && !visited[i][j]){
                    size = 0;
                    dfs(i, j, size);
                    ans = max(size, ans);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
