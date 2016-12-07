#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

/* 厉害了我的哥。Maximum Independent Set problem! */

int h, w;
vector< vector<int> > AdjList;
vector<int> match;
vector<bool> visited;

int aug_path(int u){
    if(visited[u])  return 0;
    visited[u] = true;
    for(auto v : AdjList[u])
        if(match[v] == -1 || aug_path(match[v])){
            match[v] = u;
            return 1;
        }
    return 0;
}

int main(){ _
    int tc; cin >> tc;
    while(tc--){
        cin >> h >> w;
        int total = 0;
        vector< vector<char> > input(h, vector<char> (w, ' '));
        for(int i = 0; i < h; ++i)
            for(int j = 0; j < w; ++j){
                cin >> input[i][j];
                if(input[i][j] == '*')  total += 1;
            }

        AdjList.assign(h * w, vector<int> (0));
        for(int i = 0; i < h; ++i){
            for(int j = 0; j < w; ++j){
                if((i + j) % 2 && input[i][j] == '*'){    // nodes with i + j = odd on the left side
                    if(i - 1 >= 0 && input[i - 1][j] == '*')
                        AdjList[i * w + j].push_back((i - 1) * w + j);
                    if(i + 1 < h && input[i + 1][j] == '*')
                        AdjList[i * w + j].push_back((i + 1) * w + j);
                    if(j - 1 >= 0 && input[i][j - 1] == '*')
                        AdjList[i * w + j].push_back(i * w + j - 1);
                    if(j + 1 < w && input[i][j + 1] == '*')
                        AdjList[i * w + j].push_back(i * w + j + 1);
                }
            }
        }

        match.assign(h * w, -1);
        int MCBM = 0;
        for(int i = 0; i < h * w; ++i){
            visited.assign(h * w, false);
            MCBM += aug_path(i);
        }

        cout << total - MCBM << endl;
    }
    return 0;
}
