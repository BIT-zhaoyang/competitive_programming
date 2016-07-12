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

int nCityReach = 0;
map<string, int> s2i;
vector< vector< ii > > AdjList;
vector<bool> taken;
priority_queue< ii, vector< ii >, greater< ii > > pq;

void process(int u){
    taken[u] = true;
    ++nCityReach;

    ii next;
    int v, w;
    for(int i = 0; i < AdjList[u].size(); ++i){
        next = AdjList[u][i];
        v = next.first, w = next.second;
        if(!taken[v])   pq.push(ii(w, v));
    }
}

int main(){ _
    int n, m, u, v, w, ans = 0, start;
    string str1, str2;
    while(cin >> n >> m){
        if(n == 0)  break;

        ans = nCityReach = 0;
        s2i.clear();
        AdjList.assign(n, vector< ii > (0));
        taken.assign(n, false);

        for(int i = 0; i < n; ++i){
            cin >> str1;
            s2i[str1] = i;
        }

        for(int i = 0; i < m; ++i){
            cin >> str1 >> str2 >> w;
            u = s2i[str1], v = s2i[str2];
            AdjList[u].push_back(ii(v, w));
            AdjList[v].push_back(ii(u, w));
        }

        cin >> str1;
        start = s2i[str1];

        pq.push(ii(0, start));
        while(!pq.empty()){
            ii front = pq.top();    pq.pop();
            w = front.first, u = front.second;
            if(!taken[u]){
                ans += w;
                process(u);
            }
        }

        if(nCityReach != n) cout << "Impossible" << endl;
        else    cout << ans << endl;
    }
    return 0;
}
