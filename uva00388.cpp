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

map<char, int> c2i;
vector<double> value;
vector<int> dist;
vector<char> source, planet;
vector<string> AdjList;
queue<char> Q;

void bfs(){
    for(int i = 0; i < source.size(); ++i){
        Q.push(source[i]);
        dist[c2i[source[i]]] = 0;
    }
    char p, q; int id1, id2;
    while(!Q.empty()){
        p = Q.front();  Q.pop();
        id1 = c2i[p];
        for(int i = 0; i < AdjList[id1].size(); ++i){
            q = AdjList[id1][i];
            if(q == '*')    continue;
            id2 = c2i[q];
            if(dist[id2] == UNVISITED){
                dist[id2] = dist[id1] + 1;
                Q.push(q);
            }
        }
    }
}

int main(){ _
    int n;  char ch;
    while(cin >> n){
        c2i.clear();
        source.clear();
        value.assign(n, 0);
        planet.assign(n, ' ');
        dist.assign(n, UNVISITED);
        AdjList.assign(n, "");
        for(int i = 0; i < n; ++i){
            cin >> planet[i] >> value[i] >> AdjList[i];
            c2i[ch] = i;
            for(int j = 0; j < AdjList[i].size(); ++j)
                if(AdjList[i][j] == '*')    source.push_back(ch);
        }

        bfs();

        double ans = 0.0;   int id = -1;
        for(int i = 0; i < n; ++i){
            value[i] = value[i] * pow(0.95, dist[i]);
            if(value[i] > ans){
                ans = value[i];
                id = i;
            }
        }

        cout << "Import from " << planet[id] << endl;
    }
    return 0;
}
