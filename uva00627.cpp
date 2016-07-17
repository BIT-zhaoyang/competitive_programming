#include <algorithm>
#include <bitset>
#include <cstring>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <sstream>
#include <vector>

#define UNVISITED -1
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

vector< vector<int> > AdjList;
vector<int> dist, parent;
queue<int>  Q;

void bsf(int s){
    Q.push(s);  dist[s] = 0;
    int p, q;
    while(!Q.empty()){
        p = Q.front();  Q.pop();
        for(int i = 0; i < AdjList[p].size(); ++i){
            q = AdjList[p][i];
            if(dist[q] == UNVISITED){
                dist[q] = dist[p] + 1;
                parent[q] = p;
                Q.push(q);
            }
        }
    }
}

void backtrack(int source, int node){
    if(node == source)  cout << source;
    else{
        backtrack(source, parent[node]);
        cout << " " << node;
    }
}

int main(){ _
    int n, m, u, v;  string str;    char ch;
    stringstream ss;
    while(cin >> n){
        cout << "-----" << endl;
        AdjList.assign(n+1, vector<int> (0));
        for(int i = 0; i < n; ++i){
            cin >> str;
            ss.clear(); ss.str("");
            ss << str;
            ss >> u;
            while(ss >> ch >> v){
                AdjList[u].push_back(v);
            }
        }

        cin >> m;
        for(int i = 0; i < m; ++i){
            cin >> u >> v;
            dist.assign(n+1, UNVISITED);
            parent.assign(n+1, UNVISITED);
            bsf(u);
            if(dist[v] == UNVISITED){
                cout << "connection impossible" << endl;
                continue;
            } else {
                backtrack(u, v);
                cout << endl;
            }
        }
    }
    return 0;
}
