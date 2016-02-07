//
//  uva10264.cpp
//  
//
//  Created by 赵洋 on 15/9/24.
//
//

#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int main(){
    int n;
    while(cin >> n, !cin.eof()){
        int nEdge = pow(2, n);
        int *corner = new int[nEdge];
        int *sum = new int[nEdge];
        memset(sum, 0, sizeof(int) * nEdge);
        for(int i = 0; i < nEdge; ++i){
            cin >> corner[i];
        }
        
        int neighbour;
        for(int i = 0; i < nEdge; ++i){
            for(int j = 0; j < n; ++j){
                neighbour = i ^ (1<<j);
                sum[i] += corner[neighbour];
            }
        }
        
        int maximum = -1;
        for(int i = 0; i < nEdge; ++i){
            for(int j = 0; j < n; ++j){
                neighbour = i ^ (1<<j);
                if(sum[i] + sum[neighbour] > maximum){
                    maximum = sum[i] + sum[neighbour];
                }
            }
        }
        
        cout << maximum << endl;
        delete []corner;
        delete []sum;
    }
    
    return 0;
}