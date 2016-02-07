//
//  uva11340.cpp
//
//
//  Created by 赵洋 on 15/9/22.
//
//

#include <stdio.h>
#include <map>
#include <iostream>
#include <string>

using namespace std;

int main(){
    int N, K, M;
    cin >> N;
    while(N--){
        double sum = 0.0;
        cin >> K;
        map<char, int> price;
        char ch;
        int p;
        for(int i = 0; i < K; ++i){
            cin >> ch >> p;
            price[ch] = p;
        }
        
        cin >> M;
        cin.ignore();
        string line;
        map<char, int>::iterator it;
        
        //        for(it = price.begin(); it != price.end(); ++it){
        //            cout << it->first << " " << it->second << endl;
        //        }
        
        
        for(int i = 0; i < M; ++i){
            getline(cin, line);
            
            for(int j = 0; j < line.size(); ++j){
                it = price.find(line[j]);
                if(it != price.end()){
                    sum += it->second;
                }
            }
        }
        
//        cout.precision(2);
//        cout << sum / 100.0 << "$" << endl;
        printf("%.2lf$\n", sum / 100);
    }
    return 0;
}