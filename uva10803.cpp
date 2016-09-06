#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(4);
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
    int TC; cin >> TC;
    for(int tc = 1; tc <= TC; ++tc){
        int n;  cin >> n;
        vector< ii > loc(n, ii(0, 0));
        for(int i = 0; i < n; ++i)  cin >> loc[i].first >> loc[i].second;

        vector< vector<double> > AdjMat(n, vector<double> (n, 2e9));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j){
                double d = compute(loc[i], loc[j]);
                if(d - 1e-9 < 10.0)     AdjMat[i][j] = d;
            }

        for(int k = 0; k < n; ++k)
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);

        double longest = 0.0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                longest = max(longest, AdjMat[i][j]);

        cout << "Case #" << tc << ":" << endl;
        if(abs(longest - 2e9) < 1e-9)   cout << "Send Kurdy" << endl;
        else    cout << fixed << longest << endl;
        cout << endl;
    }
    return 0;
}
