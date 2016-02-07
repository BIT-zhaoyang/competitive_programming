//
//  uva11498.cpp
//  
//
//  Created by 赵洋 on 15/9/11.
//
//
#include <iostream>

using namespace std;

int main(){
    int n, dx, dy, x, y;
    while(cin >> n, n){
        cin >> dx >> dy;
        for(int i = 0; i < n; ++i){
            cin >> x >> y;
            if(x == dx || y == dy){
                cout << "divisa" << endl;
            } else if(x < dx && y > dy){
                cout << "NO" << endl;
            } else if(x > dx && y > dy){
                cout << "NE" << endl;
            } else if(x < dx && y < dy){
                cout << "SO" << endl;
            } else if(x > dx && y < dy){
                cout << "SE" << endl;
            }
        }
    }
    return 0;
}
