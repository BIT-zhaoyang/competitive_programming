//
//  uva10107.cpp
//  
//
//  Created by 赵洋 on 15/9/23.
//
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long d;
    int n = 0;
    vector<long> vl;
    while(cin >> d, !cin.eof()){
        vl.push_back(d);
        n = vl.size();
        if(n % 2 == 1){
            nth_element(vl.begin(), vl.begin() + n/2, vl.end());
            cout << vl[n/2] << endl;
        } else {
            nth_element(vl.begin(), vl.begin() + n/2, vl.end());
            long a = vl[n/2];
            nth_element(vl.begin(), vl.begin() + n/2 - 1, vl.end());
            long b = vl[n/2 - 1];
            cout << (a + b) / 2 << endl;
        }
    }
    return 0;
}