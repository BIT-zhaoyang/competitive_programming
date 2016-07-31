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

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

/* inspired by this problem: https://ericsson.kattis.com/problems/coast, Coast Length. Accessed on 30.07.2016.

Pay attention that the maze is not necessarily a square. So the first step is to get clear which cell is inside the maze.

Then we can BFS inside the maze to find how long it takes us to get outside the maze. One corner case is that we are not in the maze at all.
*/

#define UNVISITED -1
#define maxN 205

typedef long long int64;
typedef pair<int, int> ii;


vector< vector<bool> > inside, visited;
set< tuple<int, int, int, int> > wall;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};

void bfs1(int x, int y){
    visited.assign(maxN, vector<bool> (maxN, false));
    visited[x][y] = true;
    inside[x][y] = false; // the starting point is not inside the maze

    queue< ii > Q;
    Q.push(ii(x, y));
    int nx, ny;
    while(!Q.empty()){
        x = Q.front().first,    y = Q.front().second;
        Q.pop();

        for(int i = 0; i < 4; ++i){
            nx = x + dx[i],     ny = y + dy[i];
            if(nx < 0 || nx >= maxN || ny < 0 || ny >= maxN)    continue;
            if(wall.count(make_tuple(x, y, nx, ny)))    continue;
            if(visited[nx][ny]) continue;

            inside[nx][ny] = false;
            visited[nx][ny] = true;
            Q.push(ii(nx, ny));
        }
    }
}

int bfs2(int x1, int y1, int d1){
    visited.assign(maxN, vector<bool> (maxN, false));
    visited[x1][y1] = true;

    queue< tuple<int, int, int> > Q2;
    Q2.push(make_tuple(x1, y1, d1));
    int x2, y2, d2;
    while(!Q2.empty()){
        tie(x1, y1, d1) = Q2.front();
        Q2.pop();

        for(int i = 0; i < 4; ++i){
            x2 = x1 + dx[i],    y2 = y1 + dy[i],    d2 = d1 + 1;
            if(x2 < 0 || x2 >= maxN || y2 < 0 || y2 >= maxN)    continue;
            if(wall.count(make_tuple(x1, y1, x2, y2)))    continue;
            if(inside[x2][y2] == false) return d2;
            if(visited[x2][y2]) continue;

            visited[x2][y2] = true;
            Q2.push(make_tuple(x2, y2, d2));
        }
    }
    return -1;
}

int main(){ _
    int nW, nD;
    while(cin >> nW >> nD){ // #Wall, #Door
        if(nW == -1)    break;
        inside.assign(maxN, vector<bool> (maxN, true)); // we assume every cell is in the maze
        wall.clear();

        // Build the maze. Notice that the maze is not necessarily a rectangle.
        int x, y, d, t;
        for(int i = 0; i < nW; ++i){
            cin >> x >> y >> d >> t;
            if(d){
                for(int j = 0; j < t; ++j){
                    wall.insert(make_tuple(x-1, y, x, y));
                    wall.insert(make_tuple(x, y, x-1, y));
                    ++y;
                }
            } else {
                for(int j = 0; j < t; ++j){
                    wall.insert(make_tuple(x, y-1, x, y));
                    wall.insert(make_tuple(x, y, x, y-1));
                    ++x;
                }
            }
        }


        // label cells not inside the maze
        // label this before we open the doors!
        bfs1(0, 0);

        // open the doors by removing walls
        for(int i = 0; i < nD; ++i){
            cin >> x >> y >> d;
            if(d){
                if(wall.count(make_tuple(x-1, y, x, y))){
                    wall.erase(make_tuple(x-1, y, x, y));
                    wall.erase(make_tuple(x, y, x-1, y));
                }
            } else {
                if(wall.count(make_tuple(x, y-1, x, y))){
                    wall.erase(make_tuple(x, y-1, x, y));
                    wall.erase(make_tuple(x, y, x, y-1));
                }
            }
        }

        // bfs from where Nemo locates, compute doors needed to go through
        double doubX, doubY;
        cin >> doubX >> doubY;
        int intX = (int)doubX, intY = (int)doubY;
        if(intX >= 200 || intY >= 200 || !inside[intX][intY])  cout << 0 << endl;
        else {
            int ans = bfs2(intX, intY, 0);
            cout << ans << endl;
        }
    }
    return 0;
}
