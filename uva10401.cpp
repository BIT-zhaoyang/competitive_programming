#include <bits/stdc++.h>
#define UNVISITED -1
#define BIGINT 1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

/* This is a very interesting problem! This problem is a variation of the classic 8-queen problem. Here, we can model this variation as a DAG. The vertex of the DAG contains two parameters: column and row. The edges in the DAG is (col, row) -> (col + 1, row + x) where |x| > 1 and |row + x| >= 0 && |row + x| < n.

In the classical 8-queen problem, DP is also available. The idea is similiar, we go column by column. But in the classical 8-queen problem, all columns before our current 'col' will makes an effect on the result. Thus, the edges of the 8-queen problem is much denser! An advanced technique of bitmask should be used to represent states. For more detail, see CP3, section 8.2.1.
*/


int main(){ _
    int64 n, pre, cur;
    string line;
    vector<int64> ways[2];
    while(cin >> line){
        pre = 0, cur = 1;
        n = line.size();
        if(line[0] == '?'){
            ways[pre].assign(n, 1);
        } else {
            ways[pre].assign(n, 0);
            if(line[0] >= '1' && line[0] <= '9')    ways[pre][line[0] - '1'] = 1;
            else    ways[pre][line[0] - 'A' + 9] = 1;
        }

        for(int64 col = 1; col < n; ++col){
            ways[cur].assign(n, 0);

            char ch = line[col];
            if(ch == '?'){
                for(int64 curRow = 0; curRow < n; ++curRow)
                    for(int64 preRow = 0; preRow < n; ++preRow)
                        if(abs(curRow - preRow) > 1)
                            ways[cur][curRow] += ways[pre][preRow];
            } else {
                int64 curRow;
                if(ch >= '1' && ch <= '9')  curRow = ch - '1';
                else    curRow = ch - 'A' + 9;

                for(int64 preRow = 0; preRow < n; ++preRow)
                    if(abs(curRow - preRow) > 1)
                        ways[cur][curRow] += ways[pre][preRow];
            }
            pre = 1 - pre, cur = 1 - cur;
        }

        int64 ans = 0;
        for(int row = 0; row < n; ++row)    ans += ways[pre][row];
        cout << ans << endl;
    }
    return 0;
}
