#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    int k;
    while(cin >> k, !cin.eof()){
        int x, y, ky;
        vector<int> arrX, arrY;
        for(y = k+1; y <= k*2; ++y){
            ky = k*y;
            if(ky % (y-k) == 0){
                x = ky / (y-k);
                if(x >= y){
                    arrX.push_back(x);
                    arrY.push_back(y);
                }
            }
        }
        cout << arrX.size() << endl;
        for(int i = 0; i < arrX.size(); ++i){
            x = arrX[i]; y = arrY[i];
            cout << "1/" << k << " = 1/" << x << " + 1/" << y << endl;
        }
    }
    return 0;
}
