//
//  uva10684.cpp
//  
//
//  Created by 赵洋 on 15/11/6.
//
//

#include <iostream>

using namespace std;

int main(){
    int N;
    while(cin >> N, N != 0){
        int sum = 0, win = 0, num = 0;
        while(N--){
            cin >> num;
            sum += num;
            if(sum < 0){
                sum = 0;
            } else if(sum > win){
                win = sum;
            }
        }
        
        if(win == 0){
            cout << "Losing streak." << endl;
        } else {
            cout << "The maximum winning streak is " << win << "." << endl;
        }
    }
    return 0;
}
