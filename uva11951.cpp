//
//  uva11951.cpp
//  
//
//  Created by 赵洋 on 15/11/7.
//
//

#include <iostream>
#include <vector>

using namespace std;
int K, nplot, price;

void max_sum(vector<int> &col, int left, int right){
//    cout << "col is: " << endl;
//    for(int i = 0; i < col.size(); ++i){
//        cout << col[i] << endl;
//    }
//    
//    cout << endl;
    int factor = right - left + 1;
    
    for(int i = 0; i < col.size(); ++i){
        int count = 0, sum = 0;
        for(int j = i; j < col.size(); ++j){
            sum += col[j];
            count += factor;
            if(count > nplot && sum <= K){
                nplot = count;
                price = sum;
            } else if(count == nplot && sum < price){
                price = sum;
            } else if(sum > K){
                break;
            }
        }
    }
}

int main(){
    int T;
    cin >> T;
    for(int i = 1; i <= T; ++i){
        int N, M;
        cin >> N >> M >> K;
        vector< vector<int> > table(N, vector<int> (M, 0));
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < M; ++j){
                cin >> table[i][j];
            }
        }
        
        for(int i = 0; i < N; ++i){
            for(int j = 1; j < M; ++j){
                table[i][j] += table[i][j-1];
            }
        }
        
//        for(int i = 0; i < N; ++i){
//            for(int j = 0; j < M; ++j){
//                cout << table[i][j] << "\t";
//            }
//            cout << endl;
//        }
        
        nplot = 0, price = 0;
        for(int left = 0; left < M; ++left){
            for(int right = left; right < M; ++right){
                vector<int> col(N, 0);
                for(int i = 0; i < N; ++i){
                    if(left == 0){
                        col[i] = table[i][right];
                    } else {
                        col[i] = table[i][right] - table[i][left - 1];
                    }
                }
                max_sum(col, left, right);
            }
        }
        cout << "Case #" << i << ": " << nplot << " " << price << endl;
    }
    
    return 0;
}
