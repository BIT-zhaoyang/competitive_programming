#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(2);
#define UNVISITED -1
#define INF 1e9
#define eps 1e-9
using namespace std;

/* Good problem. TSP solution with tweak. Cause my attention on pricison issues. Need to study this a bit. */

typedef long long int64;
typedef pair<int, int> ii;

vector< vector<double> > fullDist, partialDist;
vector<double> saving;
vector< vector<double> > memo;

double tsp(int pos, int mask, int target){
    if(mask == target)  return partialDist[pos][0];
    if(memo[pos][mask] != INF)  return memo[pos][mask];

    memo[pos][mask] = partialDist[pos][0];  // We can go home early which means we don't need to travel all the stores. Thus, memo[pos][mask] = partialDist[0][pos] represents the choice we go home from current pos. (In normal tsp, this is set to INF, since in normal TSP we are required to traverse all positions. Leaving early leads to fail which incurs INF cost.)
    for(int i = 1; i < partialDist.size(); ++i){
        if(mask & (1 << i)) continue;
        memo[pos][mask] = min(memo[pos][mask],
                            partialDist[pos][i] + tsp(i, mask | (1 << i), target) - saving[i]);
    }
    return memo[pos][mask];
}

int main(){ _
    int tc; cin >> tc;
    while(tc--){
        int n, m;   cin >> n >> m;
        ++n;
        fullDist.assign(n, vector<double> (n, INF));
        for(int i = 0; i < n; ++i)  fullDist[i][i] = 0.0;

        int u, v;   double w;
        for(int i = 0; i < m; ++i){
            cin >> u >> v >> w;
            fullDist[u][v] = fullDist[v][u] = min(w, fullDist[u][v]);
        }

        // Floyd - Warshell
        for(int k = 0; k < n; ++k)
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    fullDist[i][j] = min(fullDist[i][j], fullDist[i][k] + fullDist[k][j]);

        // read selected stores
        int p;
        cin >> p;
        ++p;
        saving.assign(p, 0.0);
        partialDist.assign(p, vector<double> (p, 0.0));
        vector<int> stores(p, 0);
        for(int i = 1; i < p; ++i)     cin >> stores[i] >> saving[i];
        for(int i = 0; i < p; ++i)
            for(int j = 0; j < p; ++j)
                partialDist[i][j] = fullDist[stores[i]][stores[j]];

        // tsp
        memo.assign(p, vector<double> (1 << p, INF));
        int target = (1 << p) - 1;
        tsp(0, 1, target);

        // notice the precision problem
        if(memo[0][1] <= -eps)    cout << "Daniel can save $" << fixed << -memo[0][1] << endl;
        else    cout << "Don't leave the house" << endl;
    }
    return 0;
}
