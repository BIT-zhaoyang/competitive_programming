#include <bits/stdc++.h>
#define UNVISITED -1
#define BIGINT 1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

vector< vector<int> > res;
vector<int> parent;
queue<int> Q;
const int s = 0, t = 37;
int f, mf, totalUser;

void init(){
    // 38 vertices in total
    // 0: s     37: t
    // 1 - 26: applications
    // 27 - 36: computers
    res.assign(38, vector<int> (38, 0));
    totalUser = 0;

    // init maxFlow value
    mf = 0;

    // connect all computers to the super sink
    // connection of super source with applications will be done in reading input part since only some applications are mentioned
    for(int i = 27; i <= 36; ++i)   res[i][t] = 1;
}

void augment(int u, int minEdge){
    if(u == s)  {f = minEdge;   return; }
    else if(parent[u] != -1){
        minEdge = min(minEdge, res[parent[u]][u]);
        augment(parent[u], minEdge);
        res[parent[u]][u] -= f;
        res[u][parent[u]] += f;
    }
}

void print(){
    if(totalUser != mf){ cout << "!" << endl;   return; }
    else {
        for(int i = 27; i <= 36; ++i){
            bool connect = false;
            for(int j = 1; j <= 26; ++j)
                if(res[i][j] == 1){
                    cout << char('A' + j - 1);
                    connect = true;
                    break;
                }
            if(!connect)    cout << "_";
        }
        cout << endl;
    }
}

void process(){
    // Edmond-Karp
    while(true){
        // BFS to find a path
        // init BFS
        parent.assign(38, -1);
        parent[s] = 0;
        Q.push(s);
        // BFS search
        while(!Q.empty()){
            int u = Q.front();  Q.pop();
            for(int v = 0; v < res[u].size(); ++v)
                if(res[u][v] > 0 && parent[v] == -1)
                    parent[v] = u, Q.push(v);
        }
        // augment path
        f = 0;
        augment(t, BIGINT);
        mf += f;

        if(f == 0)  break;
    }
    // print result
    print();
}

int main(){ _
    string line;
    char app, nUser, id;
    int appId, compId;

    init();
    while(getline(cin, line)){
        if(line == ""){
            process();
            init();
            continue;
        } else {
            stringstream ss;
            ss << line;
            ss >> app >> nUser;
            appId = app - 'A' + 1;
            res[s][appId] = nUser - '0';
            totalUser += nUser - '0';
            while(ss >> id){
                if(id == ';')   break;
                compId = id - '0' + 27;
                res[appId][compId] = 1;
            }
        }
    }
    process();
    return 0;
}
