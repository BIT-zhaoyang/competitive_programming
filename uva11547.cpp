//
//  uva11547.cpp
//  
//
//  Created by 赵洋 on 15/9/11.
//
//

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int t, n, result;
    cin >> t;
    while(t--){
        cin >> n;
        result = 315 * n + 36962;
        result /= 10;
        result %= 10;
        cout << abs(result) << endl;
    }
}
