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
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);

using namespace std;

int dr[] = {0, 0,  0, -1, 1};
int dc[] = {0, 1, -1,  0, 0};

int main(){ _
    bitset<10000> row, col;
    int R, C, N, ro, co, count = 0;
    while(true){
        cin >> R >> C >> N;
        if(R == 0 && C == 0 && N ==0)   break;
        ++count;
        row.reset(),    col.reset();

        for(int i = 0; i < N; ++i){
            cin >> ro >> co;
            row[ro] = true;
            col[co] = true;
        }

        cin >> ro >> co;
        bool escape = false;
        int _ro, _co;
        for(int i = 0; i < 5; ++i){
            _ro = ro + dr[i];
            _ro = max(0, _ro);
            _ro = min(R-1, _ro);

            _co = co+dc[i];
            _co = max(0, _co);
            _co = min(C-1, _co);

            if(row[_ro] == false && col[_co] == false){
                escape = true;
                break;
            }
        }

        if(escape){
            cout << "Case " << count << ": Escaped again! More 2D grid problems!" << endl;
        } else {
            cout << "Case " << count << ": Party time! Let's find a restaurant!" << endl;
        }
    }
    return 0;
}
