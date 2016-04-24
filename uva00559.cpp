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
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);

using namespace std;

vector<vector<int> > graph(26);
vector<int> nodes;
vector<bool> visited(26);

void dfs(int node, int &n_node, int &n_edge){
    visited[node] = true;
    n_node += 1;
    n_edge += graph[node].size();
    for(int i = 0; i < graph[node].size(); ++i){
        int neib = graph[node][i];
        if(!visited[neib])  dfs(neib, n_node, n_edge);
    }
}

int main(){ _
    int T;  cin >> T;
    string line;
    int start, end;
    while(T--){
        graph.assign(26, vector<int> (0));
        nodes.clear();
        visited.assign(26, false);

        while(cin >> line, line[0] != '*'){
            start = line[1] - 'A';
            end = line[3] - 'A';
            graph[start].push_back(end);
            graph[end].push_back(start);
        };

        cin >> line;
        for(int i = 0; i < line.size(); ++i){
            if(isalpha(line[i]))
                nodes.push_back(line[i]-'A');
        }

        int acorn = 0, tree = 0;
        for(int i = 0; i < nodes.size(); ++i){
            int n_node = 0, n_edge = 0;
            if(graph[nodes[i]].size() == 0){
                acorn += 1;
                continue;
            }

            if(!visited[nodes[i]])  dfs(nodes[i], n_node, n_edge);
            if(n_edge / 2 == n_node-1) tree += 1;
        }

        cout << "There are " << tree << " tree(s) and " << acorn << " acorn(s)." << endl;
    }
    return 0;
}
