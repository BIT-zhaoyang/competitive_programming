#include <algorithm>
#include <bitset>
#include <cstring>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <sstream>
#include <vector>

#define UNVISITED -1
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

const int dl[] = {1, -1, 0, 0, 0, 0};
const int dr[] = {0, 0, 1, 0, -1, 0};
const int dc[] = {0, 0, 0, 1, 0, -1};


int L, R, C;
int dist[30][30][30];
char space[30][30][30];

queue< tuple<int, int, int> > Q;

void bfs(int l1, int r1, int c1){
    Q.push(make_tuple(l1, r1, c1));
    dist[l1][r1][c1] = 0;
    int l2, r2, c2;
    while(!Q.empty()){
        tie(l1, r1, c1) = Q.front();    Q.pop();
        for(int i = 0; i < 6; ++i){
            l2 = l1 + dl[i],    r2 = r1 + dr[i],    c2 = c1 + dc[i];
            if(l2 < 0 || l2>= L || c2 < 0 || c2 >= C || r2 < 0 || r2 >= R)  continue;
            if(space[l2][r2][c2] != '#' && dist[l2][r2][c2] == UNVISITED){
                dist[l2][r2][c2] = dist[l1][r1][c1] + 1;
                Q.push(make_tuple(l2, r2, c2));
            }
        }
    }
}

int main(){ _
    int sl, sr, sc, tl, tr, tc;
    while(cin >> L >> R >> C){
        if(L == 0 && R == 0 && C == 0)  break;
        memset(dist, UNVISITED, sizeof dist);
        for(int i = 0; i < L; ++i){
            for(int j = 0; j < R; ++j){
                for(int k = 0; k < C; ++k){
                    cin >> space[i][j][k];
                    if(space[i][j][k] == 'S')   sl = i, sr = j, sc = k;
                    if(space[i][j][k] == 'E')   tl = i, tr = j, tc = k;
                }
            }
        }

        bfs(sl, sr, sc);
        if(dist[tl][tr][tc] == UNVISITED)   cout << "Trapped!" << endl;
        else    cout << "Escaped in " << dist[tl][tr][tc] << " minute(s)." << endl;
    }
    return 0;
}
