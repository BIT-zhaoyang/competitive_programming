#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

/* Colors given in the order: (front, back), (left, right), (top, bottom)
   Index system: each cube has 6 faces, each face has an index. We turn the index from 2D to 1D. So each cube occupies the index from 6i to 6i + 5.
   So, if n cubes are given, there will be 6n vertices in total.
*/

vector< vector<int> > cubes;
vector< vector<int> > AdjList;
vector<int> dist, parent;
stack<int> si;
vector<string> faces;

void topoSort(int u){
    dist[u] = 1;
    for(int i = 0; i < AdjList[u].size(); ++i){
        int v = AdjList[u][i];
        if(dist[v] == UNVISITED)
            topoSort(v);
    }
    si.push(u);
}

void print(int v){
    int cube = v / 6 + 1, // I indexed the cubes from 0, but the problem indexed from 1
        face = v % 6;
    if(parent[v] == -1){
        cout << cube << " " << faces[face] << endl;
    } else {
        print(parent[v]);
        cout << cube << " " << faces[face] << endl;
    }
}

int main(){ _
    faces.push_back("front");   faces.push_back("back");
    faces.push_back("left");   faces.push_back("right");
    faces.push_back("top");   faces.push_back("bottom");

    int n, tc = 0;
    while(cin >> n){
        if(n == 0)  break;
        // store cube information first
        cubes.assign(n, vector<int> (6, 0));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < 6; ++j)
                cin >> cubes[i][j];

        AdjList.assign(6 * n, vector<int> (0));
        for(int i = 0; i < n; ++i)
            for(int j = i + 1; j < n; ++j)
                for(int k = 0; k < 6; ++k)
                    for(int l = 0; l < 6; ++l){
                        int face1 = cubes[i][k], face2;
                        if(k % 2) face2 = cubes[i][k-1];
                        else    face2 = cubes[i][k+1];

                        int face3 = cubes[j][l];
                        if(face2 == face3)
                            AdjList[i*6 + k].push_back(j*6 + l);
                    }

        // topo sort
        dist.assign(6 * n, UNVISITED);
        for(int i = 0; i < 6 * n; ++i)
            if(dist[i] == UNVISITED)
                topoSort(i);

        // update information according to topoSort
        int highest = 0, index = -1;
        parent.assign(6 * n, UNVISITED);
        while(!si.empty()){
            int u = si.top();   si.pop();
            if(dist[u] > highest){
                highest = dist[u];
                index = u;
            }

            for(int i = 0; i < AdjList[u].size(); ++i){
                int v = AdjList[u][i];
                if(dist[u] + 1 > dist[v]){
                    dist[v] = dist[u] + 1;
                    parent[v] = u;
                }
            }
        }

        // print result
        if(tc)  cout << endl;
        cout << "Case #" << ++tc << endl;
        cout << highest << endl;
        print(index);
    }
    return 0;
}
