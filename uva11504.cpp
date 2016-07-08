#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
using namespace std;

typedef long long int64;

int n, m, from, to, dfsCounter, numSCC;
vector<int> S;
vector<bool> visiting;
vector< vector<int> > AdjList;

void dfs2(int p){
    visiting[p] = true;

    int q;
    for(int i = 0; i < AdjList[p].size(); ++i){
        q = AdjList[p][i];
        if(!visiting[q])    dfs2(q);
    }
    S.push_back(p);
}

void dfs(int p){
    visiting[p] = true;

    int q;
    for(int i = 0; i < AdjList[p].size(); ++i){
        q = AdjList[p][i];
        if(!visiting[q])    dfs(q);
    }
    S.push_back(p);
}

int main(){ _
    int tc; cin >> tc;
    while(tc--){
        cin >> n >> m;
        visiting.assign(n, false);
        AdjList.assign(n, vector<int> (0));
        S.clear();
        numSCC = 0;

        for(int i = 0; i < m; ++i){
            cin >> from >> to;
            --from, --to;
            AdjList[from].push_back(to);
        }

        for(int i = 0; i < n; ++i){
            if(!visiting[i])    dfs2(i);
        }
        visiting.assign(n, false);

        int p;
        for(int i = n-1; i >= 0; --i){
            p = S[i];
            if(!visiting[p]){
                ++numSCC;
                dfs(p);
            }
        }

        cout << numSCC << endl;
    }
    return 0;
}
