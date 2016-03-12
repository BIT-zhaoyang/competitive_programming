//
//  11364.cpp
//  
//
//  Created by 赵洋 on 15/9/11.
//
//

#include <iostream>
using namespace std;

int main(){
    int TC, n, min, max, temp;
    cin >> TC;
    while(TC--){
        cin >> n;
        min = 100, max = -1;
        while(n--){
            cin >> temp;
            if(temp < min){
                min = temp;
            }
            if(temp > max){
                max = temp;
            }
        }
        cout << (max - min) * 2 << endl;
    }
    return 0;
}
