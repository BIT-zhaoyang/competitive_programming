//
//  42.cpp
//  
//
//  Created by 赵洋 on 15/9/5.
//
//

#include <iostream>
using namespace std;

int reverse(int a){
    int b = 0;
    while(a != 0){
        b = b * 10 + a % 10;
        a /= 10;
    }
    return b;
}



int main(){
    int nLoop;
    int a, b, sum;
    cin >> nLoop;
    for( ; nLoop > 0; --nLoop){
        cin >> a >> b;
        a = reverse(a);
        b = reverse(b);
        sum = reverse(a + b);
        cout << sum << endl;
    }
}