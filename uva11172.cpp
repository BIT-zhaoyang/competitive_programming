//
//  uva11172.cpp
//  
//
//  Created by 赵洋 on 15/9/11.
//
//

#include <iostream>
using namespace std;

int main(){
    int TC, x, y;
    cin >> TC;
    while(TC--){
        cin >> x >> y;
        if(x > y)
            cout << ">" << endl;
        else if(x < y)
            cout << "<" << endl;
        else
            cout << "=" << endl;
    }
    return 0;
}