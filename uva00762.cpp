#include <algorithm>
#include <bitset>
#include <cstring>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <sstream>
#include <vector>

#define UNVISITED -1
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
map<string, int> s2i;
vector<string> cities;
vector< vector<int> > AdjList;
queue<int> Q;
vector<int> dist, parent;

void bfs(int source){
    Q.push(source); dist[source] = 0;
    int p, q;
    while(!Q.empty()){
        p = Q.front();  Q.pop();
        for(int i = 0; i < AdjList[p].size(); ++i){
            q = AdjList[p][i];
            if(dist[q] == UNVISITED){
                parent[q] = p;
                dist[q] = dist[p] + 1;
                Q.push(q);
            }
        }
    }
}

void print(int source, int node){
    if(parent[node] == source)  cout << cities[source] << " " << cities[node] << endl;
    else{
        print(source, parent[node]);
        cout << cities[parent[node]] << " " << cities[node] << endl;
    }
}

int main(){ _
    int n, nCity, tc = 0;  string str1, str2;  int id1, id2;
    while(cin >> n){
        if(tc++)  cout << endl;

        nCity = 0;
        s2i.clear();
        AdjList.clear();
        cities.clear();

        for(int i = 0; i < n; ++i){
            cin >> str1 >> str2;
            if(s2i.count(str1) == 0){
                s2i[str1] = nCity++;
                AdjList.push_back(vector<int> (0));
                cities.push_back(str1);
            }
            if(s2i.count(str2) == 0){
                s2i[str2] = nCity++;
                AdjList.push_back(vector<int> (0));
                cities.push_back(str2);
            }
            id1 = s2i[str1],    id2 = s2i[str2];
            AdjList[id1].push_back(id2);
            AdjList[id2].push_back(id1);
        }

        dist.assign(nCity, UNVISITED);
        parent.assign(nCity, UNVISITED);
        cin >> str1 >> str2;
        if(s2i.count(str1) == 0 || s2i.count(str2) == 0){
            cout << "No route" << endl;
            continue;
        }

        id1 = s2i[str1], id2 = s2i[str2];
        bfs(id1);

        if(dist[id2] == UNVISITED)  cout << "No route" << endl;
        else    print(id1, id2);
    }
    return 0;
}
