#include <bits/stdc++.h>
#define UNVISITED -1
#define BIGINT 1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
    int n, m, u, v, tc = 0;
    vector< vector<int> > AdjMat;
    while(cin >> m){
        n = 0;
        AdjMat.assign(30, vector<int> (30, 0));
        for(int i = 0; i < m; ++i){
            cin >> u >> v;
            AdjMat[u][v] = 1;
            n = max(n, max(u, v));
        }
        n++;

        for(int k = 0; k < n; ++k)
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    AdjMat[i][j] += AdjMat[i][k] * AdjMat[k][j];

        for(int k = 0; k < n; ++k)
            if(AdjMat[k][k] > 0){
                for(int i = 0; i < n; ++i)
                    for(int j = 0; j < n; ++j)
                        if(AdjMat[i][k] && AdjMat[k][j]){
                            AdjMat[i][k] = AdjMat[k][j] = AdjMat[i][j] = -1;
                        } else if(AdjMat[i][k]){
                            AdjMat[i][k] = -1;
                        } else if(AdjMat[k][j]){
                            AdjMat[k][j] = -1;
                        }
            }

        cout << "matrix for city " << tc++ << endl;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(j)   cout << " ";
                cout << AdjMat[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
