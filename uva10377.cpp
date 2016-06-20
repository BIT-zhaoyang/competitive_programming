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

// #define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

char maze[61][61];
const int dr[] = {-1, 0, 1, 0}; // N, E, S, W
const int dc[] = {0, 1, 0, -1};


int main(){
    int TC; cin >> TC;
    while(TC--){
        int nR, nC; cin >> nR >> nC;

        string str;
        cin.ignore();
        for(int i = 1; i <= nR; ++i){
            getline(cin, str);
            for(int j = 1; j <= nC; ++j){
                maze[i][j] = str[j-1];
            }
        }

        int r, c, nextR, nextC, dir = 0;    cin >> r >> c;
        char op;
        while(cin >> op){
            if(op == 'Q')   break;
            switch (op) {
                case 'R':   dir = (dir + 1) % 4;    break;
                case 'L':   dir = (dir + 3) % 4;    break;
                case 'F':
                    nextR = r + dr[dir];
                    nextC = c + dc[dir];
                    if(maze[nextR][nextC] == '*')   break;
                    else {
                        r = nextR;
                        c = nextC;
                        break;
                    }
            }
        }

        cout << r << " " << c << " ";
        switch (dir) {
            case 0: cout << "N" << endl;    break;
            case 1: cout << "E" << endl;    break;
            case 2: cout << "S" << endl;    break;
            case 3: cout << "W" << endl;    break;
        }

        if(TC)  cout << endl;
    }
    return 0;
}
