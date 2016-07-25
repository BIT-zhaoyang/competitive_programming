#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

set< vector<int> > forbiden;
queue< vector<int> > Q;
int dist[10][10][10][10];

void bfs(vector<int> a){
    Q.push(a);  dist[a[0]][a[1]][a[2]][a[3]] = 0;
    vector<int> b(4, 0);

    while(!Q.empty()){
        a = Q.front();    Q.pop();
        for(int i = 0; i < 4; ++i){
            b = a;
            b[i] = (a[i] + 1) % 10;
            if(forbiden.count(b))   continue;
            if(dist[b[0]][b[1]][b[2]][b[3]] == UNVISITED){
                dist[b[0]][b[1]][b[2]][b[3]] = dist[a[0]][a[1]][a[2]][a[3]] + 1;
                Q.push(b);
            }
        }

        for(int i = 0; i < 4; ++i){
            b = a;
            b[i] = (a[i] + 10 - 1) % 10;
            if(forbiden.count(b))   continue;
            if(dist[b[0]][b[1]][b[2]][b[3]] == UNVISITED){
                dist[b[0]][b[1]][b[2]][b[3]] = dist[a[0]][a[1]][a[2]][a[3]] + 1;
                Q.push(b);
            }
        }
    }
}

int main(){ _
    int tc; cin >> tc;
    while (tc--) {
        forbiden.clear();
        memset(dist, -1, sizeof dist);

        vector<int> a(4, 0), b(4, 0), f(4, 0);
        for(int i = 0; i < 4; ++i)  cin >> a[i];
        for(int i = 0; i < 4; ++i)  cin >> b[i];

        int nf; cin >> nf;
        for(int i = 0; i < nf; ++i){
            for(int j = 0; j < 4; ++j)  cin >> f[j];
            forbiden.insert(f);
        }

        bfs(a);

        cout << dist[b[0]][b[1]][b[2]][b[3]] << endl;
    }
    return 0;
}
