#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int table[1024][1024];

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        memset(table, 0, 1024*1024*sizeof(int));

        int range;
        cin >> range;
        int n;
        cin >> n;
        int x, y, p;
        int maximum = -1;
        int ansX, ansY;
        while(n--){
            cin >> x >> y >> p;
            for(int i = max(0, x-range); i <= min(1023, x+range); ++i){
                for( int j = max(0, y-range); j <= min(1023, y+range); ++j){
                    table[i][j] += p;
                    if(table[i][j] > maximum){
                        maximum = table[i][j];
                        ansX = i; ansY = j;
                    }
                }
            }
        }
        cout << ansX << " " << ansY << " " << maximum << endl;
    }
    return 0;
}
