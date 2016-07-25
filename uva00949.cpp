#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
using namespace std;

/* The problem statement is wrong!!!!!!!!!! The two numbers in the first line represent #horizontal roads and #vertical roads! What a dum mistake!

**The lesson I learned is that, BFS can be used to compute SSSP on both directed & undirected graph, as long as it's unweighted! Very important lesson learned...**
*/

typedef long long int64;
typedef pair<int, int> ii;

int C, R;
queue< tuple<int, int, int> > Q;
map< int, ii > monitor;
vector< vector<int> > dist;
set< tuple< int, int, int, int > > blocks;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

void bfs(int x1, int y1, int t1){
    Q.push(make_tuple(x1, y1, t1)); dist[x1][y1] = t1;

    int x2, y2, t2;
    while(!Q.empty()){
        tie(x1, y1, t1) = Q.front();    Q.pop();
        for(int i = 0; i < 4; ++i){
            x2 = x1 + dx[i],    y2 = y1 + dy[i],    t2 = t1 + 1;

            // illegal operations
            if(x2 < 0 || x2 == R || y2 < 0 || y2 == C)  continue;   // overbound
            if( blocks.count(make_tuple(x1, y1, x2, y2)) )   continue;   // no connect
            if(dist[x2][y2] != UNVISITED)   continue;   // already visited

            // legal operations
            if(monitor.count(t2) && monitor[t2] == ii(x2, y2)){ // if next cross is being monitoring
                Q.push(make_tuple(x1, y1, t1 + 1));     // wait at current cross
            } else {
                dist[x2][y2] = t2;  // go to next cross
                Q.push(make_tuple(x2, y2, t2));
            }
        }
    }
}

int main(){ _
    int x1, y1, x2, y2, tc = 1;
    while(cin >> R >> C){
        blocks.clear();
        monitor.clear();
        dist.assign(R, vector<int> (C, UNVISITED));
        int nb;  cin >> nb;
        for(int i = 0; i < nb; ++i){
            cin >> x1 >> y1 >> x2 >> y2;
            blocks.insert(make_tuple(x1, y1, x2, y2));
        }

        int nt, t; cin >> nt;
        for(int i = 0; i < nt; ++i){
            cin >> t >> x1 >> y1;
            monitor[t] = ii(x1, y1);
        }

        bfs(0, 0, 0);
        cout << dist[R-1][C-1] << endl;
    }
    return 0;
}
