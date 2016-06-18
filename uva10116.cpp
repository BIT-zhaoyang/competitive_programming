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

int nR, nC, sC;
char maze[11][11];
int dist[11][11];
const int dr[] = {-1, 0, 1, 0}; // N, E, S, W
const int dc[] = {0, 1, 0, -1};

bool dfs(int r, int c, int& d, int& lenLoop){
    if(r == 0 || c == 0 || r > nR || c > nC)    return true;
    if(dist[r][c] != 0){
        lenLoop = d - dist[r][c];
        return false;
    }

    dist[r][c] = d;
    switch (maze[r][c]) {
        case 'N':   r = r + dr[0];  c = c + dc[0];  break;
        case 'E':   r = r + dr[1];  c = c + dc[1];  break;
        case 'S':   r = r + dr[2];  c = c + dc[2];  break;
        case 'W':   r = r + dr[3];  c = c + dc[3];  break;
    }

    d += 1;
    return dfs(r, c, d, lenLoop);
}

int main(){ _
    while(cin >> nR >> nC >> sC){
        if(nR + nC + sC == 0)   break;

        for(int i = 1; i <= nR; ++i){
            for(int j = 1; j <= nC; ++j){
                cin >> maze[i][j];
            }
        }

        memset(dist, 0, sizeof dist);

        int lenLoop = 0, d = 1;
        if(dfs(1, sC, d, lenLoop))  cout << d-1 << " step(s) to exit" << endl;
        else    cout << d-1-lenLoop << " step(s) before a loop of " << lenLoop << " step(s)" << endl;

    }
    return 0;
}
