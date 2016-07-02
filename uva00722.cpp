#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
bool visited[100][100];
const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

void dfs(int r, int c, int& ans, vector< string >& vs){
    visited[r][c] = true;
    ++ans;

    int nr, nc, N = vs.size(), M = vs[0].size();
    for(int i = 0; i < sizeof(dr)/sizeof(int); ++i){
        nr = r + dr[i], nc = c + dc[i];
        if(nr < 0 || nr >= N || nc < 0 || nc >= M || visited[nr][nc] || vs[nr][nc] == '1')  continue;

        dfs(nr, nc, ans, vs);
    }
}

int main(){ _
    int TC; cin >> TC;
    while(TC--){
        int r, c;   cin >> r >> c;
        --r, --c;
        cin.ignore();
        memset(visited, 0, sizeof visited);

        string str;
        vector< string > vs;
        while(getline(cin, str)){
            if(str == "")   break;
            vs.push_back(str);
        }

        int nElement = 0;
        dfs(r, c, nElement, vs);

        cout << nElement << endl;
        if(TC)  cout << endl;
    }
    return 0;
}
