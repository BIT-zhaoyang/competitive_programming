//
//  uva11926.cpp
//  
//
//  Created by 赵洋 on 15/9/24.
//
//

#include <iostream>
#include <bitset>

#define N 1000000
using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m, n || m){
        bitset<N> bs;
        int s, e;
        bool flag = true;   // flag == true: NO CONFLICT
        for(int i = 0; i < n; ++i){
            cin >> s >> e;
            if(flag){
                for(int j = s; j < e; ++j){
                    if(bs.test(j)){
                        cout << "CONFLICT" << endl;
                        flag = false;
                        break;
                    }
                    bs.set(j);
                }
            }
        }
        
        int interval;
        for(int i = 0; i < m; ++i){
            cin >> s >> e >> interval;
            if(flag){
                for(int j = s; j < e; ++j){
                    if(flag){
                        for(int k = 0; j+k*interval < N; ++k){
                            if(bs.test(j+k*interval)){
                                cout << "CONFLICT" << endl;
                                flag = false;
                                break;
                            }
                            bs.set(j+k*interval);
                        }
                   } else {
                       break;
                   }
                }
            }
        }
        
       if(flag){
           cout << "NO CONFLICT" << endl;
       }
    }
    return 0;
}