#include <bits/stdc++.h>
// #define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);

using namespace std;
int a, b, counter;
bitset<20> rw, ld, rd;
vector<int> row;

void backtrack(int c){
    if(c == 8){
        printf("%2d      %d", ++counter, row[0] + 1);
        for(int i = 1; i < 8; ++i)
            printf(" %d", row[i] + 1);
        cout << endl;
    } else {
        for(int r = 0; r < 8; ++r){
            if(c+1 == b && r+1 != a) continue;

            if(!rw[r] && !ld[r-c+7] && !rd[r+c]){
                rw[r] = true; ld[r-c+7] = true; rd[r+c] = true;
                row[c] = r;
                backtrack(c+1);
                rw[r] = ld[r-c+7] = rd[r+c] = false;
            }
        }
    }
}

int main(){
    int T; cin >> T;
    while(T--){
        cin >> a >> b;
        counter = 0;
        row.assign(8, 0);
        rw.reset(); ld.reset(); rd.reset();
        cout << "SOLN       COLUMN" << endl;
        cout << " #      1 2 3 4 5 6 7 8" << endl << endl;
        backtrack(0);
        if(T) cout << endl;
    }

    return 0;
}
