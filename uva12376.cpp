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

void dfs(int node, vector<int> &nodes, vector< vector<int> > &AdjList){
    int unit = 0, maxVal, maxId, nextNode;
    while(AdjList[node].size()){
        maxVal = -1, maxId = -1;
        for(int i = 0; i < AdjList[node].size(); ++i){
            nextNode = AdjList[node][i];
            if(nodes[nextNode] > maxVal){
                maxVal = nodes[nextNode];
                maxId = nextNode;
            }
        }
        unit += maxVal;
        node = maxId;
    }

    cout << unit <<  " " << node << endl;
}

int main(){ _
    int TC; cin >> TC;
    for(int tc = 1; tc <= TC; ++tc){
        int n, m;  cin >> n >> m;
        vector<int> nodes(n, 0);
        for(int i = 0; i < n; ++i)  cin >> nodes[i];

        vector< vector<int> > AdjList(n);
        int from, to;
        for(int i = 0; i < m; ++i){
            cin >> from >> to;
            AdjList[from].push_back(to);
        }

        cout << "Case " << tc << ": ";
        dfs(0, nodes, AdjList);
    }
    return 0;
}
