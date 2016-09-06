#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 25
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
    int n;
    while(cin >> n){
        if(n == 0)  break;
        vector< vector<int> > old(n+1, vector<int> (n+1, BIGINT));
        vector< vector<int> > prop(n+1, vector<int> (n+1, BIGINT));
        for(int i = 0; i <= n; ++i)
            old[i][i] = prop[i][i] = 0;

        stringstream ss;
        string str;
        cin.ignore();
        int v;
        for(int u = 1; u <= n; ++u){
            getline(cin, str);
            ss.clear();
            ss.str("");
            ss << str;
            ss >> v;
            while (ss >> v) {
                old[u][v] = 1;
            }
        }

        for(int u = 1; u <= n; ++u){
            getline(cin, str);
            ss.clear();
            ss.str("");
            ss << str;
            ss >> v;
            while (ss >> v) {
                prop[u][v] = 1;
            }
        }

        int A, B;   cin >> A >> B;
        //floyd warshall
        for(int k = 1; k <= n; ++k)
            for(int i = 1; i <= n; ++i)
                for(int j = 1; j <= n; ++j){
                    old[i][j] = min(old[i][j], old[i][k] + old[k][j]);
                    prop[i][j] = min(prop[i][j], prop[i][k] + prop[k][j]);
                }

        bool success = true;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                success &= (prop[i][j] <= (A * old[i][j] + B));

        cout << (success ? "Yes" : "No") << endl;
    }
    return 0;
}
