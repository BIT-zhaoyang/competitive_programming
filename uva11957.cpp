#include <bits/stdc++.h>
#define UNVISITED -1
#define BIGINT 1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

vector< vector<char> > board;
vector< vector<int64> > ways;

bool valid(int x, int y, int n){
    return x >= 0 && x < n && y >= 0 && y < n;
}

int main(){ _
    const int MOD = 1000007;
    int TC; cin >> TC;
    for(int tc = 1; tc <= TC; ++tc){
        cout << "Case " << tc << ": ";
        int n;  cin >> n;
        board.assign(n, vector<char> (n, ' '));
        ways.assign(n, vector<int64> (n, 0));

        for(int y = n - 1; y >= 0; --y)
            for(int x = 0; x < n; ++x){
                cin >> board[y][x];
                if(board[y][x] == 'W')  ways[y][x] = 1;
            }

        int nx, ny;
        for(int y = 0; y + 1 < n; ++y){
            for(int x = 0; x < n; ++x){
                nx = x - 1, ny = y + 1;
                if(valid(nx, ny, n) && board[ny][nx] != 'B'){
                    ways[ny][nx] += ways[y][x];
                    ways[ny][nx] %= MOD;
                } else if(valid(nx, ny, n) && board[ny][nx] == 'B'){
                    nx = x - 2, ny = y + 2;
                    if(valid(nx, ny, n) && board[ny][nx] != 'B'){
                        ways[ny][nx] += ways[y][x];
                        ways[ny][nx] %= MOD;
                    }
                }

                nx = x + 1, ny = y + 1;
                if(valid(nx, ny, n) && board[ny][nx] != 'B'){
                    ways[ny][nx] += ways[y][x];
                    ways[ny][nx] %= MOD;
                } else if(valid(nx, ny, n) && board[ny][nx] == 'B'){
                    nx = x + 2, ny = y + 2;
                    if(valid(nx, ny, n) && board[ny][nx] != 'B'){
                        ways[ny][nx] += ways[y][x];
                        ways[ny][nx] %= MOD;
                    }
                }
            }
        }

        int64 ans = 0;
        for(int i = 0; i < n; ++i){
            ans += ways[n - 1][i];
            ans %= MOD;
        }
        cout << ans << endl;
    }
    return 0;
}
