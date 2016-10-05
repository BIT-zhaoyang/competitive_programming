#include <bits/stdc++.h>
#define UNVISITED -1
#define BIGINT 1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
    int tc; cin >> tc;
    vector<int> npath[2];
    while(tc--){
        int W, N;   cin >> W >> N;  cin.ignore();
        npath[0].assign(N + 1, 0);  npath[0][1] = 1;
        npath[1].assign(N + 1, 0);
        string line;
        int widx, nidx, pre = 0, cur = 1;
        for(int i = 0; i < W; ++i){
            npath[cur].assign(N + 1, 0);
            getline(cin, line);
            stringstream ss(line);
            ss >> widx;
            while(ss >> nidx)   npath[cur][nidx] = -1;

            for(int i = 1; i <= N; ++i)
                if(npath[cur][i] != -1)
                    npath[cur][i] += npath[cur][i - 1] + npath[pre][i];
                else
                    npath[cur][i] = 0;

            pre = 1 - pre,  cur = 1 - cur;
        }

        cout << npath[pre][N] << endl;
        if(tc)  cout << endl;
    }
    return 0;
}
