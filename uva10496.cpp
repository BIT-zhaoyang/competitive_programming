#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);

using namespace std;

int table[20][1<<20];

int tsp(int pos, int mask, vector< vector<int> >& dist){
    int n = dist.size();
    if(mask == (1<<n)-1)    return dist[pos][0];
    if(table[pos][mask])    return table[pos][mask];

    int cost = INT_MAX;
    for(int i = 0; i < n; ++i){
        if( !(mask & (1<<i)) )
            cost = min(cost, dist[pos][i] + tsp(i, mask | (1 << i), dist));
    }

    table[pos][mask] = cost;
    return cost;
}


int main(){ _
    // 16:10
    int T; cin >> T;
    while(T--){
        int lx, ly; cin >> lx >> ly;
        int sx, sy; cin >> sx >> sy;
        int n;  cin >> n;
        memset(table, 0, sizeof table);

        vector<int> x(n+1, sx), y(n+1, sy);
        for(int i = 1; i <= n; ++i){
            cin >> x[i] >> y[i];
        }

        vector< vector<int> > dist(n+1, vector<int> (n+1, 0));
        for(int i = 0; i <= n; ++i){
            for(int j = 0; j <= n; ++j){
                dist[i][j] = abs(x[i]-x[j]) + abs(y[i]-y[j]);
            }
        }

        int cost = tsp(0, 1, dist);
        cout << "The shortest path has length " << cost << endl;
    }
    return 0;
}
