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
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
using namespace std;

int n, m, dfsCounter, id1, id2;
vector<string> names;
vector<int> dfs_num, dfs_low, stack;
vector<bool> visiting;
vector< vector<int> > AdjList;
string a, b;
map<string, int> name2id;

void SCC(int p){
    dfs_num[p] = dfs_low[p] = dfsCounter++;
    visiting[p] = true;
    stack.push_back(p);

    int q;
    for(int i = 0; i < AdjList[p].size(); ++i){
        q = AdjList[p][i];

        // if(dfs_num[q] == UNVISITED) SCC(q);
        // if(visiting[q]) dfs_low[p] = min(dfs_low[p], dfs_low[q]);

        // This implementation has a better strucutre of the idea behind the algorithm
        if(dfs_num[q] == UNVISITED){
            SCC(q);
            dfs_low[p] = min(dfs_low[p], dfs_low[q]);
        } else if(visiting[q]){
            dfs_low[p] = min(dfs_low[p], dfs_num[q]);
        }
    }

    if(dfs_low[p] == dfs_num[p]){
        while(true){
            q = stack.back();
            stack.pop_back();
            visiting[q] = false;

            if(q != p){
                cout << names[q] << ", ";
            } else {
                cout << names[q] << endl;
                break;
            }
        }
    }

}

int main(){ _
    int tc = 0;
    while(cin >> n >> m){
        if(n + m == 0)  break;

        if(tc)  cout << endl;
        cout << "Calling circles for data set " << ++tc << ":" << endl;
        dfsCounter = 0;
        dfs_num.assign(n, UNVISITED);
        dfs_low.assign(n, UNVISITED);
        visiting.assign(n, false);
        AdjList.assign(n, vector<int> (0));
        stack.clear();
        name2id.clear();
        names.clear();

        for(int i = 0; i < m; ++i){
            cin >> a >> b;
            if(name2id.count(a)){
                id1 = name2id[a];
            } else {
                id1 = name2id.size();
                name2id[a] = id1;
                names.push_back(a);
            }

            if(name2id.count(b)){
                id2 = name2id[b];
            } else {
                id2 = name2id.size();
                name2id[b] = id2;
                names.push_back(b);
            }

            AdjList[id1].push_back(id2);
        }

        for(int i = 0; i < n; ++i){
            if(dfs_num[i] == UNVISITED) SCC(i);
        }

    }
    return 0;
}
