#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define POS_INF 1 << 28
#define NEG_INF -1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int total;
map<char, int> char2int;
vector< vector< ii > > AdjList;

void read_input(string &line){
    char start = line[0], end = line.back();
    if(char2int.count(start) == 0){
        char2int[start] = AdjList.size();
        AdjList.push_back(vector< ii > (0));
    }
    if(char2int.count(end) == 0){
        char2int[end] = AdjList.size();
        AdjList.push_back(vector< ii > (0));
    }

    int u = char2int[start], v = char2int[end];
    AdjList[u].push_back(ii(v, line.size()));
    AdjList[v].push_back(ii(u, line.size()));

    total += line.size();
}

int dijkstra(int root, int target){
    int n = AdjList.size();
    vector<int> dist(n, POS_INF);
    priority_queue< ii, vector< ii >, greater<ii> > pq;
    pq.push(ii(0, root));

    while(pq.size()){
        int u, d1;
        tie(d1, u) = pq.top();
        pq.pop();
        if(d1 > dist[u])    continue;
        for(int i = 0; i < AdjList[u].size(); ++i){
            int v, d2;
            tie(v, d2) = AdjList[u][i];
            if(d1 + d2 < dist[v]){
                dist[v] = d1 + d2;
                pq.push(ii(dist[v], v));
            }
        }
    }
    return dist[target];
}

int process(){
    // find if there are odd nodes
    // if there is none, then the whole tour is a euler tour
    // we can just return the total length of all streets
    int odd1 = -1, odd2 = -1;
    for(int i = 0; i < AdjList.size(); ++i){
        if(AdjList[i].size() % 2){
            if(odd1 != -1)  odd2 = i;
            else    odd1 = i;
        }
    }
    // if there are, we should compute the shortest distance between them
    // and add them to the euler tour since we need to finish at the starting node
    if(odd1 != -1)  total += dijkstra(odd1, odd2);
    return total;
}

void init(){
    total = 0;
    AdjList.clear();
    char2int.clear();
}

int main(){ _
    string line;
    init();
    while(cin >> line){
        if(line == "deadend"){
            cout << process() << endl;
            init();
            continue;
        }
        read_input(line);
    }
    return 0;
}
