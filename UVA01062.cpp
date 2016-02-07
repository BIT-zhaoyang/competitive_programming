//
//  UVA01062.cpp
//  
//
//  Created by 赵洋 on 15/10/7.
//
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string str;
    int n = 0;
    while(cin >> str, str != "end"){
        n++;
        vector<bool> flag(26, false);
        int maximum = -1;
        for(int i = 0; i < str.length(); ++i){
            int idx = str[i] - 'A';
            if(idx > maximum){
                flag[idx] = true;
                maximum = idx;
            } else {
                for(int j = idx; j <= maximum; ++j){
                    if(flag[j] == true){
                        flag[j] = false;
                        flag[idx] = true;
                        if(j == maximum){
                            maximum = idx;
                        }
                        break;
                    }
                }
            }
        }
        
        int count = 0;
        for(int i = 0; i < 26; ++i){
            if(flag[i])
                count++;
        }
        
        cout << "Case " << n << ": " << count << endl;
    }
    
    return 0;
}
