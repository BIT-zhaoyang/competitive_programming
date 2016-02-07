//
//  uva00507.cpp
//  
//
//  Created by 赵洋 on 15/11/6.
//
//

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int T, count = 0;
    cin >> T;
    while(count < T){
        ++count;
        int nStops;
        cin >> nStops;
        vector<int> route(nStops-1);
        for(int i = 0; i < nStops - 1; ++i){
            cin >> route[i];
        }
        
        int result = 0, s = 0, sum = 0, start = 0, end = 0;
        for(int i = 0; i < nStops - 1; ++i){
            sum += route[i];
            if(sum < 0){
                s = i + 1;
                sum = 0;
            } else if(sum > result){
                end = i + 2;
                start = s + 1;
                result = sum;
            } else if(sum == result){
                if(i - s + 1 > end - start){
                    end = i + 2;
                    start = s + 1;
                }
                result = sum;
            }
        }
        
        if(start == end){
            cout << "Route " << count <<" has no nice parts" << endl;
        } else {
            cout << "The nicest part of route " << count <<" is between stops "
            << start << " and " << end << endl;
        }
    }
}
