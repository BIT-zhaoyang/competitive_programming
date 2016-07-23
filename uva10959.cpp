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
vector<int> dist;
queue<int> Q;

void bfs(int source){
    Q.push(source); dist[source] = 0;
    int p, q;
    while(!Q.empty()){
        p = Q.front();  Q.pop();
        for(int i = 0; i < AdjList[p].size(); ++i){
            q = AdjList[p][i];
            if(dist[q] == UNVISITED){
                dist[q] = dist[p] + 1;
                Q.push(q);
            }
        }
    }
}

int main(){ _
    int tc; cin >> tc;
    while(tc--){
        int P, D;   cin >> P >> D;
        AdjList.assign(P, vector<int> (0));
        dist.assign(P, UNVISITED);

        int u, v;
        for(int i = 0; i < D; ++i){
            cin >> u >> v;
            AdjList[u].push_back(v);
            AdjList[v].push_back(u);
        }

        bfs(0);
        for(int i = 1; i < P; ++i)  cout << dist[i] << endl;
        if(tc)  cout << endl;
    }
    return 0;
}
