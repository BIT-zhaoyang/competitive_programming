#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

/* Hints:
    Let's start at origin[0][0]. At this porint, the coverd area is up to origin[r-1][c-1]. This area will only be fliped 0 time or 1 time. The reason is that if we flip this area 2 times, the result equals to flip 0 time. Similiar argument applies to flip 1 time.

    So when we at origin[0][0], we just pay attention to (0, 0). If this grid is 0, it means we don't have to flip the rectangle from (0, 0) to (r, c). If this grid is 1, we flip it. After processing (0, 0), we will never come back to this point again. Thus we can move to other points. Which point shall we go? Well, never come back to a point seems to be a good property since it simplifies our problem. Thus, we can go either (0, 1) or (1, 0). Let's say we go to (1, 0). Then, (1, 0) has the same property as (0, 0). Thus, we treat it in the same way as we treat (0, 0).

    Continue processing like this until we traverse all points from (0, 0) to (n-r+1, m-c+1). Then we compare if origin is the same as change. If they are the same, it means we can make it and we have our answer ready.

    How did I find this method? Well, visualize it!
*/

bool origin[101][101];
bool change[101][101];

int main(){ _
    int n, m, r, c;
    while(cin >> n >> m >> r >> c){
        if(n + m + r + c == 0)  break;
        memset(origin, false, sizeof origin);
        memset(change, false, sizeof change);

        char ch;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j){
                cin >> ch;
                origin[i][j] = (ch == '1');
            }

        int ans = 0;
        for(int i = 0; i+(r-1) < n; ++i){
            for(int j = 0; j+(c-1) < m; ++j){

                if(origin[i][j] != change[i][j]){   // change if not equal
                    for(int k = 0; k < r; ++k){
                        for(int l = 0; l < c; ++l){
                            change[i+k][j+l] = !change[i+k][j+l];
                        }
                    }
                    ++ans;
                }

            }
        }

        bool success = true;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(change[i][j] != origin[i][j]){
                    success = false;
                    break;
                }
            }
        }

        if(success) cout << ans << endl;
        else    cout << -1 << endl;
    }
    return 0;
}
