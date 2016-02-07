//
//  uva11093.cpp
//  
//
//  Created by 赵洋 on 15/9/22.
//
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int T, N;
    cin >> T;
    for(int j = 1; j <= T; ++j){
        cin >> N;
        vector<int> pi(N, 0);
        vector<int> qi(N, 0);
        int p = 0, q = 0, pSum = 0, qSum = 0;
        vector<int> possible;
        for(int i = 0; i < N; ++i){
            cin >> p;
            pi[i] = p;
            pSum += p;
        }
        
//        cout << "pi: ";
//        for(int i = 0; i < N; ++i){
//            cout << pi[i] << " ";
//        }
        
        for(int i = 0; i < N; ++i){
            cin >> q;
            qi[i] = q;
            qSum += q;
            if(pi[i] >= qi[i]){
                possible.push_back(i);
            }
        }
        
//        cout << "qi: ";
//        for(int i = 0; i < N; ++i){
//            cout << qi[i] << " ";
//        }
        
        
//        cout << "pSum = " << pSum << endl;
//        cout << "qSum = " << qSum << endl;
        
        if(pSum < qSum){
            cout << "Case " << j << ": " << "Not possible" << endl;
            continue;
        } else {
            bool flag = true;
            int start;
            for(int k = 0; k < possible.size(); ++k){
                start = possible[k];
//                cout << "start = "<< start << endl;
                flag = true;
                int fuel = 0;
                for(int m = 0; m < N; ++m){
                    fuel = fuel + pi[(start + m)%N] - qi[(start + m)%N];
                    if(fuel < 0){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    cout << "Case " << j << ": Possible from station " << start + 1 << endl;
                    break;
                }
            }
            if(!flag){
                cout << "Case " << j << ": " << "Not possible" << endl;
            }
        }
    }
    return 0;
}