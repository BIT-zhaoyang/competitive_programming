#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

map<string, int> s2i;
vector<string> words;
vector< vector<int> > AdjList;
vector<int> dist, parent;
queue<int> Q;

int diff(string &a, string &b){
    int ans = 0;
    for(int i = 0; i < a.size(); ++i){
        if(a[i] != b[i])    ++ans;
    }
    return ans;
}

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

void backtrack(int p){
    if(parent[p] != -1) backtrack(parent[p]);
    cout << words[p] << endl;
}

bool mysort(string &a, string &b){
    if(a.size() != b.size())    return a.size() < b.size();
    else    return a < b;
}

int main(){ _
    string line;
    // read input
    while(getline(cin, line)){
        if(line == "")  break;
        words.push_back(line);
    }

    sort(words.begin(), words.end(), mysort);
    for(int i = 0; i < words.size(); ++i)   s2i[words[i]] = i;

    // build graph
    int n = words.size();
    AdjList.assign(n, vector<int> (0));
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            if(words[i].size() != words[j].size())  break;

            if(diff(words[i], words[j]) == 1){
                AdjList[s2i[words[i]]].push_back(s2i[words[j]]);
                AdjList[s2i[words[j]]].push_back(s2i[words[i]]);
            }
        }
    }

    string start, end;
    int nq = 0;
    while(cin >> start >> end){
        if(nq++)    cout << endl;

        dist.assign(n, UNVISITED);
        parent.assign(n, UNVISITED);

        bfs(s2i[start]);

        if(dist[s2i[end]] != UNVISITED) backtrack(s2i[end]);
        else    cout << "No solution." << endl;
    }
    return 0;
}
