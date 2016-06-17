#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< pair<int, int> > vii;

struct Node{
    int d, pr, pc;
    bool onPath;

    Node(){
        d = -1, pr = -1, pc = -1, onPath = false;
    }
};

enum direction {W = 0, N, E, S};
int dc[] = {-1, 0, 1, 0};  // W, N, E, S
int dr[] = {0, -1, 0, 1};
vector< vector<Node> > dist;
vector< vector<int> > wall;

bool legal(int r, int c, direction direct){
    int nR = dist.size()-1, nC = dist[0].size()-1, newR, newC;
    newR = r + dr[direct];
    newC = c + dc[direct];

    if(newR == 0 || newR > nR || newC == 0 || newC > nC)    return false;   // out boundary
    if(dist[newR][newC].d != -1)    return false;   // already visited
    switch(direct){ // wall exists
        case N:
            if(wall[newR][newC] >= 2)   return false;
            break;  // this break is necessary! Because if the 'if' test is false, the function won't return and it will continue to execute from here! Thus, a break is necessay!
        case S:
            if(wall[r][c] >= 2) return false;
            break;
        case W:
            if(wall[newR][newC] == 1 || wall[newR][newC] == 3)  return false;
            break;
        case E:
            if(wall[r][c] == 1 || wall[r][c] == 3)  return false;
            break;
    }

    return true;
}

bool dfs(int r, int c, int d, int er, int ec){
    dist[r][c].d = d + 1;
    if(r == er && c == ec)  return true;

    int newR, newC;
    bool found = false;
    for(direction direct = W; direct <= S; direct = direction(direct + 1)){
        if(legal(r, c, direct)){
            newR = r + dr[direct];
            newC = c + dc[direct];
            dist[newR][newC].pr = r;
            dist[newR][newC].pc = c;
            found = dfs(newR, newC, d+1, er, ec);
            if(found)   return true;
        }
    }
    return false;
}

void print(int &count){
    cout << "Maze " << ++count << endl << endl;

    // print header
    for(int c = 1; c < dist[0].size(); ++c) cout << "+---";
    cout << "+" << endl;


    for(int r = 1; r < dist.size(); ++r){
        cout << "|";    // left boundary
        for(int c = 1; c < dist[0].size(); ++c){
            cout << setw(3) << right;
            if(dist[r][c].onPath)   cout << dist[r][c].d;
            else{
                if(dist[r][c].d != -1)   cout << "???";
                else    cout << "   ";
            }
            if(c+1 < dist[0].size()){
                if(wall[r][c] == 1 || wall[r][c] == 3)  cout << "|";
                else    cout << " ";
            }
        }
        cout << "|";    // right boundary
        cout << endl;

        // draw the walls between rows
        if(r+1 < dist.size()){
            cout << "+";
            for(int c = 1; c < dist[0].size(); ++c){
                if(wall[r][c] >= 2) cout << "---";
                else    cout << "   ";
                cout << "+";
            }
            cout << endl;
        }
    }

    // print tail
    for(int c = 1; c < dist[0].size(); ++c) cout << "+---";
    cout << "+" << endl << endl << endl;
}

void setPath(int r, int c){
    dist[r][c].onPath = true;
    if(dist[r][c].pr != -1 && dist[r][c].pc != -1)  setPath(dist[r][c].pr, dist[r][c].pc);
}

int main(){ _
    int nR, nC, sr, sc, er, ec, count = 0;
    while(cin >> nR >> nC){
        if(nR + nC  == 0) break;
        cin >> sr >> sc >> er >> ec;

        dist.assign(nR+1, vector<Node> (nC+1));
        wall.assign(nR+1, vi(nC+1));
        for(int i = 1; i <= nR; ++i)
            for(int j = 1; j <= nC; ++j)
                cin >> wall[i][j];

        int d = 0;
        bool success;
        success = dfs(sr, sc, d, er, ec);
        if(success) setPath(er, ec);

        print(count);
    }

    return 0;
}
