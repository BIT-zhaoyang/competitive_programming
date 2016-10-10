#include <bits/stdc++.h>
#define UNVISITED -1
#define BIGINT 1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
    int n, tc = 0;
    while(cin >> n){
        if(tc++)    cout << endl;
        vector<int> ways(n, 0);     ways[0] = 1;
        int ans = 0;
        for(int i = 0; i < n; ++i){
            int m;  cin >> m;
            if(m == 0)  ans += ways[i];
            for(int j = 0; j < m; ++j){
                int next;   cin >> next;
                ways[next] += ways[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
