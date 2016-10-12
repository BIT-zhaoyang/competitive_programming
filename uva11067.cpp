#include <bits/stdc++.h>
#define UNVISITED -1
#define BIGINT 1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

const int maxN = 110;
vector< vector<int64> > ways;
vector< vector<bool> > wolf;

int main(){ _
    int w, h;
    while(cin >> w >> h){
        if(w == 0)  break;
        ways.assign(maxN, vector<int64> (maxN, 0));
        wolf.assign(maxN, vector<bool> (maxN, false));

        int nWolf;  cin >> nWolf;
        for(int i = 0; i < nWolf; ++i){
            int x, y;   cin >> x >> y;
            wolf[x][y] = true;
        }

        ways[0][0] = 1LL;
        for(int x = 0; x <= w; ++x){
            for(int y = 0; y <= h; ++y){
                if(wolf[x][y])  continue;
                if(x - 1 >= 0) ways[x][y] += ways[x-1][y];
                if(y - 1 >= 0) ways[x][y] += ways[x][y-1];
            }
        }
        if(ways[w][h] == 0)
            cout << "There is no path." << endl;
        else if(ways[w][h] == 1)
            cout << "There is one path from Little Red Riding Hood's house to her grandmother's house." << endl;
        else
            cout << "There are " << ways[w][h]
                 << " paths from Little Red Riding Hood's house to her grandmother's house."
                 << endl;
    }
    return 0;
}
