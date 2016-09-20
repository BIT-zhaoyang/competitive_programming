#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 28
using namespace std;

/* Can be translated into longest path problem. Longest path problem is only well defined on acyclic DAG. */

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
    int tc; cin >> tc;
    while(tc--){
        int n;  cin >> n;
        map<string, int> s2i;
        vector<string> names(n, "");
        vector< vector<int> > AdjMat(n, vector<int> (n, -BIGINT));

        for(int i = 0; i < n; ++i){
            cin >> names[i];
        }
        sort(names.begin(), names.end());
        for(int i = 0; i < n; ++i){
            s2i[names[i]] = i;
        }

        cin >> n;
        int m, u, v;
        string stru, strv;
        for(int i = 0; i < n; ++i){
            cin >> stru >> m;
            u = s2i[stru];
            for(int j = 0; j < m; ++j){
                cin >> strv;
                v = s2i[strv];
                AdjMat[u][v] = 1;
            }
        }

        n = names.size();
        for(int k = 0; k < n; ++k)
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    AdjMat[i][j] = max(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);

        for(int i = 0; i < n; ++i){
            vector<int> ans;
            for(int j = 0; j < n; ++j)
                if(AdjMat[i][j] == 1)
                    ans.push_back(j);
            if(ans.size()){
                cout << names[i] << " " << ans.size();
                for(int j = 0; j < ans.size(); ++j)
                    cout << " " << names[ans[j]];
                cout << endl;
            }
        }


    }
    return 0;
}
