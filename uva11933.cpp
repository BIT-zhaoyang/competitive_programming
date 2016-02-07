//
//  uva11933.cpp
//  
//
//  Created by 赵洋 on 15/9/24.
//
//

#include <stdio.h>
#include <iostream>
#include <bitset>
#include <vector>

#define N 32

using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        bitset<N> bs(n);
        vector<int> vi;
        for(int i = 0; i < N; ++i){
            if(bs.test(i)){
                vi.push_back(i);
            }
        }
        
        bitset<N> a;
        bitset<N> b;
        for(int i = 0; i < vi.size(); i += 2){
            a.set(vi[i]);
            if(i + 1 < vi.size()){
                b.set(vi[i+1]);
            }
        }
        
        cout << a.to_ulong() << " " << b.to_ulong() << endl;
    }
    return 0;
}