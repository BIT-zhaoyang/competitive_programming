#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <climits>
#include <cmath>
#include <set>
#include <bitset>
#include <sstream>

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);

using namespace std;

class UnionFind{
private:
    vector<int> p, r;
public:
    UnionFind(int n){
        r.assign(n, 0);
        p.assign(n, 0);
        for(int i = 0; i < n; ++i)  p[i] = i;
    }

    int findSet(int n){
        return (p[n] == n) ? n : (p[n] = findSet(n));
    }

    bool isSameSet(int a, int b){
        return findSet(a) == findSet(b);
    }

    void unionSet(int a, int b){
        if(isSameSet(a, b)) return;

        int x = findSet(a), y = findSet(b);
        if(r[x] < r[y]){
            p[x] = y;
        } else {
            p[y] = x;
            if(r[x] == r[y])    ++r[x];
        }
    }
};

int main(){ _
    int N, M;
    while(cin >> N, !cin.eof()){

    cin >> M;
    // UnionFind brains(N);
    set<char> active;
    set<char> nodes;
    string line;
    cin >> line;
    // brains.unionSet(line[0]-'A', line[1]-'A');
    // brains.unionSet(line[0]-'A', line[2]-'A');
    active.insert(line[0]);
    active.insert(line[1]);
    active.insert(line[2]);
    nodes.insert(line[0]);
    nodes.insert(line[1]);
    nodes.insert(line[2]);

    char start, end;
    string edges;
    map<char, vector<char> > graph;
    for(int i = 0; i < M; ++i){
        cin >> edges;
        start = edges[0];
        end = edges[1];

        graph[start].push_back(end);
        graph[end].push_back(start);
        nodes.insert(start);
        nodes.insert(end);
    }

    int lastSize = 0, year = 0;
    while(active.size() != lastSize && active.size() != N){
        lastSize = active.size();
        vector<char> willWake;
        for(set<char>::iterator it = nodes.begin(); it != nodes.end(); ++it){
            char ch = *it;
            int count = 0;
            if(active.count(ch))   continue;
            for(int i = 0; i < graph[ch].size(); ++i){
                char connect = graph[ch][i];
                if(active.count(connect))   ++count;
            }

            if(count >= 3)  willWake.push_back(ch);
        }
        for(int i = 0; i < willWake.size(); ++i)
            active.insert(willWake[i]);

        ++year;
    }

    if(active.size() != N)  cout << "THIS BRAIN NEVER WAKES UP" << endl;
    else cout << "WAKE UP IN, "<< year << ", YEARS" << endl;

}
    return 0;
}
