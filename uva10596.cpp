#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

vector<int> degree, visit;
vector< vector<int> > AdjList;

bool isConnect(){
    int root = -1;
    for(int i = 0; i < degree.size(); ++i)
        if(degree[i] != 0){
            root = i;
            break;
        }

    visit[root] = true;
    queue<int> Q;   Q.push(root);
    while(Q.size()){
        int u = Q.front();  Q.pop();
        for(auto v : AdjList[u])
            if(visit[v] == UNVISITED){
                visit[v] = true;
                Q.push(v);
            }
    }

    for(int i = 0; i < degree.size(); ++i)
        if(degree[i] != 0 && visit[i] == UNVISITED)
            return false;

    return true;
}

int main(){ _
    int N, M;
    while(cin >> N >> M){
        if(M == 0){
            cout << "Not Possible" << endl;
            continue;
        }
        AdjList.assign(N, vector<int> (0));
        degree.assign(N, 0);    visit.assign(N, UNVISITED);
        for(int i = 0; i < M; ++i){
            int u, v;   cin >> u >> v;
            AdjList[u].push_back(v);
            AdjList[v].push_back(u);
            ++degree[u], ++degree[v];
        }

        bool possible = true;
        for(int i = 0; i < N; ++i)
            if(degree[i] % 2){
                possible = false;
                break;
            }
        if(!possible){
            cout << "Not Possible" << endl;
            continue;
        }

        possible = isConnect();
        if(!possible){
            cout << "Not Possible" << endl;
            continue;
        }

        cout << "Possible" << endl;
    }
    return 0;
}
