//
//  uva10901.cpp
//
//
//  Created by 赵洋 on 15/10/19.
//
//

#include <iostream>
#include <string>
#include <queue>
using namespace std;

#define MAXN 10000
int timeLeave[MAXN];
int timeArrive[MAXN];
queue<int> Q[2];

int main(){
    int c;
    cin >> c;
    while(c--){
        int n, t, m;
        cin >> n >> t >> m;
        
        // read arrive time of cars
        string side;
        int time;
        for(int i = 0; i < m; ++i){
            cin >> time >> side;
            if(side == "left"){
                Q[0].push(i);
            } else {
                Q[1].push(i);
            }
            timeArrive[i] = time;
        }
        
        // begin simulation
        bool actualSide = false;    // false: left      true: right
        int actualTime = 0;
        while(!Q[0].empty() || !Q[1].empty()){
            int next = Q[0].empty() ? timeArrive[Q[1].front()] :
                       Q[1].empty() ? timeArrive[Q[0].front()] :
                       min(timeArrive[Q[1].front()], timeArrive[Q[0].front()]);
            
            actualTime = max(actualTime, next);     // wait if no car is on shore
            
            // load cars
            int count = 0;  // this also serves as unload car from last loop
            while(!Q[actualSide].empty() && timeArrive[Q[actualSide].front()] <= actualTime && count < n){
                timeLeave[Q[actualSide].front()] = actualTime;
                Q[actualSide].pop();
                count++;
            }
            
            // cross the river
            actualTime += t;
            actualSide = !actualSide;
        }
        
        for(int i = 0; i < m; ++i){
            cout << timeLeave[i] + t << endl;
        }
        
        if(c) cout << endl;
    }
    
    return 0;
}