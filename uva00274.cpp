#include <bits/stdc++.h>
#define UNVISITED -1
#define BIGINT 1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

/* A good test case:
2
10 1 2
-1 -1
2 1
1 2

100 50 50
-1 -1

The answer should be
Y N

Y N
*/

int main(){ _
    int tc; cin >> tc;
    while(tc--){
        int n, c, m;    cin >> n >> c >> m;
        vector< vector<bool> > cat(n+1, vector<bool> (n+1, false));
        vector< vector<bool> > mouse(n+1, vector<bool> (n+1, false));
        vector< vector<bool> > mouse2(n+1, vector<bool> (n+1, false));
        // read input
        int u, v;
        while(cin >> u >> v){
            if(u == -1) break;
            cat[u][v] = true;
        }
        cin.ignore();
        string line;
        stringstream ss;
        while(getline(cin, line)){
            if(line == "")  break;
            ss.clear();
            ss.str("");
            ss << line;
            ss >> u >> v;
            mouse[u][v] = mouse2[u][v] = true;
        }
        cat[c][c] = true;   // the initial room occupied by the cat and mouse should be
        mouse[m][m] = true; // set to true
                            // but mouse2[m][m] is still false, since the task is to find
                            // if this will be ture

        // find answer for q1
        for(int k = 1; k <= n; ++k)
            for(int i = 1; i <= n; ++i)
                for(int j = 1; j <= n; ++j){
                    cat[i][j] = cat[i][j] | (cat[i][k] & cat[k][j]);
                    mouse[i][j] = mouse[i][j] | (mouse[i][k] & mouse[k][j]);
                }

        bool q1 = false;
        for(int i = 1; i <= n; ++i)
            q1 = q1 | (cat[c][i] & mouse[m][i]);

        // find answer for q1
        // first set all possible place reachable by the cat to be unreachable for the mouse
        for(int i = 1; i <= n; ++i)
            if(cat[c][i]){
                for(int j = 1; j <= n; ++j)     mouse2[i][j] = mouse2[j][i] = false;
            }

        for(int k = 1; k <= n; ++k)
            for(int i = 1; i <= n; ++i)
                for(int j = 1; j <= n; ++j)
                    mouse2[i][j] = mouse2[i][j] | (mouse2[i][k] & mouse2[k][j]);

        bool q2 = mouse2[m][m];

        cout << (q1 ? "Y" : "N") << " " << (q2 ? "Y" : "N") << endl;
        if(tc)  cout << endl;

    }
    return 0;
}
