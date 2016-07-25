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
set< tuple<int, int, int, int> > blocks;
int dist[6][6];
char direction[6][6];
queue< ii > Q;
vector< vector< ii > > parent;

const int dr[] = {1, -1, 0, 0};
const int dc[] = {0, 0, -1, 1};
const char dir[] = {'S', 'N', 'W', 'E'};

void bfs(int r1, int c1){
    Q.push(ii(r1, c1)); dist[r1][c1] = 0;   direction[r1][c1] = 'A';

    ii p;   int r2, c2;
    while(!Q.empty()){
        p = Q.front();  Q.pop();
        r1 = p.first,   c1 = p.second;
        for(int i = 0; i < 4; ++i){
            r2 = r1 + dr[i],    c2 = c1 + dc[i];
            if(r2 < 0 || r2 == 6 || c2 < 0 || c2 == 6)  continue;
            if(dist[r2][c2] != UNVISITED)   continue;
            if(blocks.count(make_tuple(r1, c1, r2, c2)))    continue;

            dist[r2][c2] = dist[r1][c1] + 1;
            direction[r2][c2] = dir[i];
            Q.push(ii(r2, c2));
            parent[r2][c2] = ii(r1, c1);
        }
    }
}

void backtrack(int tr, int tc){
    if(parent[tr][tc] == ii(-1, -1))    return;
    int r, c;
    r = parent[tr][tc].first,   c = parent[tr][tc].second;
    backtrack(r, c);
    cout << direction[tr][tc];
}

int main(){ _
    int sr, sc, tr, tc, r1, c1, r2, c2;
    while(cin >> sc >> sr){
        if(sc == 0) break;

        blocks.clear();
        memset(dist, UNVISITED, sizeof dist);
        parent.assign(6, vector< ii > (6, ii(-1, -1)));

        cin  >> tc >> tr;
        --sr, --sc, --tr, --tc;
        for(int i = 0; i < 3; ++i){
            cin >> c1 >> r1 >> c2 >> r2;
            if(r1 == r2){   // horizontal wall
                for(int j = c1; j < c2; ++j){
                    blocks.insert(make_tuple(r1 - 1, j, r1, j));
                    blocks.insert(make_tuple(r1, j, r1 - 1, j));
                }
            } else {
                for(int j = r1; j < r2; ++j){
                    blocks.insert(make_tuple(j, c1 - 1, j, c1));
                    blocks.insert(make_tuple(j, c1, j, c1 - 1));
                }
            }
        }

        bfs(sr, sc);
        backtrack(tr, tc);
        cout << endl;
    }
    return 0;
}
