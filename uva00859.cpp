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

/* good problem. clever useage of bfs. */

typedef long long int64;
typedef pair<int, int> ii;

vector< vector<bool> > piece;
vector< vector<int> > dist;
vector< tuple<int, int, int> > ans;
queue< ii > Q;
int R, C;

const int jdr[] = {0, 1, 1, 1, 0};   // jump direction
const int jdc[] = {1, 1, 0, -1, -1};
const int gdr[] = {0, 1, 0}; // go direction
const int gdc[] = {1, 0, -1};

void bfs(int sr, int sc){
    Q.push(ii(sr, sc)); dist[sr][sc] = 0;
    ii p, q;
    int nr, nc, jr, jc;

    // go directly
    p = Q.front();
    for(int i = 0; i < 3; ++i){
        nr = p.first+ gdr[i],    nc = p.second + gdc[i];
        if(nr >= 1 && nr <= R && nc >= 1 && nc <= C && !piece[nr][nc]){
            ans.push_back(make_tuple(nr, nc, 1));
        }
    }

    while(!Q.empty()){
        p = Q.front();  Q.pop();
        // jump
        for(int i = 0; i < 5; ++i){
            nr = p.first+ jdr[i],    nc = p.second + jdc[i];
            if(nr >= 1 && nr <= R && nc >= 1 && nc <= C && piece[nr][nc]){
                jr = nr + jdr[i],    jc = nc + jdc[i];
                if(jr >= 1 && jr <= R && jc >= 1 && jc <= C && !piece[jr][jc] && dist[jr][jc] == UNVISITED){
                    Q.push(ii(jr, jc));
                    dist[jr][jc] = dist[p.first][p.second] + 1;
                    ans.push_back(make_tuple(jr, jc, dist[jr][jc]));
                }
            }
        }

    }

}

bool mycomp(tuple<int, int, int> &A, tuple<int, int, int> &B){
    int r1, c1, d1, r2, c2, d2;
    tie(r1, c1, d1) = A,    tie(r2, c2, d2) = B;

    if(r1 != r2)    return r1 > r2;
    else    return c1 < c2;
}

int main(){ _
    int tc = 0;
    while(cin >> R >> C){
        if(tc++)    cout << endl;

        piece.assign(R+1, vector<bool> (C+1, false));
        dist.assign(R+1, vector<int> (C+1, UNVISITED));
        ans.clear();

        int r, c;
        for(int i = 0; i < C << 2; ++i){
            cin >> r >> c;
            piece[r][c] = true;
        }

        int sr, sc; cin >> sr >> sc;
        bfs(sr, sc);
        sort(ans.begin(), ans.end(), mycomp);
        for(int i = 0; i < ans.size(); ++i){
            cout << get<0>(ans[i]) << " " << get<1>(ans[i]) << " " << get<2>(ans[i]) << endl;
        }
    }
    return 0;
}
