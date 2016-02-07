//
//  uva10920.cpp
//  
//
//  Created by 赵洋 on 15/9/23.
//
//

#include <stdio.h>
#include <iostream>
#include <utility>

using namespace std;

int adj_corner(double d, double *corner){
    for(int i = 0; i < n; ++i){
        if(d >= corner[i]){
            return i;
        }
    }
}

get_coord(int idx, int n, int sz, int &x, int &y, double d, double *corner){
    double diff = d - corner[idx];
    switch (idx) {
        case 0:
            x = (sz + 1) / 2 - (n - 1);
            y = (sz + 1) / 2 + (n - 1);
            y = y - diff;
            break;
            
        case 1:
            x = (sz + 1) / 2 - (n - 1);
            y = (sz + 1) / 2 - (n - 1);
            x = x + diff;
            break;

        case 2:
            x = (sz + 1) / 2 + (n - 1);
            y = (sz + 1) / 2 - (n - 1);
            y = y + diff;
            break;
            
        case 3:
            x = (sz + 1) / 2 + (n - 1);
            y = (sz + 1) / 2 + (n - 1);
            y = y - diff;
            break;
        default:
            break;
    }
}


int main(){
    double corner[4];
    int sz, n;
    double d;
    while(cin >> sz >> d, sz){
        for(int i = 1; i < (sz+1)/2; ++i){
            int n = 2*i - 1;
            corner[0] = n*n - 3*(i-1);
            corner[1] = n*n - 2*(i-1);
            corner[2] = n*n - (i-1);
            corner[3] = n*n;
            if(d < corner[0]){
                continue;
            } else {
                int idx = adj_corner(d, corner);    //idx of the smaller corner
                int x, y;   // coord of d
                get_coord(idx, n, sz, x, y, d, corner);
                cout << "Line = " << y << ", column = " << x << "." << endl;
                break;
            }
        }
    }
    
    
}