#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

/* At my first try, I will consider this as a multiple source shortest path problem. I will do up to 500(the maximum number of intersections) dijkstra, with starting source cotaining given starting points and one of the point that doesn't have a firestation. The complexity is O(VElgV) which is about 1.25 * 10^9. Hope it will pass. */

vector<bool> firestation;
vector< vector< ii > > AdjList;
priority_queue< ii, vector< ii >, greater< ii > > pq;
vector<int> dist, given;

void dijkstra(){
    int u, v, d1, d2;
    while(!pq.empty()){
        d1 = pq.top().first,    u = pq.top().second;
        pq.pop();
        if(d1 > dist[u])    continue;
        for(int i = 0; i < AdjList[u].size(); ++i){
            v = AdjList[u][i].first,    d2 = AdjList[u][i].second;
            if(d1 + d2 < dist[v]){
                dist[v] = d1 + d2;
                pq.push(ii(dist[v], v));
            }
        }
    }
}


int main(){ _
    int tc; cin >> tc;
    while(tc--){
        int n, m;   cin >> n >> m;
        given.assign(n, 0);
        firestation.assign(m+1, false);
        AdjList.assign(m+1, vector< ii > (0));

        for(int i = 0; i < n; ++i){
            cin >> given[i];
            firestation[given[i]] = true;
        }

        string str;
        stringstream ss;
        int u, v, w;
        cin.ignore();
        while(getline(cin, str)){
            if(str == "")   break;
            ss.clear();
            ss.str("");
            ss << str;
            ss >> u >> v >> w;
            AdjList[u].push_back(ii(v, w));
            AdjList[v].push_back(ii(u, w));
        }

        // Do dijkstra
        int minMax = INT_MAX, currMax = 0, idx = given[0];
        for(int i = 1; i <= m; ++i){
            if(!firestation[i]){
                dist.assign(m+1, INT_MAX);
                pq.push(ii(0, i));
                dist[i] = 0;
                for(int j = 0; j < given.size(); ++j){
                    pq.push(ii(0, given[j]));
                    dist[given[j]] = 0;
                }

                dijkstra();

                currMax = 0;
                for(int j = 1; j <= m; ++j){
                    currMax = max(currMax, dist[j]);
                }

                if(currMax < minMax){
                    minMax = currMax;
                    idx = i;
                }
            }
        }
        cout << idx << endl;
        if(tc)  cout << endl;
    }
    return 0;
}
