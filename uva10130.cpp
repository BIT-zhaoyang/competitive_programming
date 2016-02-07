//
//  uva10130.cpp
//  
//
//  Created by 赵洋 on 15/11/10.
//
//

#include <iostream>
#include <vector>

using namespace std;

int compute(int S, vector<int> &price, vector<int> &weight){
    int n = price.size();
    
    
}

int main(){
    int T;
    cin >> T;
    while(T--) {
        int N;
        vector<int> price(N, 0);
        vector<int> weight(N, 0);
        
        for(int i = 0; i < N; ++i){
            cin >> price[i] >> weight[i];
        }
        
        int nP;
        cin >> nP;
        vector<int> peopel(nP, 0);
        for(int i = 0; i < nP; ++i){
            cin >> peopel[i];
        }
        
        int value = 0;
        for(int i = 0; i < nP; ++i){
            value += compute(peopel[i], price, weight);
        }
        
        cout << value;
    }
    
    return 0;
}
