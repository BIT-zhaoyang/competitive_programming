#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
    int n, m;
    while(cin >> n){
        int start = 0, root = -1;
        vector< ii > neib(n, ii(0, 0));
        vector<int> final;

        for(int i = 0; i < n; ++i){
            char curr, left, right, type;
            cin >> curr >> left >> right >> type;
            if(type == 'x') final.push_back(i);
            neib[curr - 'A'] = ii(left - 'A', right - 'A');
        }

        int pre = 0, cur = 1;
        vector<int64> ways[2] = {vector<int64> (n, 0), vector<int64> (n, 0)};
        ways[pre][0] = 1;

        cin >> m;
        for(int j = 0; j < m; ++j){
            ways[cur].assign(n, 0LL);
            for(int i = 0; i < n; ++i){
                int left, right;
                left = neib[i].first,   right = neib[i].second;
                ways[cur][left] += ways[pre][i];
                ways[cur][right] += ways[pre][i];
            }
            pre = 1 - pre,  cur = 1 - cur;
        }

        int64 ans = 0;
        for(int i = 0; i < final.size(); ++i)
            ans += ways[pre][final[i]];

        cout << ans << endl;
    }
    return 0;
}
