#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define POS_INF 1 << 28
#define NEG_INF -1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int n, m, s, t;
vector< pair<double, double> > gopher, hole;
vector< vector<int> > AdjList;
vector<bool> visited;
vector<int> match;

double dist(pair<double, double> &A, pair<double, double> &B){
    double diffX = A.first - B.first,  diffY = A.second - B.second;
    return pow(diffX, 2) + pow(diffY, 2);
}

int aug_path(int u){
    if(visited[u])  return 0;
    visited[u] = true;
    for(int i = 0; i < AdjList[u].size(); ++i){
        int v = AdjList[u][i];
        if(match[v] == UNVISITED || aug_path(match[v])){
            match[v] = u;
            return 1;
        }
    }
    return 0;
}

int main(){ _
    while(cin >> n >> m >> s >> t){
        double maxDist = pow(s * t, 2);
        gopher.assign(n, pair<double, double> (0,0));
        hole.assign(m, pair<double, double> (0,0));
        for(int i = 0; i < n; ++i)  cin >> gopher[i].first >> gopher[i].second;
        for(int i = 0; i < m; ++i)  cin >> hole[i].first >> hole[i].second;

        AdjList.assign(n, vector<int> (0));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(dist(gopher[i], hole[j]) <= maxDist)
                    AdjList[i].push_back(j);

        match.assign(m, UNVISITED);
        int MCBM = 0;
        for(int i = 0; i < n; ++i){
            visited.assign(n, false);
            MCBM += aug_path(i);
        }
        cout << n - MCBM << endl;
    }
    return 0;
}
