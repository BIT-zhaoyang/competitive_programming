#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

vector<int> dist, choices;
queue<int> Q;

void bfs(int p){
    Q.push(p);
    dist[p] = 0;

    int q;
    while(!Q.empty()){
        p = Q.front();
        Q.pop();
        for(int i = 0; i < choices.size(); ++i){
            q = p + choices[i];
            q %= 10000;
            if(dist[q] == UNVISITED){
                dist[q] = dist[p] + 1;
                Q.push(q);
            }
        }
    }
}

int main(){ _
    int L, U, R, tc = 0;
    while(cin >> L >> U >> R){
        if(L == 0 && U == 0 && R == 0)  break;
        dist.assign(10000, UNVISITED);
        choices.assign(R, 0);
        for(int i = 0; i < R; ++i)  cin >> choices[i];

        bfs(L);
        cout << "Case " << ++tc << ": ";
        if(dist[U] == UNVISITED)    cout << "Permanently Locked" << endl;
        else    cout << dist[U] << endl;
    }
    return 0;
}
