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

/* Nice problem... Clever useage of BFS to compute shortest path. As described in CP3 exercise 4.4.2.1, this is a MSSP problem which is a variant of SSSP. The idea is pretty simple after I discover it's MSSP. We just record the distance of all starting vertex as 0. Since the distance of these vertex are set to 0, they won't visit each other again.

We may want to apply the same idea to the mutiple destination vertices. But it turns out that this isn't easily implemented. Thus we have to come up with another way to unite the destination vertices. Here I used a set to record all these destination vertices. Once we reach anyone, we can return from the function.
*/

set< ii > B;
int dist[2001][2001];

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int bfs(queue< ii > &Q){
    int r1, c1, r2, c2;
    while(!Q.empty()){
        r1 = Q.front().first, c1 = Q.front().second;    Q.pop();
        for(int i = 0; i < 4; ++i){
            r2 = r1 + dr[i],    c2 = c1 + dc[i];
            if(r2 < 0 || r2 > 2000 || c1 < 0 || c1 > 2000)  continue;
            if(dist[r2][c2] != UNVISITED)   continue;

            dist[r2][c2] = dist[r1][c1] + 1;
            Q.push(ii(r2, c2));
            if(B.count(ii(r2, c2))) return dist[r2][c2];
        }
    }
}

int main(){ _
    int n, m, r, c;
    while(cin >> n){
        if(n == 0)  break;

        memset(dist, UNVISITED, sizeof dist);

        queue< ii > Q;
        for(int i = 0; i < n; ++i){
            cin >> r >> c;  dist[r][c] = 0;
            Q.push(ii(r, c));
        }

        cin >> m;
        B.clear();
        for(int i = 0; i < m; ++i){
            cin >> r >> c;
            B.insert(ii(r, c));
        }

        int ans = bfs(Q);
        cout << ans << endl;
    }
    return 0;
}
