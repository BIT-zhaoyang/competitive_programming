#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int n, m, uniq;
map<string, int> s2i;
vector<int> plug, match;
vector<bool> visited;
vector< vector<int> > adapt, AdjList;

void bfs(int u){
    queue<int> Q;
    Q.push(u);
    visited[u] = true;
    while(Q.size()){
        u = Q.front();  Q.pop();
        for(auto v : adapt[u]){
            if(!visited[v]){
                visited[v] = true;
                Q.push(v);
            }
        }
    }
}

int aug_path(int u){
    if(visited[u])  return 0;
    visited[u] = true;
    for(auto v : AdjList[u]){
        if(match[v] == -1 || aug_path(match[v])){
            match[v] = u;
            return 1;
        }
    }
    return 0;
}

int main(){ _
    int tc; cin >> tc;
    while(tc--){
        s2i.clear();
        plug.clear();
        uniq = 0;
        cin >> n;
        for(int i = 0; i < n; ++i){
            string str; cin >> str;
            s2i[str] = uniq++;
            plug.push_back(s2i[str]);
        }

        cin >> m;
        for(int i = 0; i < m; ++i){
            string str; cin >> str >> str;
            if(s2i.count(str) == 0) s2i[str] = uniq++;
            plug.push_back(s2i[str]);
        }

        adapt.assign(uniq, vector<int> (0));
        int k;  cin >> k;
        for(int i = 0; i < k; ++i){
            string su, sv;  cin >> su >> sv;
            if(s2i.count(su) == 0){  s2i[su] = uniq++;  adapt.push_back(vector<int> (0)); }
            if(s2i.count(sv) == 0){  s2i[sv] = uniq++;  adapt.push_back(vector<int> (0)); }
            int u = s2i[su], v = s2i[sv];
            adapt[u].push_back(v);
        }

        AdjList.assign(n + m, vector<int> (0));
        for(int i = n; i < n + m; ++i){
            int u = plug[i];
            visited.assign(uniq, false);
            bfs(u);
            for(int j = 0; j < n; ++j)
                if(visited[j])
                    AdjList[i].push_back(j);
        }

        int MCBM = 0;
        match.assign(n + m, -1);
        for(int i = n; i < n + m; ++i){
            visited.assign(n + m, false);
            MCBM += aug_path(i);
        }
        cout << m - MCBM << endl;
        if(tc)  cout << endl;
    }
    return 0;
}
