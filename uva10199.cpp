#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
using namespace std;

typedef long long int64;

int N, R, a, b, root, numChild, dfsCounter, ans;
vector<int> dfs_num, dfs_low, parent;
vector<bool> articulation;
vector< vector<int> > edges;
vector<string> cities;
map<string, int> s2i;

string city, ca, cb;

void findArticulationPoint(int p){
    dfs_num[p] = dfs_low[p] = dfsCounter++;

    int q;
    for(int i = 0; i < edges[p].size(); ++i){
        q = edges[p][i];
        if(dfs_num[q] == UNVISITED){
            parent[q] = p;
            if(p == root)   ++numChild;

            findArticulationPoint(q);

            if(dfs_low[q] >= dfs_num[p])    articulation[p] = true;

            dfs_low[p] = min(dfs_low[p], dfs_low[q]);
        } else if(q != parent[p]){
            dfs_low[p] = min(dfs_low[p], dfs_num[q]);
        }
    }
}

int main(){ _
    int tc = 0;
    while(cin >> N){
        if(N == 0)  break;
        if(tc)  cout << endl;
        cout << "City map #" << ++tc << ": ";

        dfs_num.assign(N, UNVISITED);
        dfs_low.assign(N, UNVISITED);
        articulation.assign(N, false);
        parent.assign(N, UNVISITED);
        edges.assign(N, vector<int> (0));
        cities.clear();
        s2i.clear();

        for(int i = 0; i < N; ++i){
            cin >> city;
            cities.push_back(city);
            // s2i[city] = i;
        }

        sort(cities.begin(), cities.end());
        for(int i = 0; i < N; ++i){
            s2i[cities[i]] = i;
        }


        cin >> R;
        for(int i = 0; i < R; ++i){
            cin >> ca >> cb;
            a = s2i[ca],    b = s2i[cb];
            edges[a].push_back(b);
            edges[b].push_back(a);
        }

        ans = 0, dfsCounter = 0;
        for(int i = 0; i < N; ++i){
            if(dfs_num[i] == UNVISITED){
                root = i, numChild = 0;
                findArticulationPoint(root);
                articulation[root] = (numChild > 1);
            }
            if(articulation[i])  ++ans;
        }

        cout << ans << " camera(s) found" << endl;
        for(int i = 0; i < N; ++i){
            if(articulation[i])  cout << cities[i] << endl;
        }

    }
    return 0;
}
