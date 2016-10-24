#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
/* The transation functions are really error prone to analysis! Top-down implementation is better than bottom-up in this problem. */

// direction: down, left, right
const int MAXN = 80, MAXK = 10, NDIR = 3;
const int dr[] = {1, 0, 0};
const int dc[] = {0, -1, 1};

int N, K, recurN;
int value[MAXN][MAXN], dp[MAXN][MAXN][MAXK][NDIR];
bool visited[MAXN][MAXN][MAXK][NDIR];

int solve(int r, int c, int k, int dir){
    if(r >= N || c < 0 || c >= N) return INT_MIN;
    if(visited[r][c][k][dir]) return dp[r][c][k][dir];
    int nk = k + (value[r][c] < 0);
    if(nk > K)  return INT_MIN;
    if(r + 1 == N && c + 1 == N)    return value[r][c];


    int ans = INT_MIN, nr, nc;
    for(int i = 0; i < NDIR; ++i){
        if(i + dir == NDIR) continue;
        nr = r + dr[i], nc = c + dc[i];
        int temp = solve(nr, nc, nk, i);
        if(temp != INT_MIN) ans = max(ans, temp + value[r][c]);
    }

    visited[r][c][k][dir] = true;
    return dp[r][c][k][dir] = ans;
}

int main(){ _
    int tc = 0;
    while(cin >> N >> K, N){
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                cin >> value[i][j];

        memset(visited, false, sizeof visited);
        int ans = solve(0, 0, 0, 0);

        cout << "Case " << ++tc << ": ";
        if(ans != INT_MIN)  cout << ans << endl;
        else    cout << "impossible" << endl;
    }
    return 0;
}
