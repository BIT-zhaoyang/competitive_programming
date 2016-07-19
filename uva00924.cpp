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
vector< vector<int> > AdjList;
vector<int> bfs_num;
queue<int> Q;

void bfs(int source){
    bfs_num[source] = 0;
    Q.push(source);
    int p, q;
    while(!Q.empty()){
        p = Q.front();  Q.pop();
        for(int i = 0; i < AdjList[p].size(); ++i){
            q = AdjList[p][i];
            if(bfs_num[q] == UNVISITED){
                bfs_num[q] = bfs_num[p] + 1;
                Q.push(q);
            }
        }
    }
}

int main(){ _
    int n, m, f;  cin >> n;
    AdjList.assign(n, vector<int> (0));
    for(int i = 0; i < n; ++i){
        cin >> m;
        for(int j = 0; j < m; ++j){
            cin >> f;
            AdjList[i].push_back(f);
        }
    }

    int tc, source, maxIdx, maxSize; cin >> tc;
    vector<int> stats(n, 0);
    while(tc--){
        bfs_num.assign(n, UNVISITED);
        stats.assign(n, 0);
        maxSize = 0;
        cin >> source;
        bfs(source);

        for(int i = 0; i < n; ++i){
            if(bfs_num[i] > 0){
                stats[bfs_num[i]] += 1;
                maxSize = max(maxSize, stats[bfs_num[i]]);
            }
        }

        for(int i = 1; i < n; ++i){
            if(stats[i] == maxSize){
                maxIdx = i;
                break;
            }
        }

        if(maxSize == 0)    cout << 0 << endl;
        else    cout << maxSize << " " << maxIdx << endl;
    }
    return 0;
}
