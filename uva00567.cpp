#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 25
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
    const int nc = 20;

    int n, from, to, tc= 0;
    while(cin >> n){
        vector< vector<int> > AdjMat(nc + 1, vector<int> (nc + 1, BIGINT));
        for(from = 1; from < 20; ++from){
            if(from != 1)   cin >> n;
            for(int j = 0; j < n; ++j){
                cin >> to;
                AdjMat[from][to] = AdjMat[to][from] = 1;
            }
        }

        // floyd-warshall
        for(int k = 1; k <= nc; ++k)
            for(int i = 1; i <= nc; ++i)
                for(int j = 1; j <= nc; ++j)
                    AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);

        cout << "Test Set #" << ++tc << endl;
        int nq;     cin >> nq;
        for(int i = 0; i < nq; ++i){
            cin >> from >> to;
            cout << setw(2) << from << " to " << setw(2) << to << ": " << AdjMat[from][to] << endl;
        }
        cout << endl;
    }
    return 0;
}
