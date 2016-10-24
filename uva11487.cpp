#include <bits/stdc++.h>
#define UNVISITED -1
#define BIGINT 1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

/* I feel I am not good at converting grids problem to DAG DP problem. */

int N, nChar;
vector< vector<char> > grid;
vector< ii > coord;
int table[26][100][10][10];
const int  MOD = 20437;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int fill_table(int ch, int len, int x, int y){
    if(x < 0 || x >= N || y < 0 || y >= N)  return 0;
    if(grid[x][y] == '#')   return table[ch][len][x][y] = 0;
    if(grid[x][y] > char('A' + ch)) return table[ch][len][x][y] = 0;

    if(table[ch][len][x][y] != -1)  return table[ch][len][x][y];
    if(len == 0 && grid[x][y] != char('A' + ch))    return table[ch][len][x][y] = 0;
    if(grid[x][y] == char('A' + ch) && len == 0)    return table[ch][len][x][y] = 1;

    int nx, ny, ans = 0;
    for(int i = 0; i < 4; ++i){
        nx = x + dx[i], ny = y + dy[i];
        ans += fill_table(ch, len - 1, nx, ny);
    }
    return table[ch][len][x][y] = (ans % MOD);
}

int main(){ _
    int tc = 0;
    while(cin >> N, N){
        cout << "Case " << ++tc << ": ";
        grid.assign(N, vector<char> (N, ' '));
        coord.assign(26, ii(0, 0));
        memset(table, UNVISITED, sizeof table);

        nChar = 0;
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j){
                cin >> grid[i][j];
                if(grid[i][j] >= 'A'){
                    coord[grid[i][j] - 'A'] = ii(i, j);
                    ++nChar;
                }
            }

        for(int i = 0; i < nChar; ++i)
            for(int len = 0; len < 100; ++len)
                for(int x = 0; x < N; ++x)
                    for(int y = 0; y < N; ++y)
                        fill_table(i, len, x, y);

        int length = 0, ways = 1;
        for(int i = 1; i < nChar; ++i){
            bool success = false;
            int x = coord[i - 1].first, y = coord[i - 1].second;
            for(int len = 0; len < 100; ++len){
                if(table[i][len][x][y] != 0){
                    ways *= table[i][len][x][y];
                    ways %= MOD;
                    success = true;
                    length += len;
                    break;
                }
            }
            if(!success){
                ways = 0;
                break;
            }
        }

        if(ways != 0)   cout << length << " " << ways << endl;
        else    cout << "Impossible" << endl;

    }
    return 0;
}
