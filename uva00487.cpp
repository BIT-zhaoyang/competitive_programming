#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define vi vector<int>
using namespace std;

/*  ==================== LESSON LEARNED =======================
    Don't post recording current answer to its call of next recursion! Because it may won't get into next recursion!
*/

const int dx[] = {0,0,1,-1,1,1,-1,-1};
const int dy[] = {1,-1,0,0,1,-1,1,-1};

struct comp{
    bool operator() (const string& lhs, const string& rhs)  const{
        if(lhs.size() != rhs.size())    return lhs.size() < rhs.size();
        else return lhs < rhs;
    }
};

int N;
set<string, comp> words;
vector< vector<char> > maze;
vector< vector<bool> > visited;

void findWords(string &str, int x, int y){
    str.push_back(maze[x][y]);
    visited[x][y] = true;

    if(str.size() >= 3) words.insert(str);

    int nextX, nextY;
    for(int i = 0; i < 8; ++i){
        nextX = x+dx[i], nextY = y + dy[i];
        if(nextX < 0 || nextX == N || nextY < 0 || nextY == N)  continue;
        if(!visited[nextX][nextY] && maze[nextX][nextY] > maze[x][y])
            findWords(str, nextX, nextY);
    }
    visited[x][y] = false;
    str.pop_back();
}

int main(){ _
    int TC; cin >> TC;
    for(int count = 0; count < TC; ++count){
        if(count)   cout << endl;

        cin >> N;
        maze.assign(N, vector<char> (N));
        visited.assign(N, vector<bool> (N, false));
        words.clear();

        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                cin >> maze[i][j];

        string str;

        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                findWords(str, i, j);

        for(set<string>::iterator it = words.begin(); it != words.end(); ++it)
            cout << *it << endl;
    }


    return 0;
}
