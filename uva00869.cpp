#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
    int tc, n, m; cin >> tc;
    char u, v;
    while(tc--){
        vector< vector<bool> > Mat1(26, vector<bool> (26, false));
        vector< vector<bool> > Mat2(26, vector<bool> (26, false));

        cin >> n;
        for(int i = 0; i < n; ++i){
            cin >> u >> v;
            Mat1[u-'A'][v-'A'] = true;
        }

        cin >> m;
        for(int i = 0; i < m; ++i){
            cin >> u >> v;
            Mat2[u-'A'][v-'A'] = true;
        }

        for(int k = 0; k < 26; ++k)
            for(int i = 0; i < 26; ++i)
                for(int j = 0; j < 26; ++j){
                    Mat1[i][j] = Mat1[i][j] | (Mat1[i][k] & Mat1[k][j]);
                    Mat2[i][j] = Mat2[i][j] | (Mat2[i][k] & Mat2[k][j]);
                }

        bool fail = false;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                fail = fail | (Mat1[i][j] ^ Mat2[i][j]);

        cout << (fail ? "NO" : "YES") << endl;
        if(tc)  cout << endl;
    }
    return 0;
}
