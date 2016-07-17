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

map<string, int> s2i;
vector< vector<int> > AdjList;
vector<int> dist;
queue<int> Q;

void bfs(int source){
    dist[source] = 0;
    Q.push(source);
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
    cout << "SHIPPING ROUTES OUTPUT" << endl << endl;
    int TC; cin >> TC;
    string warehouse, source, dest;
    for(int tc = 1; tc <= TC; ++tc){
        cout << "DATA SET  " <<  tc << endl << endl;
        int n, m, nq;   cin >> n >> m >> nq;

        s2i.clear();
        for(int i = 0; i < n; ++i){
            cin >> warehouse;
            s2i[warehouse] = i;
        }

        AdjList.assign(n, vector<int> (0));
        int id1, id2;
        for(int i = 0; i < m; ++i){
            cin >> warehouse;   id1 = s2i[warehouse];
            cin >> warehouse;   id2 = s2i[warehouse];
            AdjList[id1].push_back(id2);
            AdjList[id2].push_back(id1);
        }

        int shipsize;
        for(int i = 0; i < nq; ++i){
            cin >> shipsize >> source >> dest;
            dist.assign(n, UNVISITED);
            bfs(s2i[source]);
            if(dist[s2i[dest]] == UNVISITED)    cout << "NO SHIPMENT POSSIBLE" << endl;
            else    cout << "$" << shipsize * dist[s2i[dest]] * 100 << endl;
        }
        cout << endl;
    }
    cout << "END OF OUTPUT" << endl;
    return 0;
}
