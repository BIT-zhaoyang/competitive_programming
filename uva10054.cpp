#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define POS_INF 1 << 28
#define NEG_INF -1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int nEdge;
vector<int> tour;
vector< list<int> > AdjList;

void init(){
    tour.clear();
    AdjList.assign(51, list<int> (0));
}

void read_input(){
    cin >> nEdge;
    for(int i = 0; i < nEdge; ++i){
        int u, v;   cin >> u >> v;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }
}

void euler_tour(int u){
    while(AdjList[u].size()){
        int v = *AdjList[u].begin();
        AdjList[u].pop_front();
        for(auto it = AdjList[v].begin(); it != AdjList[v].end(); ++it){
            if(*it == u){
                AdjList[v].erase(it);
                break;
            }
        }
        euler_tour(v);
    }
    tour.push_back(u);
}

void euler_tour(){
    int root = -1;
    for(int i = 1; i < 51; ++i){
        if(AdjList[i].size())   root = i;
        if(AdjList[i].size() % 2){
            cout << "some beads may be lost" << endl;
            return;
        }
    }

    euler_tour(root);
    if(nEdge + 1 != tour.size()){
        cout << "some beads may be lost" << endl;
        return;
    }

    for(int i = 0; i + 1 < tour.size(); ++i)
        cout << tour[i] << " " << tour[i + 1] << endl;
}

int main(){ _
    int TC; cin >> TC;
    for(int tc = 1; tc <= TC; ++tc){
        if(tc > 1)  cout << endl;
        cout << "Case #" << tc << endl;
        init();
        read_input();
        euler_tour();
    }
    return 0;
}
