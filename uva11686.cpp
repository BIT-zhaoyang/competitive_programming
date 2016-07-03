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

int n, m, a, b;
bool loop;
vector<int> visited;
vector<int> taken;
vector<int> ans;
vector< vector<int> > edges;

void dfs2(int p){
    visited[p] = true;

    int q;
    for(int i = 0; i < edges[p].size(); ++i){
        q = edges[p][i];
        if(!visited[q]) dfs2(q);
        else if(!taken[q]) loop = true;
    }

    ans.push_back(p);
    taken[p] = true;
}

int main(){ _
    while(cin >> n >> m){
        if(n + m == 0)  break;

        loop = false;
        visited.assign(n+1, false);
        taken.assign(n+1, false);
        ans.clear();
        edges.assign(n+1, vector<int> (0));

        for(int i = 0; i < m; ++i){
            cin >> a >> b;
            edges[a].push_back(b);
        }

        for(int i = 1; i <= n; ++i){
            if(!taken[i])   dfs2(i);
        }

        if(loop)    cout << "IMPOSSIBLE" << endl;
        else{
            for(int i = ans.size()-1; i >= 0; --i)  cout << ans[i] << endl;
        }
    }
    return 0;
}
