#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
    int n, m;   cin >> n >> m;
    vector< vector< ii > > AdjMat(26, vector< ii > (26, ii(BIGINT, 0)));
    vector< vector<int> > parent(26, vector<int> (26, -1));

    char cfrom, cto;
    int ifrom, ito, cost;
    for(int i = 0; i < m; ++i){
        cin >> cfrom >> cto >> cost;
        ifrom = cfrom - 'A';
        ito = cto - 'A';
        AdjMat[ifrom][ito] = AdjMat[ito][ifrom] = ii(cost, 0);
        parent[ifrom][ito] = ifrom;
        parent[ito][ifrom] = ito;
    }

    // floyd-warshall
    for(int k = 0; k < 26; ++k)
        for(int i = 0; i < 26; ++i)
            for(int j = 0; j < 26; ++j)
                if(AdjMat[i][k].first + AdjMat[k][j].first < AdjMat[i][j].first){
                    AdjMat[i][j].first = AdjMat[i][k].first + AdjMat[k][j].first;
                    AdjMat[i][j].second = AdjMat[i][k].second + AdjMat[k][j].second;
                    parent[i][j] = parent[k][j];
                } else if(AdjMat[i][k].first + AdjMat[k][j].first == AdjMat[i][j].first){
                    if(AdjMat[i][k].second + AdjMat[k][j].second < AdjMat[i][j].second){
                        AdjMat[i][j].first = AdjMat[i][k].first + AdjMat[k][j].first;
                        AdjMat[i][j].second = AdjMat[i][k].second + AdjMat[k][j].second;
                        parent[i][j] = parent[k][j];
                    }
                }

    // answer queries
    int nq;         cin >> nq;
    for(int i = 0; i < nq; ++i){
        cin >> cfrom >> cto;
        ito = cfrom - 'A';      // The graph is undirected. So we can find the track backwards
        ifrom = cto - 'A';      // by switch start position and end position.
        while(ito != ifrom){
            cout << char(ito + 'A') << " ";
            ito = parent[ifrom][ito];
        }
        cout << char(ito + 'A') << endl;
    }
    return 0;
}
