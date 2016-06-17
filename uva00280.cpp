#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

// Not standfard dfs. Modified according to the problem description.
void dfs(int s, vector<bool> &visited, vector< vector<int> > &AdjList){
    // visited[s] = true;
    int neib;
    for(int i = 0; i < AdjList[s].size(); ++i){
        neib = AdjList[s][i];
        if(!visited[neib]){
            visited[neib] = true;
            dfs(neib, visited, AdjList);
        }
    }
}

int main(){ _
    int n;
    while(cin >> n){
        if(n == 0)  break;
        vector< vector<int> > AdjList(n+1);
        vector<bool> visited(n+1, false);

        int node, neib;
        while(cin >> node){
            if(node == 0)   break;
            while(cin >> neib){
                if(neib == 0)   break;
                AdjList[node].push_back(neib);
            }
        }

        int Q, s;  cin >> Q;
        while(Q--){
            cin >> s;
            visited.assign(n+1, false);

            dfs(s, visited, AdjList);

            int ans = 0;
            for(int i = 1; i < visited.size(); ++i){
                if(!visited[i]) ++ans;
            }

            cout << ans;
            if(ans) cout << " ";
            for(int i = 1; ans > 0; ++i){
                if(!visited[i]){
                    cout << i;
                    --ans;
                    if(ans) cout << " ";
                }
            }
            cout << endl;
        }

    }
    return 0;
}
