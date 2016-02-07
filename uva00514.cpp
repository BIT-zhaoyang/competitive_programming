//
//  uva00514.cpp
//  
//
//  Created by 赵洋 on 15/10/6.
//
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        int first;
        while(cin >> first, first){
            vector<int> vi(n, first);
            for(int i = 1; i < n; ++i){
                int coach;
                cin >> vi[i];
            }
            
            int count = 1;
            stack<int> station;
            bool flag = true;
            for(int i = 0; i < n; ++i){
                while(count <= vi[i]){
                    station.push(count++);
                }
                
                if(vi[i] != station.top()){
                    flag = false;
                    break;
                }
                
                station.pop();
            }
            cout << (flag ? "Yes" : "No") << endl;
        }
        cout << endl;
    }
}







