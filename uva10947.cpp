#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

double compute(ii &a, ii &b){
    int dx = a.first - b.first, dy = a.second - b.second;
    return sqrt(dx * dx + dy * dy);
}

int main(){ _
    int K, M;
    while(cin >> K >> M){
        vector< ii > loc;
        vector<int> radius;

        int x, y, r;
        // read start
        cin >> x >> y >> r;
        loc.push_back(ii(x, y));
        radius.push_back(r);

        // read dest
        cin >> x >> y >> r;
        loc.push_back(ii(x, y));
        radius.push_back(r);

        // read intermediate
        int N;  cin >> N;
        for(int i = 0; i < N; ++i){
            cin >> x >> y >> r;
            loc.push_back(ii(x, y));
            radius.push_back(r);
        }

        // connect vertices
        N = loc.size();
        vector< vector<int> > AdjMat(N, vector<int> (N, 0));
        double speed = K * M;
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j){
                double dist = compute(loc[i], loc[j]);
                if(dist - 1e-9 <= speed + radius[i] + radius[j])
                    AdjMat[i][j] = 1;
            }

        // floyd-warshall
        for(int k = 0; k < N; ++k)
            for(int i = 0; i < N; ++i)
                for(int j = 0; j < N; ++j)
                    AdjMat[i][j] |= (AdjMat[i][k] & AdjMat[k][j]);

        if(AdjMat[0][1])    cout << "Larry and Ryan will escape!" << endl;
        else    cout << "Larry and Ryan will be eaten to death." << endl;
    }
    return 0;
}
