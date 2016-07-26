#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

/* It's better to write a more generalized condition in 'if' statement, especially when detecting memory boundaries. */

int m, n;
vector< ii > horses;
queue< ii > Q;
vector< vector<int> > dist;
vector< vector<char> > board;

const int hdr[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int hdc[] = {1, 2, 2, 1, -1, -2, -2, -1};
const int kdr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int kdc[] = {0, 1, 1, 1, 0, -1, -1, -1};

void setHorse(ii &coord){
    int r = coord.first, c = coord.second, nr, nc;
    for(int i = 0; i < sizeof(hdr) / sizeof(int); ++i){
        nr = r + hdr[i],    nc = c + hdc[i];
        if(nr < 0 || nr >= m || nc < 0 || nc >= n)  continue;
        board[nr][nc] = 'Z';
    }
}

void bfs(int r1, int c1){
    Q.push(ii(r1, c1));
    dist[r1][c1] = 0;

    int r2, c2;
    while(!Q.empty()){
        r1 = Q.front().first,   c1 = Q.front().second;
        Q.pop();
        for(int i = 0; i < sizeof(kdr) / sizeof(int); ++i){
            r2 = r1 + kdr[i],   c2 = c1 + kdc[i];
            if(r2 < 0 || r2 == m || c2 < 0 || c2 == n)  continue;
            if(board[r2][c2] == 'Z')    continue;
            if(dist[r2][c2] != UNVISITED)   continue;

            dist[r2][c2] = dist[r1][c1] + 1;
            Q.push(ii(r2, c2));
        }
    }
}

int main(){ _
    int tc; cin >> tc;
    while(tc--){
        cin >> m >> n;
        board.assign(m, vector<char> (n, '.'));
        dist.assign(m, vector<int> (n, -1));
        horses.clear();

        int ar, ac, br, bc; char ch;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                cin >> board[i][j];
                if(board[i][j] == 'Z')  horses.push_back(ii(i, j));
                if(board[i][j] == 'A')  {ar = i; ac = j;}
                if(board[i][j] == 'B')  {br = i; bc = j;}
            }
        }

        for(int i = 0; i < horses.size(); ++i)  setHorse(horses[i]);
        board[ar][ac] = 'A';
        board[br][bc] = 'B';

        bfs(ar, ac);
        if(dist[br][bc] == UNVISITED)   cout << "King Peter, you can't go now!" << endl;
        else    cout << "Minimal possible length of a trip is " << dist[br][bc] << endl;
    }
    return 0;
}
