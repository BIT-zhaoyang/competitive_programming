#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;

int N;
char game[100][100];
bool visited[100][100];

bool dfs(int r, int c){
    bool success = false;
    if(game[r][c] == 'x')   success = true;
    visited[r][c] = true;

    int row = r + 1, col = c + 1;
    if(col < N && (game[r][col] == 'x' || game[r][col] == '@')) success |= dfs(r, col);
    else if(row < N && (game[row][c] == 'x' || game[row][c] == '@')) success |= dfs(row, c);

    return success;
}

int main(){ _
    int TC; cin >> TC;
    for(int tc = 1; tc <= TC; ++tc){
        memset(visited, 0, sizeof visited);

        cin >> N;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                cin >> game[i][j];
            }
        }

        int ans = 0;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(!visited[i][j] && (game[i][j] == 'x' || game[i][j] == '@')){
                    if(dfs(i, j))   ans += 1;
                }
            }
        }

        cout << "Case " << tc << ": " << ans << endl;
    }
    return 0;
}
