#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT  1 << 25
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;


int main(){ _
    int n, tc = 0;
    while(cin >> n){
        if(n == 0)  break;
        vector< vector<int> > AdjMat(n+1, vector<int> (n+1, BIGINT));
        vector< vector<int> > parent(n+1, vector<int> (n+1, -1));

        int npath, delay, from, to;
        for(from = 1; from <= n; ++from){
            cin >> npath;
            for(int j = 0; j < npath; ++j){
                cin >> to >> delay;
                AdjMat[from][to] = delay;
                parent[from][to] = from;
            }
        }

        for(int k = 1; k <= n; ++k){
            for(int i = 1; i <= n; ++i){
                for(int j = 1; j <= n; ++j){
                    if(AdjMat[i][k] + AdjMat[k][j] < AdjMat[i][j]){
                        AdjMat[i][j] = AdjMat[i][k] + AdjMat[k][j];
                        parent[i][j] = parent[k][j];
                    }
                }
            }
        }

        cin >> from >> to;
        delay = AdjMat[from][to];
        cout << "Case " << ++tc << ": Path =";
        stack<int> si;
        while(to != from){
            si.push(to);
            to = parent[from][to];
        }
        si.push(from);
        while(!si.empty()){
            cout << " " << si.top();
            si.pop();
        }
        cout << "; " << delay << " second delay" << endl;
    }
    return 0;
}
