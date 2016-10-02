#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int R, C;
stack<int> si;
vector<int> height, dist;
vector< vector<int> > AdjList;

void topoSort(int u){
    dist[u] = 1;
    for(int i = 0; i < AdjList[u].size(); ++i){
        int v = AdjList[u][i];
        if(dist[v] == UNVISITED)
            topoSort(v);
    }
    si.push(u);
}

int main(){ _
    int tc;   cin >> tc;
    while(tc--){
        string name;
        cin >> name >> R >> C;
        height.assign(R * C, 0);
        dist.assign(R * C, UNVISITED);
        AdjList.assign(R * C, vector<int> (0));

        for(int i = 0; i < R * C; ++i)  cin >> height[i];

        for(int i = 0; i < R; ++i)
            for(int j = 0; j < C; ++j){
                for(int r = max(0, i - 1); r < min(R, i + 2); ++r)
                    if(height[i*C + j] > height[r*C + j])
                        AdjList[i*C + j].push_back(r*C + j);

                for(int c = max(0, j - 1); c < min(C, j + 2); ++c)
                    if(height[i*C + j] > height[i*C + c])
                        AdjList[i*C + j].push_back(i*C + c);
            }

        for(int i = 0; i < R * C; ++i)
            if(dist[i] == UNVISITED)
                topoSort(i);

        int ans = 0;
        while(!si.empty()){
            int u = si.top();   si.pop();
            ans = max(ans, dist[u]);
            for(int i = 0; i < AdjList[u].size(); ++i){
                int v = AdjList[u][i];
                dist[v] = max(dist[v], dist[u] + 1);
            }
        }

        cout << name << ": " << ans << endl;
    }
    return 0;
}
