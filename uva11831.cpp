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

char maze[101][101];
const int dr[] = {-1, 0, 1, 0};    // N, E, S, W
const int dc[] = {0, 1, 0, -1};

int main(){ _
    int nR, nC, S;
    while(cin >> nR >> nC >> S){
        if(nR + nC + S == 0)    break;

        int sr, sc, dir;
        for(int r = 1; r <= nR; ++r){
            for(int c = 1; c <= nC; ++c){
                cin >> maze[r][c];
                switch (maze[r][c]) {
                    case 'N':
                        sr = r; sc = c; dir = 0;
                        break;
                    case 'S':
                        sr = r; sc = c; dir = 2;
                        break;
                    case 'L':
                        sr = r; sc = c; dir = 1;
                        break;
                    case 'O':
                        sr = r; sc = c; dir = 3;
                        break;
                    default:
                        break;
                }
            }
        }

        char op;
        int nr, nc, ans = 0;
        while(S--){
            cin >> op;
            switch (op) {
                case 'D':   dir = (dir+1)%4;    break;
                case 'E':   dir = (dir+3)%4;    break;
                case 'F':
                    nr = sr + dr[dir];
                    nc = sc + dc[dir];
                    if(nr == 0 || nr > nR || nc == 0 || nc > nC)  break;
                    if(maze[nr][nc] == '#') break;
                    if(maze[nr][nc] == '*'){
                        ++ans;
                        maze[nr][nc] = '.';
                    }
                    sr = nr;
                    sc = nc;
                    break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
