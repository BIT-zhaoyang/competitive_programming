#include <bits/stdc++.h>
#define UNVISITED -1
#define BIGINT 1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

/* Nice problem. After all, it's at least a regional ACM problem. 
If the CP3 doesn't tell me this can be solved using floyd-warshall, I probably won't be able to come up with the soluiton. But after I know this information, I found that this is a cheapest cycle problem. See CP3 page 159 for reference. */

int main(){ _
    int tc; cin >> tc;
    while(tc--){
        int cap, n;     cin >> cap >> n;
        vector< vector<int> > AdjMat(n+1, vector<int> (n+1, BIGINT));

        int m, next, coins;
        // read choices of the usher
        cin >> m;
        for(int i = 0; i < m; ++i){
            cin >> next;
            AdjMat[0][next] = 0;
        }

        // read choices of the parishioner
        for(int i = 1; i <= n; ++i){
            cin >> m;
            for(int j = 0; j < m; ++j){
                cin >> coins >> next;
                AdjMat[i][next] = min(AdjMat[i][next], coins);
            }
        }

        // use floyd-warshall to find the cheapest cycle
        for(int k = 0; k <= n; ++k)
            for(int i = 0; i <= n; ++i)
                for(int j = 0; j <= n; ++j)
                    AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);

        int receive = AdjMat[0][0], acc = AdjMat[0][0], steal = 0; // acc: accumulated coins in the box
        while(acc < cap){
            acc += receive - 1;
            steal += 1;
        }

        cout << steal << endl;
    }
    cin >> tc;   // takes the extra 0??
    return 0;
}
