//
//  uva11034.cpp
//
//
//  Created by 赵洋 on 15/10/20.
//
//

#include <string>
#include <iostream>
#include <queue>

using namespace std;

int main(){
    int TEST;
    cin >> TEST;
    while(TEST--){
        int L, M;
        cin >> L >> M;
        L *= 100;

        // read input
        int length;
        string side;
        queue<int> Q[2];
        for(int i = 0; i < M; ++i){
            cin >> length >> side;
            if(side == "left"){
                Q[0].push(length);
            } else {
                Q[1].push(length);
            }
        }

        // start simulation
        bool actualSide = false;      // false: left    true: right
        int count = 0;                // how many times the ferry has to cross the river
        int space = L;
        while(!Q[0].empty() || !Q[1].empty()){
            // load car
            while(!Q[actualSide].empty() && Q[actualSide].front() <= space){
                space -= Q[actualSide].front();
                Q[actualSide].pop();
            }

            // cross the river
            actualSide = !actualSide;
            count++;

            // unload cars
            space = L;
        }

        cout << count << endl;
    }
    return 0;
}
