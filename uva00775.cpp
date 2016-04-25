#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define vi vector<int>
using namespace std;

int N, s, d;
string str;
vector< vector<int> > graph;
vector<bool> visited;
bool found;

void dfs(vector<int> &path){
    if(found)   return;

    if(path.size() == N){
        int lastNode = path.back(), neib;
        for(int i = 0; i < graph[lastNode].size(); ++i){
            neib = graph[lastNode][i];
            if(neib == path.front()){
                found = true;
                break;
            }
        }
        if(found){
            for(int idx = 0; idx < N; ++idx)    cout << path[idx] << " ";
            cout << path.front() << endl;
        }
        return;
    }

    int lastNode = path.back(), neib;
    for(int i = 0; i < graph[lastNode].size(); ++i){
        neib = graph[lastNode][i];
        if(!visited[neib]){
            path.push_back(neib);
            visited[neib] = true;
            dfs(path);
            path.pop_back();
            visited[neib] = false;
        }
    }
}


int main(){ _
    while(cin >> N){
        cin.ignore();
        graph.assign(N+1, vector<int> (0));
        visited.assign(N+1, false);
        found = false;
        while(getline(cin, str)){
            if(str[0] == '%')   break;

            stringstream ss;
            ss << str;
            ss >> s >> d;
            graph[s].push_back(d);
            graph[d].push_back(s);
        }

        vector<int> path;
        path.push_back(1);  visited[1] = true;
        dfs(path);
        if(!found)  cout << "N" << endl;
    }
    return 0;
}
