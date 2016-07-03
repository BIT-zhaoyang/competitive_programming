#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <climits>
#include <cmath>
#include <set>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <queue>
#include <stack>
#include <tuple>

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

#define R 0
#define B 1

int n, m, a, b;
bool conflict;
vector<int> color;
vector< vector<int> > edges;

void dfs2(int p, int c, int &nR, int &nB){
    color[p] = c;
    if(c == R)  ++nR;
    else    ++nB;

    int q;
    for(int i = 0; i < edges[p].size(); ++i){
        q = edges[p][i];
        if(color[q] == -1)  dfs2(q, 1 - c, nR, nB);
        else if(color[q] == c)  conflict = true;
    }
}

int main(){ _
    int tc; cin >> tc;
    while(tc--){
        cin >> n >> m;
        color.assign(n, -1);
        edges.assign(n, vector<int> (0));

        for(int i = 0; i < m; ++i){
            cin >> a >> b;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }

        int ans = 0, nR = 0, nB = 0;
        conflict = false;
        for(int i = 0; i < n; ++i){
            if(color[i] == -1){
                nR = 0, nB = 0;
                dfs2(i, R, nR, nB);
                if(nR != 0 && nB != 0)  ans += min(nR, nB);
                else    ans += max(nR, nB);
            }
        }

        if(!conflict)   cout << ans << endl;
        else    cout << -1 << endl;
    }
    return 0;
}
