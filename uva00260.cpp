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
#include <iomanip>
#include <queue>
#include <stack>
#include <tuple>

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

int N;
char game[200][200];
bool visited[200][200];


const int dr[] = {-1, -1, 0, 0, 1, 1};
const int dc[] = {-1, 0, -1, 1, 0, 1};

bool dfs(int row, int col){
    visited[row][col] = true;
    if(row == N-1)  return true;

    int nextRow, nextCol;
    bool black = false;
    for(int i = 0; i < sizeof(dr)/sizeof(int); ++i){
        nextRow = row + dr[i];
        nextCol = col + dc[i];

        if(nextRow < 0 || nextRow >= N
        || nextCol < 0 || nextCol >= N
        || visited[nextRow][nextCol]
        || game[nextRow][nextCol] == 'w')   continue;

        black |= dfs(nextRow, nextCol);
    }

    return black;
}

int main(){ _
    int count = 0;
    while(cin >> N){
        if(N == 0)  break;
        else    cout << ++count << " ";

        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                cin >> game[i][j];
            }
        }

        memset(visited, false, sizeof visited);

        bool black = false;
        for(int i = 0; i < N; ++i){
            if(!visited[0][i]) black |= dfs(0, i);
        }

        if(black)   cout << "B" << endl;
        else    cout << "W" << endl;
    }
    return 0;
}
