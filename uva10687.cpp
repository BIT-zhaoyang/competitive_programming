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

void dfs(int idx, vector< pair<int, int> >& vii, vector<bool>& visited){
    visited[idx] = true;
    int minDist, minIdx, dist, westIdx = -1;
    int x, y, nx, ny, wx, wy, sx, sy;   // nx: neib x, wx: westernmost x, sx: southernmost x

    x = vii[idx].first;   y = vii[idx].second;

    // find westernmost neib
    minDist = INT_MAX, minIdx = -1;
    for(int j = 0; j < vii.size(); ++j){
        if(j == idx)    continue;
        nx = vii[j].first;  ny = vii[j].second;
        dist = (x - nx)*(x - nx) + (y-ny)*(y - ny);
        if(dist < minDist){
            wx = nx, wy = ny;
            minDist = dist;
            minIdx = j;
        } else if(dist == minDist){
            if(nx < wx){
                wx = nx, wy = ny;
                minDist = dist;
                minIdx = j;
            }
        }
    }
    if(minIdx != -1 && !visited[minIdx]){
        westIdx = minIdx;
        dfs(minIdx, vii, visited);
    }

    // find southernmost neib
    minDist = INT_MAX, minIdx = -1;
    for(int j = 0; j < vii.size(); ++j){
        if(j == westIdx || j == idx)    continue;
        nx = vii[j].first;  ny = vii[j].second;
        dist = (x - nx)*(x - nx) + (y-ny)*(y - ny);
        if(dist < minDist){
            sx = nx, sy = ny;
            minDist = dist;
            minIdx = j;
        } else if(dist == minDist){
            if(ny < sy){
                sx = nx, sy = ny;
                minDist = dist;
                minIdx = j;
            }
        }
    }
    if(minIdx != -1 && !visited[minIdx]){
        dfs(minIdx, vii, visited);
    }

}

int main(){ _
    int n, x, y;
    while(cin >> n){
        if(n == 0)  break;
        vector< pair<int, int> > vii(n);
        vector<bool> visited(n, false);
        for(int i = 0; i < n; ++i){
            cin >> x >> y;
            vii[i] = make_pair(x, y);
        }

        dfs(0, vii, visited);
        bool fail = false;
        for(int i = 0; i < visited.size(); ++i){
            if(!visited[i]){
                cout << "There are stations that are unreachable." << endl;
                fail = true;
                break;
            }
        }

        if(!fail)   cout << "All stations are reachable." << endl;

    }
    return 0;
}
