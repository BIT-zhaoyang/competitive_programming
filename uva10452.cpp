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

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);

using namespace std;

void recurse(vector< vector<char> > &maze, vector<string> &ans, vector< vector<bool> > &visited, int row, int col, bool &found){
    if(found)   return;
    if(row < 0 || col < 0 || col >= maze[0].size())  return;
    if(visited[row][col])   return;
    if(maze[row][col] == '#'){
        found = true;
        for(int i = 0; i < ans.size()-1; ++i)
            cout << ans[i] << " ";
        cout << ans.back() << endl;
        return;
    }

    visited[row][col] = true;
    switch (maze[row][col]) {
        case 'I': case 'E': case 'H': case 'O': case 'V': case 'A': case '@':
        ans.push_back("left");
        recurse(maze, ans, visited, row, col-1, found);
        ans.pop_back();

        ans.push_back("right");
        recurse(maze, ans, visited, row, col+1, found);
        ans.pop_back();

        ans.push_back("forth");
        recurse(maze, ans, visited, row-1, col, found);
        ans.pop_back();
        break;
    }
    visited[row][col] = false;
}


int main(){ _
    int TC; cin >> TC;
    while(TC--){
        int m, n;   cin >> m >> n;
        int start;
        vector< vector<char> > maze(m, vector<char> (n,0));
        vector< vector<bool> > visited(m, vector<bool> (n,false));
        vector<string> ans;

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                cin >> maze[i][j];
                if(maze[i][j] == '@')   start = j;
            }
        }

        bool found = false;
        recurse(maze, ans, visited, m-1, start, found);
    }
    return 0;
}
