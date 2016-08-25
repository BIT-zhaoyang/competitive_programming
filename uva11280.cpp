#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

map<string, int> s2i;
vector< vector< ii > > AdjList;
vector< vector<int> > price;

int main(){ _
    int TC; cin >> TC;
    for(int tc = 1; tc <= TC; ++tc){
        cout << "Scenario #" << tc << endl;

        int n, m;
        cin >> n;
        s2i.clear();
        AdjList.assign(n, vector< ii > (0));

        string city;
        for(int i = 0; i < n; ++i){
            cin >> city;
            s2i[city] = i;
        }

        cin >> m;
        string city1, city2;
        int u, v, w;
        for(int i = 0; i < m; ++i){
            cin >> city1 >> city2 >> w;
            u = s2i[city1];
            v = s2i[city2];
            AdjList[u].push_back(ii(v, w));
        }

        int nq, q; cin >> nq;
        for(int i = 0; i < nq; ++i){
            cin >> q;
            ++q;
            price.assign(n, vector<int> (q+1, INT_MAX));
            price[0][0] = 0;
            for(int u = 0; u < n; ++u){
                for(int nStop = 0; nStop < q; ++nStop){
                    if(price[u][nStop] == INT_MAX)  continue;
                    for(int j = 0; j < AdjList[u].size(); ++j){
                        v = AdjList[u][j].first;
                        price[v][nStop+1] = min(price[v][nStop+1],
                                        price[u][nStop] + AdjList[u][j].second);
                    }
                }
            }

            int minPrice = INT_MAX;
            for(int nStop = q; nStop > 0; --nStop){
                minPrice = min(minPrice, price[n-1][nStop]);
            }

            if(minPrice == INT_MAX) cout << "No satisfactory flights" << endl;
            else    cout << "Total cost of flight(s) is $" << minPrice << endl;
        }

        if(TC - tc) cout << endl;
    }
    return 0;
}
