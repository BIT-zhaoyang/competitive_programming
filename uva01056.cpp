#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
    int P, R, tc = 0;
    while(cin >> P >> R){
        if(P == 0)  break;
        map<string, int> s2i;
        vector<string> names;
        string stru, strv;
        int u, v;

        vector< vector<int> > AdjMat(P, vector<int> (P, BIGINT));
        for(int i = 0; i < P; ++i)  AdjMat[i][i] = 0;
        for(int i = 0; i < R; ++i){
            cin >> stru >> strv;
            if(!s2i.count(stru)){
                names.push_back(stru);
                s2i[stru] = names.size() - 1;
            }

            if(!s2i.count(strv)){
                names.push_back(strv);
                s2i[strv] = names.size() - 1;
            }

            u = s2i[stru],  v = s2i[strv];
            AdjMat[u][v] = AdjMat[v][u] = 1;
        }

        for(int k = 0; k < P; ++k)
            for(int i = 0; i < P; ++i)
                for(int j = 0; j < P; ++j)
                    AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);

        int maximum = 0;
        for(int i = 0; i < P; ++i)
            for(int j = 0; j < P; ++j)
                maximum = max(maximum, AdjMat[i][j]);

        cout << "Network " << ++tc << ": ";
        if(maximum == BIGINT)   cout << "DISCONNECTED" << endl;
        else    cout << maximum << endl;
        cout << endl;
    }
    return 0;
}
