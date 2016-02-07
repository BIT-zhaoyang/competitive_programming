//
//  uva11799.cpp
//  
//
//  Created by 赵洋 on 15/9/16.
//
//

//22:32
#include <iostream>

using namespace std;

int main(){
    int n_test, n_students;
    int speed, maximum;
    cin >> n_test;
    for(int i = 1; i <= n_test; ++i){
        cin >> n_students;
        maximum = 0;
        for(int j = 0; j < n_students; ++j){
            cin >> speed;
            if(speed > maximum){
                maximum = speed;
            }
        }
        cout << "Case " << i << ": " << maximum << endl;
    }
    return 0;
}
