#include <bits/stdc++.h>
#define UNVISITED -1
#define BIGINT 1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(3);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
    int from, to, tc = 0;
    vector< vector<int> > AdjMat(101, vector<int> (101, BIGINT));
    while(cin >> from >> to){
        if(from == 0)   break;
        set<int> nodes;
        nodes.insert(from);
        nodes.insert(to);
        AdjMat.assign(101, vector<int> (101, BIGINT));
        AdjMat[from][to] = 1;
        while(cin >> from >> to){
            if(from == 0)   break;
            nodes.insert(from);
            nodes.insert(to);
            AdjMat[from][to] = 1;
        }

        // floyd
        for(int k = 1; k <= 100; ++k)
            for(int i = 1; i <= 100; ++i)
                for(int j = 1; j <= 100; ++j)
                    AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);

        vector<int> present;
        for(auto it = nodes.begin(); it != nodes.end(); ++it)   present.push_back(*it);

        int total = 0, n = present.size();
        for(int i = 0; i < n; ++i){
            from = present[i];
            for(int j = i + 1; j < n; ++j){
                to = present[j];
                total += AdjMat[from][to] + AdjMat[to][from];
            }
        }

        double frac = total;
        frac = frac / n / (n-1);
        cout << "Case " << ++tc << ": average length between pages = " << fixed << frac
             << " clicks" << endl;
    }
    return 0;
}
