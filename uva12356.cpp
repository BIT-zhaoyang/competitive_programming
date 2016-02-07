//
//  uva12356.cpp
//  
//
//  Created by 赵洋 on 15/9/23.
//
//

#include <iostream>

using namespace std;

int main(){
    int S, B;
    while(cin >> S >> B, S && B){
        int *arr, *left, *right;
        arr = new int[S+1];
        left = new int[S+1];
        right = new int[S+1];
        
        for(int i = 0; i < S+1; ++i){
            left[i] = i - 1;
            right[i] = i+1;
        }
        
        int l, r;
        for(int i = 0; i < B; ++i){
            cin >> l >> r;
            
            if(left[l] > 0){
                right[left[l]] = right[r];
                cout << left[l] << " ";
            } else {
                cout << "* ";
            }
            if(right[r] < S + 1){
                left[right[r]] = left[l];
                cout << right[r] << endl;
            } else {
                cout << "*" << endl;
            }
        }
        cout << "-" << endl;
        delete []arr;
        delete []left;
        delete []right;
    }
    return 0;
}
