//
//  uva10827.cpp
//  
//
//  Created by 赵洋 on 15/11/7.
//
//

#include <iostream>
#include <vector>

using namespace std;

int max_sum(vector<int>& vi){
    int result = -100 * 75 * 75, sum = 0;
    for(int i = 0; i < vi.size(); ++i){
        sum = 0;
        for(int j = i; j < i + vi.size(); ++j){
            sum += vi[j%vi.size()];
            result = max(result, sum);
            if(sum < 0){
                sum = 0;
            }
        }
    }
    
    return result;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector< vector<int> > grid(n, vector<int> (2*n, 0));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cin >> grid[i][j];
                grid[i][j+n] = grid[i][j];
            }
        }
        
        for(int i = 0; i < n; ++i){
            for(int j = 1; j < 2*n; ++j){
                grid[i][j] += grid[i][j-1];
            }
        }
        
        int result = -100 * 75 * 75;
        for(int left = 0; left < n; ++left){
            for(int right = left; right < left + n; ++right){
                vector<int> col(n, 0);
                for(int i = 0; i < n; ++i){
                    if(left == 0){
                        col[i] = grid[i][right];
                    } else {
                        col[i] = grid[i][right] - grid[i][left - 1];
                    }
                }
            
                result = max(result, max_sum(col));
            }
        }
        
        cout << result << endl;
    }
    return 0;
}
