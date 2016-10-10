#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

/* I am always weak in high dimensional DP problems. This problem has 4 dimensions, which is the most complicated DP problem I have met. After I really programmed it, the logic seems to be clear now.

The state we used in this problem is x, y, p(peaks found at height k by current coord (x, y)), and m(last move). The logic is that, for every point (x, y), we have two choices to arrive here, go up from (x-1, y-1) or go down from (x-1, y+1). To judge if a peak occurs, then, it must be like (x-2,y) -> (x-1, y+1) -> (x, y). Namely, it must go up to (x-1, y+1) then go down to (x, y). Any other case is not available. So the recursive function is:

1.) If we arrive at (x, y) by going up, then no new peak will appear, we simply take the sum of number of pathes of arriving at (x, y), despite how it really arrived at (x, y)
table[x][y][p][up] += table[x-1][y-1][p][up] + table[x-1][y-1][p][down];
2.) If we arrive at (x, y) by going down, there are another two situations:
    2.1) If we arrive at (x-1, y+1) by going down, then we are continuing going down, no new peak appears, so
        table[x][y][p][down] += table[x-1][y+1][p][down];
    2.2) If we arrive at (x-1, y+1) by going up, then we arrive (x, y) by going down, then a new peak appears! However,
    if y+1 != k, it's not a peak with the specified height we want, then
        table[x][y][p][down] += table[x-1][y+1][p][up];
    if y+1 == k, a new peak at the specified height appears! Then
        table[x][y][p][down] += table[x-1][y+1][p-1][up];
        notice the p-1, which means before (x-1, y+1) there are p-1 peaks we want. Now (x-1, y+1) is a new peak we want. So before (x, y) there are p peaks now.

Base case:
Base case is table[0][0][0][up] and table[0][0][0][down]. These two states doesn't really make sense from physical aspect. It should be table[0][0][0] = 1, irrespect of 'up' and 'down'. Plus considering that table[1][1][0][up] = 1(if k != 1), it make sense to assign an abitrary one of the two to 1.

What are the lesson learned? I don't really know... Maybe we should just keep calm, and analyse the real recursive structure and each possible cases. Don't try to optmize the code early by using less "if-else" statements.
*/

int table[45][25][20][2];   // state: x, y, peaks found(p), last move(m)
                            // number of ways to find p peaks with height k at coord (x, y) while last move is m
int main(){ _
    int n, r, k;
    while(cin >> n >> r >> k){
        memset(table, 0, sizeof table);
        table[0][0][0][0] = 1;
        for(int x = 1; x <= n * 2; ++x){
            for(int y = 0; y <= n; ++y){
                for(int p = 0; p <= r; ++p){
                    // arrived at [x][y] by going up from [x-1][y-1]
                    if(y-1 >= 0)
                        table[x][y][p][1] += table[x-1][y-1][p][0] + table[x-1][y-1][p][1];

                    // arrived at [x][y] by going down from [x-1][y+1]
                    table[x][y][p][0] += table[x-1][y+1][p][0];
                    if(y+1 == k && p-1 >= 0)    // find a new peak
                        table[x][y][p][0] += table[x-1][y+1][p-1][1];
                    else if(y+1 != k)
                        table[x][y][p][0] += table[x-1][y+1][p][1];
                }
            }
        }

        cout << table[n<<1][0][r][0] << endl;
    }
    return 0;
}
