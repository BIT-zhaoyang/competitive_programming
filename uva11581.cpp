//
//  uva11581.cpp
//
//
//  Created by 赵洋 on 15/9/23.
//
//

#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

void foo(int (&table)[5][5]){
    int old[5][5];
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            old[i][j] = table[i][j];
        }
    }
    
    for(int i = 1; i <=3; ++i){
        for(int j = 1; j <= 3; ++j){
            table[i][j] = (old[i-1][j] + old[i+1][j] + old[i][j-1] + old[i][j+1]) % 2;
        }
    }
}

bool is_stable(int (&table)[5][5]){
    for(int i = 1; i <= 3; ++i){
        for(int j = 1; j <= 3; ++j){
            if(table[i][j] != 0){
                return false;
            }
        }
    }
    return true;
}
int main(){
    int table[5][5];
    memset(table, 0, 25*sizeof(int));
    int n, count, temp;
    cin >> n;
    while(n--){
        count = 0;
        for(int i = 1; i <= 3; ++i){
            cin >> temp;
            //            cout << temp;
            table[i][3] = temp % 10;
            temp /= 10;
            table[i][2] = temp % 10;
            temp /= 10;
            table[i][1] = temp % 10;
        }
        
        if(is_stable(table)){
            cout << "-1" << endl;
            continue;
        }
        
        foo(table);
        while(!is_stable(table)){
            count++;
            foo(table);
        }
        cout << count << endl;
    }
}