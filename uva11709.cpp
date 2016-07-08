#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
using namespace std;

typedef long long int64;

int n, m, dfsCounter, numSCC;
vector<int> dfs_num, dfs_low, S;
vector<string> names;
map<string, int> s2i;
vector< vector<int> > AdjList;
vector<bool> visiting;
string line, from, to;

void init(int n);
void SCC(int p);

int main(){ _
    while(cin >> n >> m){
        if(n + m == 0)  break;
        init(n);

        for(int i = 0; i < n; ++i){
            getline(cin, line);
            names[i] = line;
            s2i[line] = i;
        }

        int a, b;
        for(int i = 0; i < m; ++i){
            getline(cin, from);
            getline(cin, to);

            a = s2i[from];
            b = s2i[to];
            AdjList[a].push_back(b);
        }

        for(int i = 0; i < n; ++i){
            if(dfs_num[i] == UNVISITED)     SCC(i);
        }

        cout << numSCC << endl;
    }
    return 0;
}

void init(int n){
    dfs_num.assign(n, UNVISITED);
    dfs_low.assign(n, UNVISITED);
    S.clear();
    names.assign(n, "");
    s2i.clear();
    AdjList.assign(n, vector<int> (0));
    visiting.assign(n, false);
    dfsCounter = numSCC = 0;
    cin.ignore();
}

void SCC(int p){
    dfs_num[p] = dfs_low[p] = dfsCounter++;
    visiting[p] = true;
    S.push_back(p);

    int q;
    for(int i = 0; i< AdjList[p].size(); ++i){
        q = AdjList[p][i];
        if(dfs_num[q] == UNVISITED) SCC(q);
        if(visiting[q]) dfs_low[p] = min(dfs_low[p], dfs_low[q]);
    }

    if(dfs_num[p] == dfs_low[p]){
        ++numSCC;
        while(true){
            q = S.back();
            S.pop_back();
            visiting[q] = false;

            if(q == p)  break;
        }
    }
}
