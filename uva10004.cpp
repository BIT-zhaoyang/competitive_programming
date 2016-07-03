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
bool fail;
vector<int> color;
vector< vector<int> > edges;

void dfs2(int p, int c){
    color[p] = c;

    int q;
    for(int i = 0; i < edges[p].size(); ++i){
        q = edges[p][i];
        if(color[q] == -1)  dfs2(q, 1 - c);
        else if(color[q] == c){
            fail =  true;
            break;
        }
    }
}

int main(){ _
    while(cin >> n){
        if(n == 0)  break;
        else    cin >> m;

        color.assign(n, -1);
        edges.assign(n, vector<int> (0));
        fail = false;

        for(int i = 0; i < m; ++i){
            cin >> a >> b;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }

        dfs2(0, R);

        if(!fail)    cout << "BICOLORABLE." << endl;
        else    cout << "NOT BICOLORABLE." << endl;
    }
    return 0;
}
