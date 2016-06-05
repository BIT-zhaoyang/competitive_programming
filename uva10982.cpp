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

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

/* The number of troubles changed by moving a person is computed as: #troubles in class A - #troubles in class B. The first term is the number of troubles reduced by removing this person from A. The second term is the number of troubles increased by moving this person to class B. Move the one who has the largest value of the formula.

There will always be a solution. Think about this as a bipartite problem. We can always increase the number of edges cutted by at least 1 by moving a pair of nodes on the same side to different sides.

One last thing: Be confident about yourself, you can solve these problems!
*/

bool relation[101][101];
bool A[101], B[101];

int main(){ _
    int TC; cin >> TC;
    for(int tc = 1; tc <= TC; ++tc){
        cout << "Case #" << tc << ": ";
        memset(relation, false, sizeof relation);
        memset(A, true, sizeof A);
        memset(B, false, sizeof B);

        int n, m;   cin >> n >> m;
        for(int i = 0; i < m; ++i){
            int a, b;
            cin >> a >> b;
            relation[a][b] = true;
            relation[b][a] = true;
        }

        int totalReduce = 0;
        while(totalReduce * 2 < m){
            int maxReduce = 0, reduce = 0, choose = -1;
            for(int i = 1; i <= n; ++i){
                if(A[i] == false)   continue;   // if i has moved to class B, continue

                // count number of conflict of i in class A
                reduce = 0;
                for(int j = 1; j <= n; ++j){
                    // every existing relation contributes 1 to reduce since we are removing it
                    if(A[j] == true && relation[i][j] == true)  ++reduce;
                }

                // count number of conflict of i in class B if we move i to class B
                for(int j = 1; j <= n; ++j){
                    if(B[j] == true && relation[i][j] == true)  --reduce;
                }

                if(reduce > maxReduce){
                    maxReduce = reduce;
                    choose = i;
                }
            }

            // move the chosen one naughty little bastard
            A[choose] = false;
            B[choose] = true;
            totalReduce += maxReduce;
        }

        int nMove = 0;
        for(int i = 1; i <= n; ++i)
            if(B[i])    ++nMove;

        cout << nMove << endl;
        for(int i = 1; i <= n; ++i){
            if(B[i]){
                cout << i;
                --nMove;
                if(nMove)   cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
