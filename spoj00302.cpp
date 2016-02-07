//
//  spoj00302.cpp
//  
//
//  Created by 赵洋 on 15/10/17.
//
//

#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, line, num, diff;
        cin >> N;
        line = floor(sqrt(2*N));
        if(line * (line+1) < 2 * N){
            line = line + 1;
        }
        
        diff = N - (line - 1) * line / 2;
        if(line % 2){
            num = line - diff + 1;
        } else {
            num = diff;
        }
        
        cout << "TERM " << N << " IS " << num << "/" << line + 1 - num << endl;
    }
    return 0;
}
