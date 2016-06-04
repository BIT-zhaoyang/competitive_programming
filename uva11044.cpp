//
//  uva11044.cpp
//
//  Created by 赵洋 on 15/9/11.
//
//

#include <iostream>
using namespace std;

int main(){
    int nTC, x, y;
    cin >> nTC;
    while(nTC--){
        cin >> x >> y;
        x /= 3;
        y /= 3;
        cout << x * y << endl;
    }
    return 0;
}
