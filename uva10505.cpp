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

int N;
vector<int> color;
vector< vector<int> > edges;
bool conflict;

void dfs2(int p, int c, int &nR, int &nB){
    color[p] = c;
    if(c == R)  nR += 1;
    else    nB += 1;

    int q;
    for(int i = 0; i < edges[p].size(); ++i){
        q = edges[p][i];
        if(color[q] == -1)  dfs2(q, 1-c, nR, nB);
        else if(color[q] == c){
            conflict = true;
            // break;
        }
    }
}


int main(){ _
    int TC; cin >> TC;
    while(TC--){
        cin >> N;
        color.assign(N+1, -1);
        edges.assign(N+1, vector<int> (0));

        int n, q;
        for(int i = 1; i <= N; ++i){
            cin >> n;
            for(int j = 0; j < n; ++j){
                cin >> q;
                edges[i].push_back(q);
                edges[q].push_back(i);
            }
        }

        int nR, nB, ans = 0;
        for(int i = 1; i <= N; ++i){
            if(color[i] == -1){
                nR = 0, nB = 0;
                conflict = false;
                dfs2(i, R, nR, nB);
                if(!conflict) ans += max(nR, nB);
            }
        }

        cout << ans << endl;
    }
    return 0;
}
