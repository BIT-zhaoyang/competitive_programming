//
//  uva10172.cpp
//
//
//  Created by 赵洋 on 15/10/16.
//
//

#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

bool is_finished(vector< queue<int> >& stations, stack<int>& carrier){
    for(int i = 0; i < stations.size(); ++i){
        if(!stations[i].empty())
            return false;
    }
    
    if(!carrier.empty()){
        return false;
    }
    
    return true;
}


int main(){
    int set;
    cin >> set;
    while(set--){
        // read inputs
        int N, S, Q;
        cin >> N >> S >> Q;
        vector< queue<int> > stations(N);
        for(int i = 0; i < N; ++i){
            int num, cargo;
            cin >> num;
            for(int j = 0; j < num; ++j){
                cin >> cargo;
                stations[i].push(cargo);
            }
        }
        
        // simulate process
        stack<int> carrier;
        int time = 0;
        int i = 0;  //idx
        while(!is_finished(stations, carrier)){
            // unload first
            int cargo;
            while(!carrier.empty()){
                cargo = carrier.top();
                if(cargo == (i+1)){
                    carrier.pop();
                    time += 1;
                } else if(stations[i].size() < Q){
                    carrier.pop();
                    time += 1;
                    stations[i].push(cargo);
                } else {
                    break;
                }
            }
            
            // load carrier next
            while(carrier.size() < S && stations[i].size() > 0){
                cargo = stations[i].front();
                stations[i].pop();
                carrier.push(cargo);
                time += 1;
            }
            
            // move to next station
            time += 2;
            i = (i+1) % N;
        }
        cout << time - 2 << endl;   // need to minus 2 here because we check whether
                                    // the procedure is finished after moved to next
                                    // station. This movement is unnecessary.
    }
}
