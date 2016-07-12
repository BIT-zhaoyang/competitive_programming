#include <algorithm>
#include <bitset>
#include <cstring>
#include <climits>
#include <cmath>
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

typedef pair<int, int> ii;

priority_queue< ii, vector< ii >, greater< ii > > pq;
vector<bool> taken;
vector< vector< ii > > AdjList;

void process(int u){
    taken[u] = true;

    ii next;
    int v, w;
    for(int i = 0; i < AdjList[u].size(); ++i){
        next = AdjList[u][i];
        v = next.first, w = next.second;
        if(!taken[v])   pq.push(ii(w, v));
    }
}

int main(){ _
    int TC, n, m, r, u, v, w, nAirport, cost; cin >> TC;
    ii front;
    for(int tc = 1; tc <= TC; ++tc){
        cout << "Case #" << tc << ": ";

        cin >> n >> m >> r;
        taken.assign(n, false);
        AdjList.assign(n, vector< ii > (0));
        nAirport = cost = 0;

        for(int i = 0; i < m; ++i){
            cin >> u >> v >> w;
            --u, --v;
            AdjList[u].push_back(ii(v, w));
            AdjList[v].push_back(ii(u, w));
        }

        for(int i = 0; i < n; ++i){
            if(!taken[i]){
                ++nAirport;
                cost += r;
                pq.push(ii(0, i));
                while(!pq.empty()){
                    front = pq.top();   pq.pop();
                    w = front.first, u = front.second;
                    if(!taken[u]){
                        if(w >= r){
                            cost += r;
                            ++nAirport;
                        } else {
                            cost += w;
                        }

                        process(u);
                    }
                }
            }
        }

        cout << cost << " " << nAirport << endl;
    }
    return 0;
}
