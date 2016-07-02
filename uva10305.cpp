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

int n, m;
vector<bool> visited;
vector< vector<int> > edges;
vector<int> ans;

void tps(int p){
    visited[p] = true;

    int q;
    for(int i = 0; i < edges[p].size(); ++i){
        q = edges[p][i];
        if(!visited[q]) tps(q);
    }
    ans.push_back(p);
}

int main(){ _

    while(cin >> n >> m){
        if(n + m == 0)  break;
        visited.assign(n+1, false);
        edges.assign(n+1, vector<int> (0));
        ans.clear();

        int a, b;
        for(int i = 0; i < m; ++i){
            cin >> a >> b;
            edges[a].push_back(b);
        }

        for(int i = 1; i <= n; ++i){
            if(!visited[i])   tps(i);
        }

        for(int i = ans.size()-1; i >= 0; --i){
            cout << ans[i];
            if(i)   cout << " ";
        }   cout << endl;
    }
    return 0;
}
