//
//  uva11727.cpp
//  
//
//  Created by 赵洋 on 15/9/12.
//
//
//19:27
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, a[3], result, i = 1;
    cin >> n;
    while(n--){
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a+3);
        cout << "Case " << i++ << ": " << a[1] << endl;
    }
    return 0;
}
