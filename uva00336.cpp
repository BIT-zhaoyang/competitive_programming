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

queue<int> Q;
vector<int> dist;
map<int, int> compress;
vector< vector<int> > edges;

int bfs(int source, int ttl){
    Q.push(source);  dist[source] = 0;
    int ans = 0, p, q;
    while(!Q.empty()){
        p = Q.front();    Q.pop();    ++ans;
        if(dist[p] == ttl)  continue;

        for(int i = 0; i < edges[p].size(); ++i){
            q = edges[p][i];
            if(dist[q] == UNVISITED){
                dist[q] = dist[p] + 1;
                Q.push(q);
            }
        }
    }

    return ans;
}

int main(){ _
    int nc, u, v, id1, id2, tc = 0, n;
    while(cin >> nc){
        if(nc == 0)  break;
        n = 0;
        compress.clear();   edges.clear();
        for(int i = 0; i < nc; ++i){
            cin >> u >> v;
            if(!compress.count(u)){
                compress[u] = n++;
                edges.push_back(vector<int> (0));
            }
            if(!compress.count(v)){
                compress[v] = n++;
                edges.push_back(vector<int> (0));
            }

            id1 = compress[u],  id2 = compress[v];
            edges[id1].push_back(id2);
            edges[id2].push_back(id1);
        }

        int s, ttl, ans;
        while(cin >> s >> ttl){
            if(s == 0 && ttl == 0)  break;
            cout << "Case " << ++tc << ": ";
            dist.assign(n, UNVISITED);
            ans = bfs(compress[s], ttl);
            cout << n - ans << " nodes not reachable from node " << s << " with TTL = " << ttl << "." << endl;
        }
    }
    return 0;
}
