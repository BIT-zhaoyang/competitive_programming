#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int row[8], TC, a, b, lineCounter;  // row[i] = a -> the occupied row number at the i-th column is 'a'

bool place(int r, int c){
    for(int prev = 0; prev < c; ++prev){
        if(row[prev] == r || abs(r - row[prev]) == abs(c - prev)){
            return false;
        }
    }

    return true;
}

void backtrack(int c){
    if(c == 8 && row[b] == a){   // row[b] == a -> (a, b) has a quuen.
                                // row[b] is the height. a is the horizontal deviation.
        cout << ++lineCounter << "\t" << row[0]+1;
        for(int i = 1; i < 8; ++i){
            cout << " " << row[i]+1;
        }
        cout << endl;
        return;
    }

    for(int r = 0; r < 8; ++r){
        if(place(r, c)){
            row[c] = r; // put the queen on the r-th row for the c-th column
            backtrack(c + 1);   // proceed to next column
        }
    }
}

int main(){
    scanf("%d", &TC);
    while (TC--){
        scanf("%d %d", &a, &b); a--; b--;
        memset(row, 0, sizeof row);
        lineCounter = 0;
        printf("SOLN    COLUMN\n");
        printf("#\t1 2 3 4 5 6 7 8\n\n");
        backtrack(0);
        if(TC) printf("\n");
    }
    return 0;
}
