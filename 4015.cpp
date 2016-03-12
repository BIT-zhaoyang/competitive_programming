//
//  4015.cpp
//  
//
//  Created by 赵洋 on 15/9/5.
//
//

#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int n, k;
    
    // read input
    cin >> n;
    cin >> k;
    int* array = (int *)malloc(n * n * sizeof(int));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> array[i * n + j];
        }
    }
    
//    for(int i = 0; i < n - k + 1; ++i){
//        for(int j = 0; j < n - k + 1; ++j){
//            int* start = &array[i * n + j];
//            int minimum = array[i * n + j];
//            for(int a = 0; a < k; ++a){
//                for(int b = 0; b < k; ++b){
//                    minimum = min(start[a*n + b], minimum);
//                }
//            }
//            cout << minimum << " ";
//        }
//        cout << endl;
//    }
    
    int* mediate = (int*)malloc((n - k + 1) * n * sizeof(int));
    for(int i = 0; i < n-k+1; ++i){
        for(int j = 0; j < k; ++j){
            
        }
    }
    
    
    return 0;
}