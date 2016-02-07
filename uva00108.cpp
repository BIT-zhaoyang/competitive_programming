//
//  uva00108.cpp
//  
//
//  Created by 赵洋 on 15/11/6.
//
//

#include <iostream>
#include <vector>

using namespace std;

int maxSum(vector<int> &vi){
    int opt = -127 * 100, sum = 0;
    for(int i = 0; i < vi.size(); ++i){
        sum += vi[i];
        if(sum < 0){
            sum = 0;
        } else if(sum > opt){
            opt = sum;
        }
    }
    return opt;
}



int maxSum(vector< vector <int> > table){
    int n = table.size();
    for(int i = 0; i < n; ++i){
        for(int j = 1; j < n; ++j){
            table[i][j] += table[i][j-1];
        }
    }
    
    int opt = -127 * 100 * 100;
    for(int left = 0; left < n; ++left){
        for(int right = left; right < n; ++right){
            vector<int> column(n);
            for(int i = 0; i < n; ++i){
                if(left > 0){
                    column[i] = table[i][right] - table[i][left - 1];
                } else {
                    column[i] = table[i][right];
                }
            }
            
            int result = maxSum(column);
            opt = max(result, opt);
        }
    }
    
    return opt;
}

int main(){
    int n;
    cin >> n;
    vector< vector<int> > table(n, vector<int> (n));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> table[i][j];
        }
    }
    
    int opt = maxSum(table);
    cout << opt << endl;
}