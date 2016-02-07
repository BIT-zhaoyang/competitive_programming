//
//  uva10038.cpp
//  
//
//  Created by 赵洋 on 15/9/22.
//
//

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main(){
    int n;
    while(cin >> n, !cin.eof()){
        bool *arr = new bool[n];
        memset(arr, false, n);
        int n1, n2;
        cin >> n1;
        for(int i = 1; i < n; ++i){
            cin >> n2;
            arr[abs(n1 - n2)] = true;
            n1 = n2;
        }
        
        bool flag = true;
        for(int i = 1; i < n; ++i){
            if(!arr[i]){
                flag = false;
            }
        }
        if(flag){
            cout << "Jolly" << endl;
        } else {
            cout << "Not jolly" << endl;
        }
        delete []arr;
    }
    return 0;
}