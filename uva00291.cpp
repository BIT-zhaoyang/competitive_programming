#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define POS_INF 1 << 28
#define NEG_INF -1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

vector<int> tour;
vector< vector<bool> > AdjList;
void init(){
    AdjList.assign(6, vector<bool> (6, true));
    for(int i = 0; i < 6; ++i)  AdjList[i][i] = false;

    AdjList[1][4] = false;
    AdjList[2][4] = false;
    AdjList[4][1] = AdjList[4][2] = false;
}

void euler_tour(int u){
    tour.push_back(u);
    for(int v = 1; v < 6; ++v){
        if(AdjList[u][v]){  // this path still exists
            AdjList[u][v] = false;  // take this path(done in next recursion) and remove it(in this recursion)
            AdjList[v][u] = false;  // remove the bi-directional path
            euler_tour(v);  // go deeper
            tour.pop_back();     // restore the state
            AdjList[u][v] = true;
            AdjList[v][u] = true;
        }
    }
    if(tour.size() == 9){
        for(auto ele : tour)    cout << ele;
        cout << endl;
    }
}

int main(){ _
    init();
    euler_tour(1);
    return 0;
}
