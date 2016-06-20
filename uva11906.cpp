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

int grids[100][100];
bool visited[100][100];
const int dr[] = {1, 1, -1, -1};
const int dc[] = {1, -1, 1, -1};
int nR, nC, M, N;

void dfs(int r, int c, int& odd, int& even){
    visited[r][c] = true;
    if(grids[r][c]%2)   ++odd;
    else    ++even;

    int nr, nc;
    for(int i = 0; i < 4; ++i){
        nr = r + dr[i]*M;
        nc = c + dc[i]*N;
        if(nr < 0 || nr >= nR || nc < 0 || nc >= nC)    continue;
        if(grids[nr][nc] == -1) continue;
        if(visited[nr][nc]) continue;
        dfs(nr, nc, odd, even);
    }

    for(int i = 0; i < 4; ++i){
        nr = r + dr[i]*N;
        nc = c + dc[i]*M;
        if(nr < 0 || nr >= nR || nc < 0 || nc >= nC)    continue;
        if(grids[nr][nc] == -1) continue;
        if(visited[nr][nc]) continue;
        dfs(nr, nc, odd, even);
    }
}

int main(){ _
    int TC; cin >> TC;
    for(int tc = 1; tc <= TC; ++tc){
        cout << "Case " << tc << ": ";

        cin >> nR >> nC >> M >> N;
        memset(grids, 0, sizeof grids);
        memset(visited, 0, sizeof visited);

        int nWater; cin >> nWater;
        for(int i = 0; i < nWater; ++i){
            int x, y;   cin >> x >> y;
            grids[x][y] = -1;
        }

        int odd = 0, even = 0, nr, nc;
        for(int r = 0; r < nR; ++r){
            for(int c = 0; c < nC; ++c){
                if(grids[r][c] == -1)   continue;
                for(int i = 0; i < 4; ++i){
                    nr = r + dr[i]*M;
                    nc = c + dc[i]*N;
                    if(nr < 0 || nr >= nR || nc < 0 || nc >= nC)    continue;
                    if(grids[nr][nc] == -1) continue;
                    grids[r][c] += 1;
                }

                for(int i = 0; i < 4; ++i){
                    nr = r + dr[i]*N;
                    nc = c + dc[i]*M;
                    if(nr < 0 || nr >= nR || nc < 0 || nc >= nC)    continue;
                    if(grids[nr][nc] == -1) continue;
                    grids[r][c] += 1;
                }

                if(M == 0 || N == 0 || M == N)  grids[r][c] /= 2;
            }
        }

        dfs(0, 0, odd, even);
        // for(int i = 0; i < nR; ++i){
        //     for(int j = 0; j < nC; ++j){
        //         cout << grids[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        cout << even << " " << odd << endl;
    }
    return 0;
}
