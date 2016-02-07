//
//  spoj10239.cpp
//  
//
//  Created by 赵洋 on 15/10/17.
//
//

#include <iostream>
#include <vector>
#include <bitset>
#define size 1000001

using namespace std;

void process(){
    bitset<size> first;
    bitset<size> second;
    bitset<size> combine;
    
    int N, idx, max;
    max = -1;
    
    // read the first line
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> idx;
        first[idx] = true;
        if(idx > max)
            max = idx;
    }
//    cout << first[13] << endl;
//    cout << "finished reading first line" << endl;
//    cout << first << endl;
    
    // read the second line
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> idx;
        second[idx] = true;
        if(idx > max)
            max = idx;
    }
    
//    cout << "finished reading second line" << endl;
//    cout << second << endl;
    
    combine = first & second;
    
//    cout << combine << endl;
    if(combine.any()){
        cout << 0 << endl;
        return;
    }
    
    
    combine = first | second;
    int i = 1, j = 1;
    while(!combine[i])
        ++i;
    
    int dist, min = size;
    for(j = i+1; j <= max; ++j){
        while(!combine[j] && j<= max)
            ++j;
        if(j > max)
            break;
        dist = j - i;
        if(dist < min)
            min = dist;
        i = j;
    }
    cout << min << endl;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        process();
    }
    
    return 0;
}
