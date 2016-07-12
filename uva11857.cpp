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
vector< vector< ii > > AdjList;
vector<bool> taken;

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
    int n, m, u, v, w, ans = 0;
    while(cin >> n >> m){
        if(n == 0)  break;

        ans = 0;
        taken.assign(n, false);
        AdjList.assign(n, vector< ii > (0));
        for(int i = 0; i < m; ++i){
            cin >>  u >> v >> w;
            AdjList[u].push_back(ii(v, w));
            AdjList[v].push_back(ii(u, w));
        }

        pq.push(ii(0, 0));
        while(!pq.empty()){
            ii front = pq.top();  pq.pop();
            u = front.second, w = front.first;
            if(!taken[u]){
                ans = max(ans, w);
                process(u);
            }
        }

        bool fail = false;
        for(int i = 0; i < n; ++i){
            if(!taken[i]){
                fail = true;
                break;
            }
        }

        if(fail)    cout << "IMPOSSIBLE" << endl;
        else    cout << ans << endl;
    }
    return 0;
}
